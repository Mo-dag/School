#include <stdio.h>

// Function declarations
// REMEMBER: arr[] is same as *arr

// helper method to print the array
void print_arr(const int *arr, int size);

// Sort elements in array using the insertion sort algorithm
void insertion_sort(int *arr, int size);

// Seach for element in array using binary search algorithm
int binary_search(const int *arr, int size, int seek);

int main() {
    
    // Initialize unsorted array
    int arr[] = {14, 3, 2, 9, 12, 5, 1, 15, 11, 16, 4, 7, 8, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array: ");
    print_arr(arr, size);
    
    // TODO sort the array by calling 'insertion_sort'
    
    insertion_sort(arr,size);    
    printf("Sorted array:   ");
    print_arr(arr, size);
    
  
    int index;
    int value = 11;
    // TODO find the index of 'value' in the array by calling 'binary_search'
    index=binary_search(arr,size,value);
    printf("Value %d is at index %d\n", value, index);
    
    return 0;
}

// TODO implement functions here



// ----------- Helper method -----------------

void print_arr(const int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}

void insertion_sort(int *arr,int size){

    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j=j-1;
        }
    }
}

int binary_search(const int *arr, int size, int seek){

    int i=0;
    int j=size-1;
    int k;

    while(i<=j){
        k=(i+j)/2;
        if(seek<arr[k]){
            j=k-1;
        }
        else if(seek>arr[k]){
            i=k+1;
        }
        else{break;}
    }
    if(seek == arr[k]){return k;}
    else{return -1;}
}
