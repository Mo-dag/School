#ifndef _APP_H
#define _APP_H

#include "TinyTimber.h"

typedef struct {
  Object super;
  int example;
  char buf[20];
  int buf_index;
  int history[3];
  int count;
} App;

#define initApp() \
  { initObject(), 1234, {0}, 0, {0,0,0}, 0 }

void reader(App *, int);
void receiver(App *, int);
void startApp(App *, int);

#endif