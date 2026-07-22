#include <stdio.h>

// Function declarations
// REMEMBER: arr[] is same as *arr

// helper method to print the array
void print_arr(const int *arr, int size);

// Sort elements in array using the selection sort algorithm
void selection_sort(int *arr, int size);

// Count unique elements in array
int count_unique(const int *arr, int size);

int main() {
    
    // Initialize unsorted array
    int arr[] = {14, 3, 1, 9, 12, 5, 1, 15, 11, 10, 1, 4, 7, 9, 14, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array: ");
    print_arr(arr, size);
    
    // TODO sort the array by calling 'selection_sort'
    selection_sort(arr,size);
    
    printf("Sorted array:   ");
    print_arr(arr, size);
    
    int nunique = count_unique(arr,size);
    // TODO count how many unique numbers there are in the array by calling 'count_uniques'
    
    
    printf("There are %d unique numbers\n", nunique);
    
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

void selection_sort(int *arr, int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
/*int count_unique(const int *arr, int size){
    
    int unique_nr=0;
    
    for(int i=0;i<size;i++){
        int match =0;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){match++;}
        }
        if(match>1){continue;}
        unique_nr++;
    }
    return unique_nr;
}*/

int count_unique(const int *arr,int size){
    int unique_nr=0;
    for(int i=0;i<size;i++){
        int match =0;
        for(int j=i+1;j<size;j++){
            if(arr[j]==arr[i]){
                match=1;
                break;
            }
        }
        if(match==0){unique_nr++;}

    }
    return unique_nr;
}
