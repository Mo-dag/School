/*
 *    Loop puzzlers, exercising nested while loops
 *
 *    Will print "patterns"
 *
 *   See:
 *   - puzzlers.c
 *
 */
#include<stdio.h>


int main() {

    // Plot the first pattern
    // TODO
    int x=7;
    int y=0;
    int counter =0;
    while(x>0){
        while(y<=counter){
            printf("X");
            y++;
        }
        y=0;
        x--;
        counter++;
        printf("\n");
    }
    printf("\n");    // Layout

    // Plot the second pattern
    // TODO
    int z=0;
    int i=0;
    int k=0;
    while(z<4){
        while(i<k){
            printf(" ");
            i++;
        }
        i=0;
        while(y<10){
            printf("X");
            y++;
        }
        printf("\n");
        y=0;
        z++;
        k++;
    }

    return 0;
}
