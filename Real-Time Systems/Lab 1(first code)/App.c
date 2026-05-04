#include "App.h"
#include "TinyTimber.h"
#include "canTinyTimber.h"
#include "sciTinyTimber.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
extern App app;
extern Can can0;
extern Serial sci0;









int sum(App *self){
  int a = self->history[0];
  int b = self->history[1];
  int c = self->history[2];

  if(self->cnt == 1){
    return a;
  }
  else if(self->cnt == 2){
    return a+b;
  }
  else {
    return a+b+c;
  }

}




int median(App *self){
  int a = self->history[0];
  int b = self->history[1];
  int c = self->history[2];

  if(self->cnt == 1){
    return a;
  }
  else if(self->cnt ==2){
    return (a+b)/2;
  }
  else{
    if((a<b && b<c) || (c<b && b<a)) return b;
    if((b<c && c<a) || (a<c && c<b)) return c;
    else{return a;}
  }
}






void receiver(App *self, int unused) {
  CANMsg msg;
  CAN_RECEIVE(&can0, &msg);
  SCI_WRITE(&sci0, "Can msg received: ");
  SCI_WRITE(&sci0, msg.buff);

}


void F(App *self){

  memset(self->history, 0, sizeof(self->history));

  self->cnt =0;

  SCI_WRITE(&sci0, "The 3-history has been erased\n");

}

void E(App *self){


  self->buffer[self->index] = '\0'; 
  self->history[self->cnt] = atoi(self->buffer);

  int entered_int = self->history[self->cnt];
  self->cnt ++;

  int Sum = sum(self);
  int Median = median(self);

  self->index = 0;


  // Jag kan inte skriva ut på skärmen utan att anävnda : SCI_WRITE.
  // Since den tar inte mer än två arguments, skulle jag använda sprintf som 
  // Omvandlar en TEXT med VARIABLES till en char-array.
  char write [100];
  sprintf(write, "Entered integer %d: sum = %d, median = %d \n", entered_int, Sum,Median);

  SCI_WRITE(&sci0, write);

}



void reader(App *self, int c) {
  SCI_WRITE(&sci0, "Rcv: \'");
  SCI_WRITECHAR(&sci0, c);
  SCI_WRITE(&sci0, "\'\n");

  if(tolower(c)!='e' && tolower(c)!='f'){
    self->buffer[self->index] = c;
    self->index++;
  }
  else if(tolower(c)=='e'){
    E(self);
  }
  else if(tolower(c)=='f'){
    F(self);
  }
  };









void startApp(App *self, int arg) {
  CANMsg msg;

  CAN_INIT(&can0);
  SCI_INIT(&sci0);
  SCI_WRITE(&sci0, "Hello, hello...\n");

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
