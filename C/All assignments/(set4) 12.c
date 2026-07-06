/*
 *   Remove duplicates from sorted array
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

// Test macros
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_ARR_EQUAL(V1, V2) memcmp(V1, V2, sizeof(V1)) == 0 ? printf("ok\n") : printf("not ok\n")

// Inputs src (with duplicates) and get dest (without duplicates)
void remove_dupl(int *dest, const int *src, int size);


int main() {

    int arr[] = {1, 1, 2, 2, 2, 2, 3};

    int result[SIZE(arr)];
    remove_dupl(result, arr, SIZE(arr));
    int expected[] = {1, 2, 3, 0, 0, 0, 0};
    CHECK_IF_ARR_EQUAL(expected, result);
    
    int arr2[] = {3, 3, 3, 5, 5, 5, 5, 5, 7, 7};

    int result2[SIZE(arr2)];
    remove_dupl(result2, arr2, SIZE(arr2));
    int expected2[] = {3, 5, 7, 0, 0, 0, 0, 0, 0, 0};
    CHECK_IF_ARR_EQUAL(expected2, result2);
    

}


void remove_dupl(int *dest, const int *src, int size) {
   // TODO
   int cnt=0;
   for(int i=0;i<size;i++){
        int is_used=0;
        for(int j=0;j<cnt;j++){
            if(src[i] == dest[j]){
                is_used = 1;
            }
        }
        if(is_used==0){
                dest[cnt]=src[i];
                cnt++;
            }
            
   }
   for(int i=cnt;i<size;i++){
    dest[i]=0;
   }
}
   
