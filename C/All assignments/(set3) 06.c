#include <stdio.h>

// TODO Function to shift values of 3 integers forwards using pointers
void shift_forward(int *x,int *y, int *z);
// TODO Function to shift values of 3 integers backwards using pointers
void shift_backward(int *x,int *y,int *z);
int main() {
    
    int num1 = 3;
    int num2 = 11;
    int num3 = 23;

    printf("Before shift:\n");
    printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);

    // Call shift_forward to shift the values of num1, num2, num3 forward
    shift_forward(&num1, &num2, &num3);

    printf("After forward shift:\n");
    printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);
    
    // Call shift_backward to shift the values of num1, num2, num3 back again
    shift_backward(&num1, &num2, &num3);	// TODO uncomment to call shift_backward
    
    // TODO use shift_forward instead to get same result as with shift_backward

    printf("After backward shift:\n");
    printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);

    return 0;
}

void shift_forward(int *x,int *y,int *z){
    int holder = *x;
    *x=*y;
    *y=*z;
    *z=holder;
}
void shift_backward(int *x,int *y,int *z){
    int holder = *x;
    *x=*z;
    *z=*y;
    *y=holder;
}
