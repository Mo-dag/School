#include <stdio.h>

// TODO implement function to swap two integers using pointers
void swap(int *x, int *y);
// TODO implement function to sort two integers 
void sort_int(int *x, int *y);
int main() {
    
    int num1;
    int num2;
    
    printf("Enter two integers:\n");
    printf("first integer > ");
    scanf("%d", &num1);
    printf("second integer > ");
    scanf("%d", &num2);
    
    // TODO call sort_int to sort the values of num1 and num2
    sort_int(&num1, &num2);   
    printf("num1 = %d, num2 = %d\n", num1, num2);
    
    return 0;
}

void swap(int *x,int *y){
    int place_holder = *x;
    *x = *y;
    *y = place_holder;
} 
void sort_int(int *x, int *y){
    if(*y<*x){
        swap(x,y);
    }
}
