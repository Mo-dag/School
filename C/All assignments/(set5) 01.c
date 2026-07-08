#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    
    // initialize string with text
    char str[] = "This is a text with seven words.";
    
    // TODO print string
    int size=sizeof(str)/sizeof(str[0]);
    int cnt =0;
    for(int i=0;i<size;i++){
        putchar(str[i]);
        if(str[i]==' '){
            cnt++;
        }
    }

    
    // TODO count number of words in the text placed in 'str'
    
    // TODO print the result
    printf("\n");
    printf("Number if words: %d\n", cnt+1);

    // TODO capitalize all letters in the text
    for(int i=0;i<size;i++){
        putchar(toupper(str[i]));
    }
    
    // TODO print string
    

    return 0;

}
