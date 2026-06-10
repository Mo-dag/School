#include <stdio.h>

int main()
{
    float pi;       // Declaration of a float
    pi = 3.1415;    // Assigment
	float r;        // Declaration of a second float
    
    printf("Input the circle's radius: ");
    scanf("%f", &r);
    
    float l = 2.0 * r * pi;
    
    // Output with standard formatting
    printf("The circumference is %f\n", l);
    
    // You can specify how you want the value to be printed
    // Play around with the numbers to figure out how this works!
    printf("\nThe same with different formatting:\n---\n");
    printf("The circumference is %.3f\n", l);
    printf("The circumference is %8.2f\n", l);
    printf("The circumference is %08.2f\n", l);
    
    // For integers it works similarly, you can for example select %8d or %08d
}
