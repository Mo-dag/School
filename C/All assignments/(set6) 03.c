#include <stdio.h>
#include <math.h>





double calculate_pi(double limit);

int main() {
    
    double pi;
    double limit = 0.001;
    
    pi = calculate_pi(limit);
    
    printf("PI approximated to %lf\n", pi);
    
    return 0;
}


// TODO implement the function 'calculate_pi' here



double calculate_pi(double limit){
    double term =1;
    double sum=0;
    double x=1;
    double sign=1;

    while(fabs(term)>=limit){
        term = sign/x;
        sum += term;
        sign = -sign;
        x+=2;
    }
    return 4*sum;
}
