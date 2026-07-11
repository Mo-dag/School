/*
         Exercising string functions.

    See:
    - string_func.c

 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_STR_EQUAL(S1, S2) strcmp(S1, S2) == 0 ? printf("ok\n") : printf("not ok\n")

#define SIZE 20

// Count number of character ch in str
int count(const char *str, char ch);

// Convert string to lowercase and return it (i.e. return changed original)
// This uses ASCII codes. The difference between upper case and lower case
// letters is 32 (ASCII code for space). Just need to consider the english alphabet (A-Z)
char *to_lower(char *str);

// Reverses string src. Result in dest
void reverse(char *dest, const char *src);

// Remove leading and trailing space in str.
// Should return a new (dynamically allocated) string
char *trim(const char *str);


int main() {

    CHECK_IF_EQUAL(count("a b c  de", ' '), 4);
    CHECK_IF_EQUAL(count("a   b   ", ' '), 6);

    char str1[] = "ABCDE?";
    CHECK_IF_STR_EQUAL(to_lower(str1), "abcde?");
    char str2[] = "OOpssHhh!";
    CHECK_IF_STR_EQUAL(to_lower(str2), "oopsshhh!");

    char tmp[strlen(str1) + 1];    // +1 because of '\0'
    reverse(tmp, str1);
    CHECK_IF_STR_EQUAL(tmp, "?edcba");

    char str[] = "   abcde  ";     // 3 spaces before and 2 after
    char *ptr = trim(str);
    CHECK_IF_EQUAL(str == ptr, false);     // Get new dynamically allocated string
    CHECK_IF_STR_EQUAL(ptr, "abcde");

    return 0;
}


// -------- Function definitions ----------------

int count(const char *str, char ch) {
   // TODO
   int cnt =0;
   for(int i=0;str[i]!='\0';i++){
    if(str[i]==ch){cnt++;}
   }
   return cnt;
}

char *to_lower(char *str) {
    // TODO
    for(int i=0;str[i]!='\0';i++){
        str[i]=tolower(str[i]);
    }
    return str;
}

void reverse(char *dest, const char *src) {
    // TODO
    int size=strlen(src); // strlen : räknar inte \0 Därför kommer jag att minska bara 1
    int cnt=0;
    for(int i=size-1;i>=0;i--){
        dest[cnt] = src[i];
        cnt++;
    }
    dest[cnt]='\0';
}

char *trim(const char *str) {

    // TODO
    // NOTE: You only need to consider strings that may have spaces at the beginning or at the end. 
    // You do not need to handle cases where spaces appear between characters within the string.
    int start =0;
    int end=0;


    for(int i =0;;i++){
        if(str[i]==' '){
            start++;
        }
        else{break;}
    }

    for(int j=strlen(str)-1;j>0;j--){
        if((str[j]) == ' '){
            end++;
        }
        else{j=0;}
    }
    
    
    int dest_size = strlen(str)+1 -(start+end);
    char *dest = malloc(dest_size);
    int dest_loop=0;

    for(int i=start;i<=strlen(str)-end-1;i++){
        dest[dest_loop]=str[i];
        dest_loop++;
    }
    dest[dest_loop]='\0';
    return dest;
}





/*
I C kan vi inte returnera en hel lokal array direkt.
Om vi skapar arrayen inne i funktionen försvinner den när funktionen slutar.
Därför returnerar vi en pekare till minne som skapats med malloc.
malloc-minnet lever kvar efter funktionen.*/
