#include <stdio.h>

#define NROWS 2   
#define NCOLS 3

// TODO make a function that initializes an integer 2D array with some value 
void init_2Darr(int arr[NROWS][NCOLS],int value){
    for(int r=0;r<NROWS;r++){
        for(int c=0;c<NCOLS;c++){
            arr[r][c] = value;
        }
    }
}

// TODO make a function that prints all elements in an integer 2D array
void print_arr(int arr[NROWS][NCOLS]){
    for(int r=0;r<NROWS;r++){
        for(int c=0;c<NCOLS;c++){
            printf("%d ", arr[r][c]);
        }
    }
    printf("\n");
}
int main() {
	
    // Declare integer 2D array with 2 rows and 3 columns 
    int int2Darray[NROWS][NCOLS];    // TODO make sure your functions work for arbitrary size of the array 
    
    // TODO initialize int2Darray with ones
    init_2Darr(int2Darray,1);
    
    printf("Elements of 2D array with %d rows and %d columns are:\n", NROWS, NCOLS);
    // TODO print the values of intarray
    print_arr(int2Darray);

    
    return 0;
}
