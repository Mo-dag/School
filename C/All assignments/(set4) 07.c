#include <stdio.h>

// TODO define the structure 'student'
typedef struct {
    char grad;
    unsigned long long pnumber;
}students_t;

int main() {
    
    // Number of students
    int nstudents = 3;
    
    // TODO declare an array called 'grades' to store student information 
    students_t grades [3];
    
    for (int i = 0; i < nstudents; i++) {
        
        // variables to temporary hold input 
        unsigned long long int pnr;
        char grd;
        
        // Get input from user
        printf("Student %d\n", i+1);
        printf("Enter social security number: ");
        scanf("%llu", &pnr);
        printf("Enter grade (A-F): ");
        scanf(" %c", &grd); // NOTE: space in string necessary here, since we use %c and read a number before
        
        // TODO declare variable called 'stud' of type 'struct student'
        students_t stud;
        // TODO assign input values to members of 'stud'
        stud.grad = grd;
        stud.pnumber = pnr;
        // TODO store student information in the array 'grades'
        grades[i] = stud;
    }
    
    // Select student to view grade and social security number
    int studnr;
    printf("\nEnter student number to see social security number and grade: ");
    scanf("%d", &studnr);
    
    // TODO print the social security number and the grade for the selected student
    printf("Social security numbner is : %llu \nGrade is : %c\n", grades[studnr-1].pnumber, grades[studnr-1].grad);

    return 0;
}
