/*
 *  Sum 1 - n introducing the for-loop
 *
 *  Samples:
 *  - for_stmt.c
 */
#include<stdio.h>


int main() {
    int sum = 0;
    int n;

    printf("Program to sum 1-n\n");
    printf("Input n : ");
    scanf("%d", &n);

    // TODO
    if(n>0){
        for(int i = 0; i<n+1;i++){
            sum += i;
        }
    }
    printf("Sum 1 to %d = %d\n", n, sum);

    return 0;
}
