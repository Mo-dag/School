Uppgiften : 

//int main() {

    // There is one mistake in this block
    /*
    int foundation_year;
    */  
    // There is one mistake in this block
    /*
    1829 = foundation_year;
    */  
    // The code below does not work. Why?
    /*
    printf("Chalmers was founded in %d.\n", foundation_year);
    */  
    // We ask the user for a year.
    // The code below does not work. Why? Can you fix it?
    /*
    int year;
    scanf("Insert a year: %f", year);
    */

    // The code below does not work as it should. Why? Can you fix it?
    // Note 1: there is more than one error.
    // Note 2: try giving a year different than 1829 to the program.
    /*
    if (year = foundation_year){
        print("%d was when Chalmers was founded.\n\n", &year);
    } else {
        print("In %i Chalmers was not founded.\n\n", &year);
    }
    */  
    // According to the reports, there were this many full-time students in Chalmers
    // - Year 2019:  9,744
    // - Year 2020: 10,203
    // - Year 2021: 10,712
    // - Year 2022: 10,595
    // The goal of the code below is to present the latest number of students available
    // What is wrong?
    /*
    int last_year = 2022;      // Do not modify this line
    if (2022 == last_year){
        student_count = 10595; // Do not modify this line
        last_year = 2021;      // Do not modify this line
    } if (2021 == last_year){
        student_count = 10712; // Do not modify this line
        last_year = 2020;      // Do not modify this line
    } if (2020 == last_year){
        student_count = 10203; // Do not modify this line
        last_year = 2019;      // Do not modify this line
    } if (2019 == last_year){
        student_count = 9744;  // Do not modify this line
        last_year = 2018;      // Do not modify this line
    }
    printf("In the last available report (2022) "); // Do not modify this line
    printf("Chalmers presents it had %d students.\n", student_count); // Do not modify this line
    */  
    //return 0;
//}


Lösningen : 
#include <stdio.h>
int main() {

    // There is one mistake in this block
    int foundation_year;
    // There is one mistake in this block
    
    foundation_year = 1829;
      
    // The code below does not work. Why?
    printf("Chalmers was founded in %d.\n", foundation_year);
    // We ask the user for a year.
    // The code below does not work. Why? Can you fix it?
    
    int year;
    printf("Insert a year: ");
    scanf("%d", &year);

    // The code below does not work as it should. Why? Can you fix it?
    // Note 1: there is more than one error.
    // Note 2: try giving a year different than 1829 to the program.
    
    if (year == foundation_year){
        printf("%d was when Chalmers was founded.\n\n", year);
    } else {
        printf("In %i Chalmers was not founded.\n\n", year);
    }
    // According to the reports, there were this many full-time students in Chalmers
    // - Year 2019:  9,744
    // - Year 2020: 10,203
    // - Year 2021: 10,712
    // - Year 2022: 10,595
    // The goal of the code below is to present the latest number of students available
    // What is wrong?
    
    int student_count;
    int last_year = 2022;      // Do not modify this line
    if (last_year == 2022){
        student_count = 10595; // Do not modify this line
        last_year = 2021;      // Do not modify this line
    } else if (last_year == 2021){
        student_count = 10712; // Do not modify this line
        last_year = 2020;      // Do not modify this line
    } else if (last_year == 2020){
        student_count = 10203; // Do not modify this line
        last_year = 2019;      // Do not modify this line
    } else if (last_year == 2019){
        student_count = 9744;  // Do not modify this line
        last_year = 2018;      // Do not modify this line
    }
    printf("In the last available report (2022) "); // Do not modify this line
    printf("Chalmers presents it had %d students.\n", student_count); // Do not modify this line
    // If controllerar varej gng.
    // else if kör bara nästa om den första var falsk.
    return 0;
}
