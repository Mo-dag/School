/*
 *     Assignment 1a, Number Fiddling
 *
 *     (Read ASSIGNMENT1a.pdf carefully before you start coding)
 *
 *     HINTS: 
 *     - integer division and the moldulo operator are very useful
 *       in this assignment
 *     - functions from set2\ex_functions may be reused! 
 */


#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>


// This macro is used for testing. It expects V1 and V2 to be equal and prints OK or Not OK
#define CHECK_IF_EQUAL(V1, V2) (V1) == (V2) ? printf("ok\n") : printf("not ok\n")

// --------------- Function declarations ------------------------

int n_digits(int number);

int get_digit_at_position(int number, int position);

bool digit_is_in(int number, int digit);

bool is_unique_digits(int number);

// Generates a n-digit random number with no repeated digits
// (digits in range 1-9)
int get_random_digits(int n);

// Returns number of exact digit matches between two numbers
int n_exact_digit_matches(int number1, int number2);

// Returns number of digit matches between two numbers without
// considering the position
int n_digit_matches(int number1, int number2);

int main() {

    // TODO Initialize random number generator with random seed
    srand((unsigned int)time(NULL));
    // TODO Uncomment one at the time to test the functions
    // test the n_digits-function
    CHECK_IF_EQUAL(n_digits(123), 3);
    CHECK_IF_EQUAL(n_digits(12345), 5);
    CHECK_IF_EQUAL(n_digits(1623945), 7);
    
  
   
    CHECK_IF_EQUAL(get_digit_at_position(4321, 0), 1);
    CHECK_IF_EQUAL(get_digit_at_position(4321, 2), 3);
    CHECK_IF_EQUAL(get_digit_at_position(432156, 5), 4);
    
    CHECK_IF_EQUAL(digit_is_in(2637, 2), true);
    CHECK_IF_EQUAL(digit_is_in(2637, 4), false);
    CHECK_IF_EQUAL(digit_is_in(2607, 0), true);
    CHECK_IF_EQUAL(digit_is_in(2670, 0), true);

    CHECK_IF_EQUAL(is_unique_digits(2237), false);
    CHECK_IF_EQUAL(is_unique_digits(2637), true);
    CHECK_IF_EQUAL(is_unique_digits(2132), false);
    CHECK_IF_EQUAL(is_unique_digits(243865), true);
    printf("3-digit random number %d\n", get_random_digits(3));
    printf("6-digit random number %d\n", get_random_digits(6));
    CHECK_IF_EQUAL(get_random_digits(10), 0);


    CHECK_IF_EQUAL(n_exact_digit_matches(1827, 7812), 1);
    CHECK_IF_EQUAL(n_exact_digit_matches(2647, 2837), 2);

    CHECK_IF_EQUAL(n_digit_matches(1827, 7812), 4);
    CHECK_IF_EQUAL(n_digit_matches(2647, 2837), 2);
    
    return 0;
}

// ----------------- Function definitions ---------------------

// TODO define functions here

int n_digits(int number){
    int n = number;
    int cnt=0;
    while(n!=0){
        n/=10;
        cnt++;
    }
    return cnt;
}


int get_digit_at_position(int number, int position){
    int n =number;
    while(position>0){
        position--;
        n/=10;
    }
    return n%10;
    }

bool digit_is_in(int number, int digit){
    int n=number;
    while(n>0){
        if(n%10 == digit){return true;}
        n/=10;
    }
    return false;
}

bool is_unique_digits(int number){
    int n = number;
    
    while(n>0){
        int n_copy = n/10;
        if(n%10==n_copy%10){return false;}
        while(n_copy>0){
            
            if(n_copy%10==n%10){return false;}
            n_copy/=10;
        }
        n/=10;
    }
    return true;
}

int get_random_digits(int n){
    if(n<1 || n>9){exit(EXIT_FAILURE);}
    int loop = n;
    int num=0;
    int digit=0;
    while(loop>0){
        digit=rand()%9+1;
        if(!digit_is_in(num,digit)){
            num*=10;
            num+=digit;
            loop--;
        }
    }
    return num;
}

int n_exact_digit_matches(int number1, int number2){
    // I uppgiften : You may assume that the two numbers have the same number of digits.
    int n1=number1;
    int n2=number2;
    int cnt=0;
    int position=0;
    while(n1>0){
        int last_digit = n1%10;
        
        if(get_digit_at_position(n2,position)==last_digit){
                cnt++;
        }
        
        position++;
        n1/=10;
    }
    return cnt;
}

int n_digit_matches(int number1, int number2){
    // I uppgiften : You can assume that the function will be used only for unique digits.
    int n1=number1;
    int n2=number2;
    int cnt=0;

    while(n1>0){
        int n_check = n1%10;
        if(digit_is_in(n2,n_check)){
            cnt++;
        }
        n1/=10;
    }
    return cnt;
    
}
