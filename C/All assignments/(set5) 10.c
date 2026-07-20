#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
char vowels[] = "aeiouy";

void Svinlatin(char out[],char in[],char vowels[]);
int main() {
    
    char word_in[99], word_out[99];


    // TODO Your code here. Decalre functions if you need them.
    scanf("%s", word_in);
    Svinlatin(word_out,word_in,vowels);
    printf("%s\n",word_out);
    return 0;
}


void Svinlatin(char out[],char in[],char vowels[]){
    if(strchr(vowels,tolower(in[0]))){
        int i=0;
        for(;in[i]!='\0';i++){
            out[i]= in[i];
        }
        out[i]  ='w';
        out[++i]='a';
        out[++i]='y';
        out[++i]='\0';
    }
    else if(!strchr(vowels,tolower(in[0]))){
        int i=0;
        int cnt=0;
        for(i=1;in[i]!='\0';i++){
            out[cnt] = in[i];
            cnt++;
        }
        out[cnt]  = tolower(in[0]);
        out[++cnt]= 'a';
        out[++cnt]= 'y';
        out[++cnt]= '\0';
    }

}
