#include <stdio.h>

int main() {
	
    int number;
    int rightmost_digit;
    int count_digits=0;
    
    // ---- Input ---------
    // TODO
    printf("Input an integer number : ");
    scanf("%d", &number);
    rightmost_digit = number %10;
    while(number>0){
        number /=10;
        count_digits ++;
    }
    // ------ Process --------
    // TODO
    
    // ----- Output ------------
    printf("Rightmost digit is %d\n", rightmost_digit);
    printf("Number of digits is %d\n", count_digits);
    
	return 0;
}
