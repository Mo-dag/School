#include "App.h"
#include "TinyTimber.h"
#include "canTinyTimber.h"
#include "sciTinyTimber.h"
#include <stdio.h>
#include <stdlib.h>

extern App app;
extern Can can0;
extern Serial sci0;

static void add_to_history(App *self, int num) {
  if (self->count < 3) {
    self->history[self->count] = num;
    self->count++;
  } else {
    self->history[0] = self->history[1];
    self->history[1] = self->history[2];
    self->history[2] = num;
  }
}

static int sum_history(App *self) {
  int sum = 0;
  for (int i = 0; i < self->count; i++) {
    sum += self->history[i];
  }
  return sum;
}

static int median_history(App *self) {
  if (self->count == 1) {
    return self->history[0];
  }

  if (self->count == 2) {
    return (self->history[0] + self->history[1]) / 2;
  }

  int a = self->history[0];
  int b = self->history[1];
  int c = self->history[2];

  if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
  if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
  return c;
}

void receiver(App *self, int unused) {
  CANMsg msg;
  CAN_RECEIVE(&can0, &msg);
  SCI_WRITE(&sci0, "Can msg received: ");
  SCI_WRITE(&sci0, msg.buff);
}

void reader(App *self, int c) {
  char out[100];

  SCI_WRITE(&sci0, "Rcv: \'");
  SCI_WRITECHAR(&sci0, c);
  SCI_WRITE(&sci0, "\'\n");

  if (c == 'F' || c == 'f') {
    self->count = 0;
    self->buf_index = 0;
    self->buf[0] = '\0';
    SCI_WRITE(&sci0, "The 3-history has been erased\n");
    return;
  }

  if (c == 'e') {
    int num, sum, median;

    if (self->buf_index == 0) {
      return;
    }

    self->buf[self->buf_index] = '\0';
    num = atoi(self->buf);

    add_to_history(self, num);
    sum = sum_history(self);
    median = median_history(self);

    snprintf(out, sizeof(out),
             "Entered integer %d: sum = %d, median = %d\n",
             num, sum, median);
    SCI_WRITE(&sci0, out);

    self->buf_index = 0;
    self->buf[0] = '\0';
    return;
  }

  if (self->buf_index < 19) {
    self->buf[self->buf_index] = (char)c;
    self->buf_index++;
  }
}

void startApp(App *self, int arg) {
  CANMsg msg;

  CAN_INIT(&can0);
  SCI_INIT(&sci0);
  SCI_WRITE(&sci0, "Hello, hello...\n");

  self->buf_index = 0;
  self->count = 0;
  self->buf[0] = '\0';

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

int main() {
  INSTALL(&sci0, sci_interrupt, SCI_IRQ0);
  INSTALL(&can0, can_interrupt, CAN_IRQ0);
  TINYTIMBER(&app, startApp, 0);
  return 0;
}