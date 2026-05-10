#include "App.h"
#include "TinyTimber.h"
#include "canTinyTimber.h"
#include "sciTinyTimber.h"
#include <stdio.h>
#include <stdlib.h>

#define DAC_DATA ((volatile unsigned char *)0x4000741C)

#define MIN_VOLUME 1
#define MAX_VOLUME 20

#define MIN_KEY (-5)
#define MAX_KEY 5

#define MIN_TEMPO 60
#define MAX_TEMPO 240

#define MIN_INDEX (-10)

extern App app;
extern Can can0;
extern Serial sci0;
extern InputHandler input;

ToneGenerator tone = initTone();
MusicPlayer player = initPlayer();

/* ---------------- Melody data from Part 0 ---------------- */

int melody[32] = {
    0, 2, 4, 0, 0, 2, 4, 0,
    4, 5, 7, 4, 5, 7, 7, 9,
    7, 5, 4, 0, 7, 9, 7, 5,
    4, 0, 0, -5, 0, 0, -5, 0};

/*
 * Frequency indices -10 to 14.
 * Array index is x(k) = k + 10.
 */
int period[25] = {
    2024, 1911, 1803, 1702, 1607,
    1516, 1431, 1351, 1275, 1203,
    1136, 1072, 1012, 955, 901,
    851, 803, 758, 715, 675,
    637, 601, 568, 536, 506};

/*
 * Note lengths:
 * 1 = half beat
 * 2 = one beat
 * 4 = two beats
 */
int note_length[32] = {
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 4, 2, 2, 4, 1, 1,
    1, 1, 2, 2, 1, 1, 1, 1,
    2, 2, 2, 2, 4, 2, 2, 4};

/* ---------------- CAN receiver ---------------- */

void receiver(App *self, int unused)
{
  CANMsg msg;
  CAN_RECEIVE(&can0, &msg);
  SCI_WRITE(&sci0, "Can msg received: ");
  SCI_WRITE(&sci0, msg.buff);
}

/* ---------------- Tone generator ---------------- */

void tone_task(ToneGenerator *self, int unused)
{
  if (!self->sound_enabled || self->muted)
  {
    *DAC_DATA = 0;
  }
  else
  {
    if (self->signal_high)
    {
      *DAC_DATA = self->volume;
    }
    else
    {
      *DAC_DATA = 0;
    }

    self->signal_high = !self->signal_high;
  }

  AFTER(USEC(self->period_us), self, tone_task, 0);
}

void set_period(ToneGenerator *self, int period_us)
{
  self->period_us = period_us;
}

void sound_on(ToneGenerator *self, int unused)
{
  self->sound_enabled = 1;
}

void sound_off(ToneGenerator *self, int unused)
{
  self->sound_enabled = 0;
  *DAC_DATA = 0;
}

void volume_up(ToneGenerator *self, int unused)
{
  char out[64];

  if (!self->muted && self->volume < MAX_VOLUME)
  {
    self->volume++;
    self->previous_volume = self->volume;
  }

  snprintf(out, sizeof(out), "Volume: %d\n", self->volume);
  SCI_WRITE(&sci0, out);
}

void volume_down(ToneGenerator *self, int unused)
{
  char out[64];

  if (!self->muted && self->volume > MIN_VOLUME)
  {
    self->volume--;
    self->previous_volume = self->volume;
  }

  snprintf(out, sizeof(out), "Volume: %d\n", self->volume);
  SCI_WRITE(&sci0, out);
}

void toggle_mute(ToneGenerator *self, int unused)
{
  if (self->muted)
  {
    self->muted = 0;
    self->volume = self->previous_volume;
    SCI_WRITE(&sci0, "Sound enabled\n");
  }
  else
  {
    self->muted = 1;
    self->previous_volume = self->volume;
    *DAC_DATA = 0;
    SCI_WRITE(&sci0, "Sound muted\n");
  }
}

/* ---------------- Music player ---------------- */

void play_note(MusicPlayer *self, int unused)
{
  int frequency_index;
  int period_index;
  int beat_ms;
  int note_duration_ms;
  int sound_time_ms;
  char out[96];

  frequency_index = melody[self->current_note] + self->key;
  period_index = frequency_index - MIN_INDEX; /* same as frequency_index + 10 */

  beat_ms = 60000 / self->tempo;
  note_duration_ms = (beat_ms * note_length[self->current_note]) / 2;

  sound_time_ms = note_duration_ms - self->gap_ms;
  if (sound_time_ms < 1)
  {
    sound_time_ms = note_duration_ms;
  }

  snprintf(out, sizeof(out),
           "Note %d, key %d, tempo %d, period %d us\n",
           self->current_note,
           self->key,
           self->tempo,
           period[period_index]);
  SCI_WRITE(&sci0, out);

  ASYNC(&tone, set_period, period[period_index]);
  ASYNC(&tone, sound_on, 0);

  AFTER(MSEC(sound_time_ms), self, end_note, 0);
}

void end_note(MusicPlayer *self, int unused)
{
  ASYNC(&tone, sound_off, 0);

  self->current_note = (self->current_note + 1) % 32;

  AFTER(MSEC(self->gap_ms), self, play_note, 0);
}

void set_key(MusicPlayer *self, int key)
{
  char out[64];

  if (key < MIN_KEY || key > MAX_KEY)
  {
    SCI_WRITE(&sci0, "Key out of range. Use -5 to 5.\n");
    return;
  }

  self->key = key;

  snprintf(out, sizeof(out), "Key set to %d\n", self->key);
  SCI_WRITE(&sci0, out);
}

void set_tempo(MusicPlayer *self, int tempo)
{
  char out[64];

  if (tempo < MIN_TEMPO || tempo > MAX_TEMPO)
  {
    SCI_WRITE(&sci0, "Tempo out of range. Use 60 to 240 bpm.\n");
    return;
  }

  self->tempo = tempo;

  snprintf(out, sizeof(out), "Tempo set to %d bpm\n", self->tempo);
  SCI_WRITE(&sci0, out);
}

/* ---------------- Keyboard input ---------------- */

void reader(InputHandler *self, int c)
{
  SCI_WRITE(&sci0, "Rcv: '");
  SCI_WRITECHAR(&sci0, c);
  SCI_WRITE(&sci0, "'\n");

  switch (c)
  {
  case 'u':
    ASYNC(&tone, volume_up, 0);
    break;

  case 'd':
    ASYNC(&tone, volume_down, 0);
    break;

  case 'm':
    ASYNC(&tone, toggle_mute, 0);
    break;

  case 'k':
    self->input_mode = 'k';
    self->buf_index = 0;
    self->buf[0] = '\0';
    SCI_WRITE(&sci0, "Enter key, finish with e\n");
    break;

  case 'p':
    self->input_mode = 'p';
    self->buf_index = 0;
    self->buf[0] = '\0';
    SCI_WRITE(&sci0, "Enter tempo, finish with e\n");
    break;

  case 'e':
  {
    int value;

    if (self->buf_index == 0)
    {
      SCI_WRITE(&sci0, "No integer entered\n");
      break;
    }

    self->buf[self->buf_index] = '\0';
    value = atoi(self->buf);

    if (self->input_mode == 'k')
    {
      ASYNC(&player, set_key, value);
    }
    else if (self->input_mode == 'p')
    {
      ASYNC(&player, set_tempo, value);
    }
    else
    {
      SCI_WRITE(&sci0, "No input mode selected. Use k or p first.\n");
    }

    self->buf_index = 0;
    self->buf[0] = '\0';
    self->input_mode = 0;
    break;
  }

  default:
    if (self->input_mode == 'k' || self->input_mode == 'p')
    {
      if (self->buf_index < 19)
      {
        self->buf[self->buf_index] = (char)c;
        self->buf_index++;
      }
      else
      {
        SCI_WRITE(&sci0, "Input too long\n");
        self->buf_index = 0;
        self->buf[0] = '\0';
      }
    }
    break;
  }
}

/* ---------------- Startup ---------------- */

void startApp(App *self, int arg)
{
  CANMsg msg;

  CAN_INIT(&can0);
  SCI_INIT(&sci0);
  SCI_WRITE(&sci0, "Hello, hello...\n");
  SCI_WRITE(&sci0, "Brother John player starting...\n");

  *DAC_DATA = 0;

  ASYNC(&tone, tone_task, 0);
  ASYNC(&player, play_note, 0);

  msg.msgId = 1;
  msg.nodeId = 1;
  msg.length = 6;
  msg.buff[0] = 'H';
  msg.buff[1] = 'e';
  msg.buff[2] = 'l';
  msg.buff[3] = 'l';
  msg.buff[4] = 'o';
  msg.buff[5] = 0;

  CAN_SEND(&can0, &msg);
}

int main()
{
  INSTALL(&sci0, sci_interrupt, SCI_IRQ0);
  INSTALL(&can0, can_interrupt, CAN_IRQ0);
  TINYTIMBER(&app, startApp, 0);

  return 0;
}