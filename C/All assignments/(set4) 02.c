#include <stdio.h>

// TODO make a function that initializes an integer array with some value 
void int_init(int *arr,int x,int value);
// TODO make a function that prints all elements in an integer array
void print_arr(int *arr,int x);
int main() {
	
    // Declare integer array with 6 element 
    int intarray[6];    // TODO make sure your functions work for arbitrary size of the array 
    
    // TODO Get the size of the array
    int arr_size = sizeof(intarray)/sizeof(intarray[0]);
    // TODO initialize intarray with ones
    int_init(intarray, arr_size,1);
    printf("Elements of the array are: ");
    // TODO print the values of intarray
    print_arr(intarray, arr_size);
    return 0;
}

void int_init(int *arr, int x,int value){ 
    int arr_size = x;
    for(int i=0; i<arr_size;i++){
        arr[i] =value;
    }
}

void print_arr(int *arr,int x){
    int loop = x;
    for(int i = 0; i<loop;i++){
        printf("%d ", arr[i]);
    }
}
