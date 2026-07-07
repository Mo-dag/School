#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")

bool is_sorted(const int *arr, int size);

void bubble_sort(int *arr, int size);

void insertion_sort(int *arr, int size);

double median(const int *arr, int size);

void print_arr(const int *arr, int size);


int main() {
    
    int arr[] = {4, 5, 7, 6, 2, 8, 9, 4, 5, 3, 4, 1, 2, 3, 9, 8};
    CHECK_IF_EQUAL(is_sorted(arr, SIZE(arr)), false);

    bubble_sort(arr, SIZE(arr));
    print_arr(arr, SIZE(arr));
    CHECK_IF_EQUAL(is_sorted(arr, SIZE(arr)), true);

    int arr2[] = {1, 3, 6, 5, 7, 2, 9, 7, 8, 4, 4, 5, 3, 6, 6};
    CHECK_IF_EQUAL(is_sorted(arr2, SIZE(arr2)), false);
    insertion_sort(arr2, SIZE(arr2));
    CHECK_IF_EQUAL(is_sorted(arr2, SIZE(arr2)), true);
    print_arr(arr2, SIZE(arr2));
    

    // Both arrays sorted!
    printf("Size of arr is %llu median is %f\n", SIZE(arr), median(arr, SIZE(arr)));
    printf("Size of arr2 is %llu median is %f\n", SIZE(arr2), median(arr2, SIZE(arr2)));

    return 0;
}

bool is_sorted(const int *arr, int size) {
    // TODO
    
    for(int i=0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}
void swipe(int *arr, int i,int j){
    int swiper = arr[i];
    arr[i]=arr[j];
    arr[j]=swiper;
}
void bubble_sort(int *arr, int size) {
    // TODO

    for(int c=0;c<size-1;c++){
        for(int i=0;i<size-1;i++){
            int swiper;
            if(arr[i]>arr[i+1]){
                swiper=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=swiper;
            }
        }   
    }

    
    
}

void insertion_sort(int *arr, int size) {
    // TODO
    for(int i=1;i<size;i++){// i : is in the front. j : is adjacent
        int loop=i;
        for(int j=i-1;j>=0;j--){
            if(arr[loop]<arr[j]){
                swipe(arr,loop,j);
                loop--;
            }
            
        }
    }
}

// Assumes sorted array
double median(const int *arr, int size) {
    // TODO
    double median = 0;
    int middle=0;
    if(size%2 == 0){
        middle = (size/2);
        middle = arr[middle] + arr[middle-1];
        return median = (double)middle/2;
    }
    else{
        middle=size/2;
        return median = (double) arr[middle];
    }
}

// ----------- Helper method -----------------

void print_arr(const int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[size - 1]);
}
