#include <stdio.h>
#include <math.h>

double factorial(int n);


double sin_x(double x, int n);



int main(){

    int n = 0;
    double x = 2.0;
    double our_sin_x = sin_x(x,n);
    double math_sin = sin(x);


    printf("sin(x) by series: %f\n", our_sin_x);
    printf("Test \n");
    printf("Difference to std. function: %f", (our_sin_x - math_sin));

    return 0;
}


double factorial(int n){

    double sum = 1;
    for(int i = 1; i<= n ; i++){
        sum *= i;
    }
    return sum;
}

double sin_x(double x, int n){ 
    double sinus_x; 
    double sum=0;
    while(1){
        sinus_x = (pow(-1,n)*pow(x,2*n+1))/factorial(2*n+1);
        sum += sinus_x;
        if(fabs(sinus_x) < 0.001){    
            return sum;
        }
        n++;
    }
    }                       
    
        
