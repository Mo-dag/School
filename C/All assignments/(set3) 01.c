#include <stdio.h>

// TODO Look at values and addresses of a variable and a pointer.

int main() {
    
    // Initialize a variable called 'a' of type int to have the value 5
    int a = 5;

    // TODO Declare an integer pointer called 'ptr' that points to the variable a
    int *ptr_a = &a;
    // TODO Print the value of a
    printf("%d",a);
    // TODO Print the value that ptr points to
    printf("%d", *ptr_a);
    // TODO Print the address of a (remember that %p is the format specifier for addresses)
    printf("%p", &a);
    // TODO Print the value of ptr
    printf("%p", ptr_a);
    // TODO Print the address of ptr
    printf("%p", &ptr_a);
    return 0;
}
