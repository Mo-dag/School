#include<stdio.h>

#define ROWS 2   // Possibly try other value
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int transpose[COLS][ROWS];

    // --- In -------------
    printf("Program to transpose matrix\n");
    printf("Input a %d x %d matrix\n", ROWS, COLS);
    // Read input to the matrix 
    //Rows =2 , Cols = 3 

    for(int r =0;r<ROWS;r++){
        for(int c =0; c<COLS;c++){
            printf("Input %d %d ", r,c);
            scanf("%d", &matrix[r][c]);
        }
    }
    // ---- Process ----------
    // TODO transpose the matrix

    for(int c = 0;c<COLS;c++){
        for(int r = 0; r<ROWS;r++){
            transpose [c][r] = matrix[r][c];
        }
    }
    // ------ Out ------------------

    printf("Matrix is\n");
    // TODO print the matrix
    for(int r = 0; r<ROWS;r++){
        for(int c=0; c<COLS;c++){
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    printf("Transpose is\n");
    // TODO print the transpose
    for(int c=0; c<COLS;c++){
        for(int r=0; r<ROWS;r++){
            printf("%d ", transpose[c][r]);
        }
        printf("\n");
    }

    return 0;
}

































/*    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("Input %d %d > ", r, c);
            scanf("%d", &matrix[r][c]);
        }
    }
*/
