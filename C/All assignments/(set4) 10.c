#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
// Test macros
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_ARR_EQUAL(V1, V2) memcmp(V1, V2, sizeof(V1)) == 0 ? printf("ok\n") : printf("not ok\n")

// -------- Declarations ---------------

// How many values of to_count are there in arr?
int count(const int arr[], int size, int to_count);

// Return first index of to_find in arr if not found return -1
int find_first(const int arr[], int size, int to_find);

// Set first fraction of array to 1, the rest of the array to 0
void distribute(int arr[], int size, double fraction);

// Randomly reorder elements (a permutation)
void shuffle(int arr[], int size);

// Helper method
void print_arr(const int arr[], int size);


int main() {
    int arr[] = {4, 1, 5, 3, 6, 3, 1, 9};
    srand((unsigned int) time(NULL));
    // Standard way of getting size of array
    int size = sizeof(arr) / sizeof(arr[0]);

    CHECK_IF_EQUAL(count(arr, size, 6), 1);            // There's one 6
    CHECK_IF_EQUAL(count(arr, size, 3), 2);

    CHECK_IF_EQUAL(find_first(arr, size, 4), 0);        // 4 is at index 0
    CHECK_IF_EQUAL(find_first(arr, size, 5), 2);
    CHECK_IF_EQUAL(find_first(arr, size, 99), -1);

    int a2[10];
    size = sizeof(a2) / sizeof(a2[0]);
    distribute(a2, size , 0.2);
    int expected1[] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}; // The expected answer, 20% one's
    CHECK_IF_ARR_EQUAL(a2, expected1);       // Are a2 and expected1 the same? If so print ok.

    distribute(a2, size, 0.5);
    int expected2[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};  // 50% one's
    CHECK_IF_ARR_EQUAL(a2, expected2);

    distribute(a2, size, 0.75);   // Rounded
    int expected3[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    CHECK_IF_ARR_EQUAL(a2, expected3);
    

    size = sizeof(arr) / sizeof(arr[0]);  // reset size to size of arr (not a2)
    shuffle(arr, size);            // Reorder randomly (permutation)
    print_arr(arr, size);          // Use ocular inspection of output
    shuffle(arr, size);
    print_arr(arr, size);
    shuffle(arr, size);
    print_arr(arr, size);

    return 0;
}

// ------ Implementations -----------------

int count(const int arr[], int size, int to_count) {
    // TODO
    int cnt=0;
    for(int i=0;i<size;i++){
        if(arr[i]==to_count){
            cnt++;
        }
    }
    return cnt;
}

int find_first(const int arr[], int size, int to_find) {
    // TODO
    for(int i =0;i<size;i++){
        if(arr[i]== to_find){
            return i;
        }
 
    }
    return -1;
}

void distribute(int arr[], int size, double fraction) {
    // TODO
    // För att : i < 7.5 betyder att : loopa 0,1,2,3,4,5,6,7 = 8 ggr. Då skulle jag round. 
    int ones = round(fraction*size);
    for(int i=0;i<size;i++){
        if(i<ones){
            arr[i] = 1;
        }
        else{arr[i]=0;}
    }
    
}

/*  Fisher- Yates algorithm
    https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
 */
void shuffle(int arr[], int size) {
    // TODO
    int loop = size-1;
   
    while(1){
        int shuffler = rand()%size;
        
        
        int swiper = arr[shuffler];
        arr[shuffler] = arr[loop];
        arr[loop]=swiper;
        loop--;
        size--;

        if(loop ==-1 || size == 0){break;}
        
    }
}

// ----------- Helper method -----------------

void print_arr(const int arr[], int size){
    printf("[");
    for( int i = 0 ; i < size-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size-1]);
}

