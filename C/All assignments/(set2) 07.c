/*
 *  A first exercise involving functions.
 *  Macros for testing are also introduced.
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Test macros
// CHECK_IF_EQUAL will print ok if V1 and V2 are equal
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
// CHECK_IF_EPS_EQUAL will print ok if difference of V1 and V2 is less than 0.0001
#define CHECK_IF_EPS_EQUAL(V1, V2) fabs((V1) - (V2)) < 0.0001 ? printf("ok\n") : printf("not ok\n")

#define PI 3.1415926

// ------------- Function declarations -------------

// The square function
int square(int i);

// The average of 3 floats.
float avg(float i, float j, float k);

// This is the same as ex_rectangle in set1. Just make a function out of it
float rectangle(float width, float height);

// This is about the same as ex_convertangle in set1.
float deg_to_rad(float deg);

// Absolute value
int absolute(int i);

// This is the same as ex_factorial.
long long factorial(int n);

// The power function for positive int's only
int pow_int(int base, int exp);

// Count how many digits there are in a number
int n_digits(int number);

// The sum of the digits in some number
int digit_sum(int number);

/*
 *  Just testing the functions not a meaningful program
 */
int main() {

    // TODO This should print ok
    CHECK_IF_EQUAL(square(4), 16);
    CHECK_IF_EQUAL(square(-2), 4);

    // TODO Uncomment one at a time, all should print ok
    CHECK_IF_EPS_EQUAL(avg(1.0, 1.0, 1.0), 1.0);   // Average is 1.0
    CHECK_IF_EPS_EQUAL(avg(1.5, 2.0, 4.0), 2.5);
    

    CHECK_IF_EPS_EQUAL(rectangle(4.0, 5.0), 20.0);
    CHECK_IF_EPS_EQUAL(rectangle(33.3, 3.0), 99.9);

    CHECK_IF_EPS_EQUAL(deg_to_rad(0), 0);
    CHECK_IF_EPS_EQUAL(deg_to_rad(90), 1.5708);

    CHECK_IF_EQUAL(absolute(12), 12);      // Absolute of 12 is 12
    CHECK_IF_EQUAL(absolute(0), 0);
    CHECK_IF_EQUAL(absolute(-4), 4);

    CHECK_IF_EQUAL(factorial(1), 1);
    CHECK_IF_EQUAL(factorial(3), 6);
    CHECK_IF_EQUAL(factorial(15), 1307674368000);  // Need long long for result!

    CHECK_IF_EQUAL(pow_int(2, 4), 16);
    CHECK_IF_EQUAL(pow_int(1, 23), 1);
    CHECK_IF_EQUAL(pow_int(4, 0), 1);
    
    CHECK_IF_EQUAL(n_digits(123), 3);   // 123 has 3 digits
    CHECK_IF_EQUAL(n_digits(12345), 5);
    CHECK_IF_EQUAL(n_digits(1023945), 7);

    CHECK_IF_EQUAL(digit_sum(11111), 5);
    CHECK_IF_EQUAL(digit_sum(12345), 15);

    return 0;
}

// ------------- Function definitions -------------
// Below you implement the functions

int square(int i) {
// TODO
    return i*i;
}
float avg(float i,float j,float k){

    return (i+j+k)/ 3;
}
float rectangle(float width, float height){


    return width * height;
}
// TODO Add function definitions here
float deg_to_rad(float deg){
    return deg * (PI/180);
}
int absolute (int i){
    return abs(i);
}
long long factorial(int i){
    long long answer= i;
    int loop = i;
    for(int j=1; j<loop;j++){
        answer *= i-1;
        i--;
    }
    return answer;
}
/* An other lösning.
long long factorial2(int i){
long long answer=1;
    while(1){
        if(i>0){
            answer *= i;
            i--;
        }
        else{break;}
    }
    return answer;
}
*/
int pow_int(int base, int exp){
    return pow(base, exp); 
}
int n_digits(int x){
    if(x==0){return 1;}
    if(x<0){x*=-1;}

    int i = 0;
    for(;x>0;i++){
        x/=10;
    }
    return i;
    

   
}

int digit_sum(int x){
    int sum = 0;
    int no_1 =0;
    int no_2 =0;
    
    while(x>0){
        no_1 = x%10;
        x /= 10;
        if(x>0){
            no_2 = x%10;
            x/= 10;
        }
        sum = sum + (no_1 + no_2);
        no_2 = 0;
    }
    return sum;
     
}

