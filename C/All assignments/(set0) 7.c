#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Please insert a\n");
    scanf("%i", &a);
    printf("Please insert b\n");
    scanf("%i", &b);
    // Add code to read in values for a and b


    if (a > b) {   
        printf("a is larger than b\n");
    }
    if (a >= b) {
        printf("a is greater than or equal to b\n");
    }
    if (a < b) {
        printf("a is smaller than b\n");
    }
    if (a <= b) {
        printf("a is smaller than or equal to b\n");
    }
    if (a == b) {
        printf("a is equal to b\n");
    }
    if (a != b) {
        printf("a is not equal to b\n");
    }
    return 0;
}


/*
  Please note that there is no difference between placing the starting { like this:
    if (a > b ) {
   
  or like this:
    if (a > b ) 
    {

*/
