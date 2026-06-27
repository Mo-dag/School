#include <stdio.h>

// TODO implement function 'modify_int'
void modify_int(int *x);

int main() {
    
    // initialize a variable called 'a' of type int to have the value 6
    int a = 6;
    // Declear an integer pointer called 'ptr'
    int *ptr;
    //Print original value of 'a'
    printf("Original value of a: %d\n", a);
    
    // TODO use the pointer 'ptr' to change the value of 'a' to 15
    ptr = &a;
    *ptr = 15;
    // print new value of 'a'
    printf("New value of a: %d\n", a);
    
    //TODO call 'modify_int' to change the value of 'a' to 23
    modify_int(ptr);
    // print final value of 'a'
    printf("Final value of a: %d\n", a);
    
    return 0;
}

void modify_int(int *x){
    *x = 23;
}
