#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO implement function 'five_dice' that simulates the throw of five dice 
//  using pointers in the function. The function should not return any value.
void five_dice(int *d1,int *d2,int *d3,int *d4,int *d5);
int main() {
    
    // TODO Initialise the random number generator
    srand((unsigned int) time(NULL));
    int d1=0, d2=0, d3=0, d4=0, d5=0;

    // print the values of the five dice before calling the function
    printf("Dice at beginning: %d %d %d %d %d\n", d1, d2, d3, d4, d5);
    
    // TODO call 'five_dice' to simulate the throw of five dice
    five_dice(&d1,&d2,&d3,&d4,&d5);
    // print the values of the five dice again after calling the function
    printf("Dice after calling function: %d %d %d %d %d\n", d1, d2, d3, d4, d5);
    
    return 0;
}

    void five_dice(int *d1, int *d2,int *d3,int *d4,int *d5){
        *d1 = rand()%6+1;
        *d2 = rand()%6+1;
        *d3 = rand()%6+1;
        *d4 = rand()%6+1;
        *d5 = rand()%6+1;
    }
