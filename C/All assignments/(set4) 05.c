#include <stdio.h>

// TODO
// Define an enumeration named 'days' containing
// the days of the week
enum days{monday,tuesday,wednesday,thursday,friday,saturday,sunday};
// TODO rename the type `enum days` to 'days_t'
typedef enum days days_t;
int main()
{
    // TODO initialize a variable called today with the value of current day
    days_t today = monday;
    
    // TODO Check if it is the weekend yet
    if(today == saturday || today == sunday){
        printf("It is weekend");
    }
    else{printf("It is not weekend yet");}
    // (compare today with a value in days)

   return 0;
}

