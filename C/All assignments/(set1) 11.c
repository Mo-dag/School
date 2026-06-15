#include <stdio.h>

int main() {
    int dagens_datum = 20260615;
    int PN;
    int year = 2026;
    int month = 06;
    int day = 15;
    printf("Personal number: ");
    scanf("%d", &PN);

    int birth_year = PN/10000;
    int birth_day = PN%100;
    int birth_month = (PN/100)%100;
    if((year-birth_year) > 20){printf("OK\n");}
    else if((year-birth_year) < 20){printf("!!! Not OK !!!\n");}
    else if((year-birth_year) == 20){
        if(birth_month < month){
            printf("OK\n");
        }
        else if(birth_month == month){
            if(birth_day <= day){printf("OK\n");}
        else{printf("!!! Not OK !!!\n");}
        }
        else{printf("!!! Not OK !!!\n");}
    } 
    
    return 0;
}
