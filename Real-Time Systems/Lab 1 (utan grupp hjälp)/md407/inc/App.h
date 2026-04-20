#ifndef _APP_H
#define _APP_H

#include "TinyTimber.h"

typedef struct {
  Object super;
  int example;
  char buffer[20];    // För att lagra inmatade siffror. 
  int history [20]; // för att lagra de 3 sista siffror. 
  int index; // för : buffer
  int cnt;   // för : history
} App;

#define initApp()                                                              \
  { initObject(), 0,{0},{0},0,0}

void reader(App *, int);
void receiver(App *, int);
void startApp(App *, int);

#endif
