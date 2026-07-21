/*
 *  This is a rework of remove duplicates exercise from set4
 *  Here we return a dynamically allocated array
 *
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_ARR_EQUAL(a1, a2) printf( memcmp(a1, a2, sizeof(a1)) == 0 ? "ok\n" : "not ok\n")

// Return new dynamically allocated array without duplicates
int *remove_dupl(const int *arr, int size);


int main() {

    int arr[] = {1, 1, 2, 2, 2, 2, 3};

    int *result = remove_dupl(arr, SIZE(arr));
    int expected[] = {1, 2, 3};
    CHECK_IF_ARR_EQUAL(expected, result);   // NOTE: Must have array first
    CHECK_IF_EQUAL(arr == result, false);   // Two different arrays (addresses)

    free(result);   // Not really needed here but in general.

    int arr2[] = {3, 3, 3, 5, 5, 5, 5, 5, 7, 7};
    int *result2 = remove_dupl(arr2, SIZE(arr2));
    int expected2[] = {3, 5, 7};
    CHECK_IF_ARR_EQUAL(expected2, result2);

    free(result2);  // Not really needed here but in general.

    return 0;
}


/*
 * TODO: Implementation
 *  Hint: Use a temporarily (tmp) variable with same size
 *  as arr and copy the unique values to tmp. Keep track of number of 
 *  elements in tmp.
 *  Then,... dynamically allocate an array of that size and copy
 *  values from tmp to allocated. Return allocated array with the correct size.
 */
int *remove_dupl(const int *arr, int size) {
    // TODO
    int temp[size];
    int cnt=0;
    for(int i=0;i<size;i++){
        if(arr[i]!=0)
        {
            if(cnt==0 || arr[i] != temp[cnt-1]){
                temp[cnt]= arr[i];
                cnt++;
            }
        }
    }
    int *result = malloc(cnt*sizeof(int));

    for(int j=0;j<cnt;j++){
        result[j]=temp[j];
    }
    return result;
}
