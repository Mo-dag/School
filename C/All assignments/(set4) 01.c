#include<stdio.h>

int main() {
    
    // TODO initialize array with integer values
    
    int array [] = {2,3,5,8,4,1,9};
    // TODO use 'sizeof' to get the size of the array
    int the_size = sizeof(array)/ sizeof(array[0]);
    
    // TODO Print size of the array
    
    printf("The size of the array %d\n", the_size);
    printf("Elements of the array are: ");
    // TODO Print the values of the array elements
    for(int i = 0; i<the_size;i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    // TODO Calculate the sum of the elements in the array
    int sum = 0;
    for (int j = 0; j<the_size;j++){
        sum += array[j];
    }
    
    // TODO Print the sum of the array elements
    printf("The sum of array elements : %d\n", sum);

    return 0;
}
