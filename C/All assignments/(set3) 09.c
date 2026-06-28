/*
 *  Uncomment a)-g) one at a time and explain
 *
 *  - If compile error: What's the problem (comment out again)?
 *  - If no compile error. Run it. Any problems? If so what happens? Why?
 *    NOTE: if exit code is not 0 there's a problem (11 is segmentation fault i.e. crash)
 *  - If no problem what will be printed? Why?
 */

#include<stdio.h>

int main() {

    int i = 1;
    int j = 2;
    int *k;       
    int *l;       

    // a)
    //printf("%d\n", i);          

    // b)
    //printf("%d\n", sizeof(&i) == sizeof(i));  Den ger resultatet 0 för att size of i's adress är inte lika med size of i

    // c)
    //&i = 0xFFFFFF;          //Fel för att den försöker sätta adress till i. Dator som bestämmer adressen. 

    // d)
    // *&i = 567;               // fel, * och & behövs inte här.
    // printf("%d\n", i);          

    // e)
    // *k = i;                    // k är inte kopplad till nåt adress. 
    // printf("%d", *k);

    // f)
    // k = i;                      // K är en pekare, det är fel. 
    // printf("%d", *k);     

    // g)
    // *l = &k;           // Det är fel, om den pekade till pekare från början den skulle vara korrekt ! : int **l = &k;
    // printf("%p", l);

    return 0;
}
