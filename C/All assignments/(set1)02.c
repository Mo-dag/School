#include <stdio.h>

int main() {
    
    printf("Program to calculate the area of a rectangle\n");

    float width;
    float height;
    float area;

    // ----- Input ----------------

    // TODO
    printf("Please insert the width\n");
    scanf("%f", &width);
    printf("Please insert the height\n");
    scanf("%f", &height);
    // -------- Process -----------
    area =  width * height;

    // TODO

    // ----- Output ----------------

    printf("The area of the rectangle is : %.5f \n", area);
    
	return 0;
}
