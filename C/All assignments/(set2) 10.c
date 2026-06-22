/*
 *   Calculate the day number given a year, a month and a day.
 *   See : https://www.epochconverter.com/daynumbers
 *   See: https://en.wikipedia.org/wiki/Leap_year#Algorithm
 *
 * Samples:
 */
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Get ordinal number of day for some date some year
int get_day_nbr(int year, int month, int day);
int is_leap(int year);
int days_in_month(month);
int sum_days(month);
// The test method (all tests)
void test();


int main() {
    //test();                // <--------- Uncomment to test only

    int year;
    int month;
    int day;

    // -- In ----------------
    printf("Program to calculate to ordinal number of a day\n");
    printf("Input the year > ");
    scanf("%d", &year);
    printf("Input the month number > ");
    scanf("%d", &month);
    printf("Input the day number > ");
    scanf("%d", &day);

    // --- Process ---------

    // This is the top level function
    // Implement it by breaking down into smaller functions
    // Combine to solve the problem
    int dayNbr = get_day_nbr(year, month, day);

    // ---- Out ----
    printf("Ordinal number for %d/%d in %d is: %d\n", day, month, year, dayNbr);

    return 0;
}


// TODO Function definitions

#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")

void test(){
    // TODO
    // CHECK_IF_EQUAL( ...), 31);

    // Etc tests as needed

    exit(0);
}
int is_leap(int year){
    if(year %4 != 0 || (year %4 ==0 && year %100 ==0 && year %400 != 0)){return 0;}//not leap 
    //else if(year %4 == 0 && year%100 == 0 && year %400 ==0){return 1;}
    else {return 1;} // leap !
    }
int days_in_month(int month){
    if(month == 2){return 28;}
    else if((month <= 7 && month %2 !=0) || (month >= 8 && month %2 == 0)){
        return 31;
    }
    else{return 30;}
}
int sum_days(int month){
    int days=0;
    for(int i =1; i<month;i++){
        days += days_in_month(i);
    }
    return days;
}
int get_day_nbr(int year, int month, int day){
    int days = sum_days(month);
    if(is_leap(year) ==1 && month >2){
        return days + day +1;
    }
    else{return days + day;}
}
