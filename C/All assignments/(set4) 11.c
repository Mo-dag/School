#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_ARR_EQUAL(V1, V2) memcmp(V1, V2, sizeof(V1)) == 0 ? printf("ok\n") : printf("not ok\n")

#define ROWS 3
#define COLS 3

// Count how many elements in matrix greater or equal to limit
int count_gte(int n_rows, int n_cols, const int matrix[][n_cols], int limit);

// Is the row and col inside the matrix? If so return true else false
bool is_valid_location(int n_rows, int n_cols, int row, int col);

// Convert array to matrix
// Note: array size must be n_rows * n_cols
void array_to_matrix(int n_rows, int n_cols, int matrix[][n_cols], const int arr[]);

// Sum of all neighbors of position (row, col) in matrix
int sum_neighbours(int n_rows, int n_cols, const int matrix[][n_cols], int row, int col);


int main() {
    int matrix[ROWS][COLS] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };


    CHECK_IF_EQUAL(count_gte(ROWS, COLS, matrix, 4), 6);
    CHECK_IF_EQUAL(count_gte(ROWS, COLS, matrix, 9), 1);

    CHECK_IF_EQUAL(is_valid_location(ROWS, COLS, 0, 0), true);
    CHECK_IF_EQUAL(is_valid_location(ROWS, COLS, ROWS - 1, COLS - 1), true);
    CHECK_IF_EQUAL(is_valid_location(ROWS, COLS, -1, 2), false);
    CHECK_IF_EQUAL(is_valid_location(ROWS, COLS, 3, 0), false);


    int m2[2][2];
    int arr2[] = {0, 3, 7, 5};         // Size = 2 * 2
    array_to_matrix(2, 2, m2, arr2);
    int expected2[] = {0, 3};
    CHECK_IF_ARR_EQUAL(m2[0], expected2);
    int expected3[] = {7, 5};
    CHECK_IF_ARR_EQUAL(m2[1], expected3);

    CHECK_IF_EQUAL(sum_neighbours(ROWS, COLS, matrix, 0, 0), 11); // 2+4+5
    CHECK_IF_EQUAL(sum_neighbours(ROWS, COLS, matrix, 1, 1), 40); // 1+2+3+4+6+7+8+9
    CHECK_IF_EQUAL(sum_neighbours(ROWS, COLS, matrix, 2, 2), 19); // 5+6+8

    return 0;
}


// Should use for-loops
int count_gte(int n_rows, int n_cols, const int matrix[][n_cols], int limit) {
    // TODO
    int cnt=0; 
    for(int r=0;r<n_rows;r++){
        for(int c=0;c<n_cols;c++){
            if(matrix[r][c]>= limit){
                cnt++;
            }
        }
    }
    return cnt;
}

bool is_valid_location(int n_rows, int n_cols, int row, int col) {
    // TODO
    if(row < n_rows && row>0 && col < n_cols && col >0){return true;}
    else{return false;}
}

// Should use for-loop
void array_to_matrix( int n_rows, int n_cols, int matrix[][n_cols], const int arr[] ) {
    // TODO
    int i=0;
    for(int r=0;r<n_rows;r++){
        for(int c=0;c<n_cols;c++){
            matrix[r][c]= arr[i];
            i++;
        }
    }
    
}

// Should use for-loops
int sum_neighbours(int n_rows, int n_cols, const int matrix[][n_cols], int row, int col) {
    // TODO
    // loop row-1 to row +1
    // loop col-1 to cols+1 
    // check if the place is valid.
    // Add to sum.  
    // skip the chosen number.
    int row_start =row-1; 
    int row_range = row+1;
    int col_start=col-1;
    int col_range=col+1;
    int sum = 0;

    for(int r=row_start;r<=row_range;r++){
        for(int c=col_start;c<=col_range;c++){
            if(is_valid_location(n_rows,n_cols,r,c)){
                if(r==row && c==col){continue;}
                sum+= matrix[r][c];
            }
        }
    }
    return sum;
}


