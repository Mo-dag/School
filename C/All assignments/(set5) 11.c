/*
 *  Dynamic allocation of array
 *
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>


int main() {
    int n_elems;
    printf("How many elements > ");
    scanf("%d", &n_elems);

     // TODO allocate array 
    int *ptr = NULL;
    ptr = malloc(n_elems * sizeof(int));
    for( int i = 0 ; i < n_elems; i++){
        printf("Input %d >  ", i);
        scanf("%d", &ptr[i]);
    }

    printf("Array is: ");
    for( int i = 0 ; i < n_elems; i++){
        printf("%d  ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}

