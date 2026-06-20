#include <stdio.h>
#include <math.h>

#define PI 3.1415926

float get_radius();
float circle_circumference(float x);
float circle_area(float x);


int main() {
    
    printf("Program to calculate the area and circumference of a circle\n");
    
    float radius;
    float area;
    float circ;
    
    // ----- Input ----------------
    
    radius = get_radius();
    // -------- Process -----------

    area= circle_area(radius);
    circ = circle_circumference(radius);
    // ----- Output ----------------

    printf("The circumference of the circle is : %.2f \n", circ);
    printf("The area of the circle is : %.2f \n", area);
    
	return 0;
}
float get_radius(){
    float radius; 
    printf("Input the radius of the circle: ");
    scanf("%f", &radius);

    return radius;
}


float circle_circumference(float radius){
    float circ;
    circ = 2*PI*radius;
    return circ;
}

float circle_area(float radius){
    float area;
    area = PI*pow(radius,2);
    return area;
}

