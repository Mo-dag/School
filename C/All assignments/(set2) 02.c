/*
 *  Calculate factorial using while loops
 *
 * Samples:
 * - while_stmt.c
 */
#include<stdio.h>
#include<stdbool.h>


int main() {
    int number;
    // TODO declare the variable "factorial" with a suitable type
    long long factorial = 1;
    printf("Enter an integer (less than 20) > ");
    scanf("%d", &number);
    // TODO. Do it once then add while (loop) around
    while(1){
        if(number>1){
            factorial *= number;
            number--;
        }
        else{break;}
    }
    // TODO print the size of the variable "factorial"
    printf("Size of the variable factorial is : %zu\n" , sizeof(factorial));
    printf("Factorial = %lld\n", factorial);

    return 0;
}
