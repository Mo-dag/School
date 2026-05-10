#ifndef _APP_H
#define _APP_H

#include "TinyTimber.h"

typedef struct {
  Object super;
} App;

typedef struct {
  Object super;
  char buf[20];
  int buf_index;
  char input_mode;   /* 'k' = key input, 'p' = tempo input */
} InputHandler;

typedef struct {
  Object super;
  int volume;
  int previous_volume;
  int muted;
  int signal_high;
  int sound_enabled;
  int period_us;
} ToneGenerator;

typedef struct {
  Object super;
  int current_note;
  int key;
  int tempo;
  int gap_ms;
} MusicPlayer;

#define initApp()          { initObject() }
#define initInputHandler() { initObject(), {0}, 0, 0 }
#define initTone()         { initObject(), 5, 5, 0, 0, 0, 1136 }
#define initPlayer()       { initObject(), 0, 0, 120, 25 }

void reader(InputHandler *, int);
void receiver(App *, int);
void startApp(App *, int);

void tone_task(ToneGenerator *, int);
void set_period(ToneGenerator *, int);
void sound_on(ToneGenerator *, int);
void sound_off(ToneGenerator *, int);
void volume_up(ToneGenerator *, int);
void volume_down(ToneGenerator *, int);
void toggle_mute(ToneGenerator *, int);

void play_note(MusicPlayer *, int);
void end_note(MusicPlayer *, int);
void set_key(MusicPlayer *, int);
void set_tempo(MusicPlayer *, int);

#endif