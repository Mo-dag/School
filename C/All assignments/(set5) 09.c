#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//TODO Declare functions
void first_cap(char new_str[],char text[]);

int main() {
    // Declare new_string 
    char new_string[50];
    first_cap(new_string, "some string");
    printf("%s\n", new_string);
    first_cap(new_string, "one, two, three");
    printf("%s\n", new_string);
    first_cap(new_string, "the Elephant\nis\tpink");
    printf("%s\n", new_string);
    return 0;
}


//TODO Implement functions
void first_cap(char new_str[],char text[]){
    int i=0;
    int toupp=0;
    char ch;
    for(;text[i]!='\0';i++){
        ch=text[i];
        if(i==0){
            new_str[i]=toupper(ch);
            continue;
        }
        else if(isspace(ch)){
            new_str[i]=ch;
            toupp=1;
        }
        else{
            if(toupp==1){
                new_str[i]=toupper(ch);
                toupp=0;
            }
            else{new_str[i]=ch;}
    }
    }
    new_str[i]='\0';
}
