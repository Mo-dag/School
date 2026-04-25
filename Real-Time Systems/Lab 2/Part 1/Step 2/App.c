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
// DAC är en converter , Digital to Analog. 
// Vi fick uppgift att skapa en Tone Generator. Vi fick oskså adress till DAC som : 0x4000741C.
// Jag skulle definera den. 
// Optimera inte den "Tar bort inte den !". 

#define DAC_DATA ((volatile unsigned char *)0x4000741C)
// DAC_DATA är ansvarig för ljud styrka.

int mini_index = -10;     // Jag skrev de här bara för att visa de , annars skulle de befinna sig i Labb papper !
int max_index = 14;       // Jag skrev de här bara för att visa de , annars skulle de befinna sig i Labb papper !
static int volume = 1;
static int state =0;
int melody[32] = {0,2,4,0,0,2,4,0,4,5,7,4,5,7,7,9,7,5,4,0,7,9,7,5,4,0,0,-5,0,0,-5,0};


void Tone_generator(App *self, int unused){   // Tiny timber kräver denna form !


  if( state < 1){
    *DAC_DATA = volume;
    state = 1;
  }
  else{*DAC_DATA = 0;
  state = 0;}
  
  AFTER(USEC(931),self, Tone_generator,0);  // 500 >> 1 kHz för att : 1 kHz =1000, 500µs för 0 + 500µs för 1 = en period 
  
}
void empty_loop(App *self, int unused){

  for(volatile int i = 0; i<self->background_loop_range;i++);  // Volatile för att inte optimeras bort.
                                                               // Compilor kan tar bort den. 
  AFTER(USEC(1300),self, empty_loop, 0);

}


int period[25] = {
  2024, 1911, 1803, 1702, 1607,
  1516, 1431, 1351, 1275, 1203,
  1136, 1072, 1012, 955, 901,
  851, 803, 758, 715, 675,
  637, 601, 568, 536, 506
};

void period_lookup(App *self, int *melody, int *period){
  int key = self->history[self->cnt-1];
  

  char write[10];
  sprintf(write, "Key: %i\n", key);
  SCI_WRITE(&sci0, write);
  for(int i=0; i<32;i++){
    int index = melody[i]+key;
    index = index - (-10); 
    char skriv[20];
    sprintf(skriv, "%i ", period[index]);
    SCI_WRITE(&sci0, skriv);
  }
  SCI_WRITE(&sci0, "\n");
   

}
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
  if(self->buffer[0]== '-'){
    volume --;
    if(volume <1){volume =1;}
  }
  else if(self->buffer[0]=='+'){
    volume ++;
    if(volume > 5){volume = 5;}
  }
  else if(self->buffer[0]=='m'){
    if(volume == 0){
      volume = 1;
    }
    else{volume = 0;}
  }
  else if(self->buffer[0] == 'i'){
    if(self->background_loop_range <= 8000){
      self->background_loop_range +=500;
    }
  }
  else if(self->buffer[0] == 'k'){
    if(self->background_loop_range >=1500){
      self->background_loop_range -=500;
    }
  }
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
  period_lookup(self, melody, period);

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
  Tone_generator(self, 0);
  empty_loop(self,0);

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
