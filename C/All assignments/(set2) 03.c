/*
 *   Solving a quadratic equation
 *   https://en.wikipedia.org/wiki/Quadratic_formula
 *   https://www.mathsisfun.com/quadratic-equation-solver.html
 *
 *
 *   See:
 *   - math.c
 */
#include<stdio.h>
#include<math.h>


int main() {

    printf("Program to solve a quadratic equation: ");
    printf("ax^2 + bx + c = 0\n");
    
    double a;
    double b;
    double c;
    double x1;
    double x2; 
    double x;
    printf("Please input a > ");
    scanf("%lf", &a);
    printf("Please input b > ");
    scanf("%lf", &b);
    printf("Please input c > ");
    scanf("%lf", &c);

    double discriminant;

    // TODO
    if(a==0){printf("It is not a quadratic ekvation !!");return 0;}

    discriminant = (b*b - (4*a*c));

    if( discriminant > 0){
        printf("There are two distinct real roots ");
        x1 = (-b+sqrt(discriminant))/(2*a);
        x2 = (-b-sqrt(discriminant))/(2*a);
        printf("x1 = %f, x2 = %f\n", x1, x2);
    } else if( discriminant < 0 ){
        printf("There are two complex conjugate roots. Can't solve will give nan\n");
    } else {
        printf("There are two equal real roots ");
        x = (-b)/(2*a);
        printf("x = %lf", x);
    }

    //printf("x1 = %f, x2 = %f\n", x1, x2);
    return 0;
}
