/*
 *   The Robber language, see https://en.wikipedia.org/wiki/R%C3%B6varspr%C3%A5ket
 *
 *
 *   See:
 *   - string_func.c
 *   - use_string_h.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHECK_IF_EQUAL(V1, V2) V1 == V2 ? printf("ok\n") : printf("not ok\n")
#define CHECK_IF_STR_EQUAL(S1, S2) strcmp(S1, S2) == 0 ? printf("ok\n") : printf("not ok\n")

#define VOWELS "aeiouyåäöAEIOUYÅÄÖ"
#define SEPARATOR ",.!?;:"
#define SPACE " \n\t\r"

#define SIZE 200

void to_robber(char *dest, const char *src);

char *to_robber2(const char *src);


int main() {
    char *robber1 = "HoHelola dodagogenon";
    char *robber2 = "NoNejoj, sosovovmomororgogonon";
    char *robber3 = "HoHelollolrore enon fofågogelol i hohanondodenon änon totio i soskokogogenon";

    char dest[SIZE];  // If text too long problems ...(better allocate dynamically)

    char *str = "Hela dagen";
    to_robber(dest, str);
    CHECK_IF_STR_EQUAL(dest, robber1);

    str = "Nej, sovmorgon";
    to_robber(dest, str);
    CHECK_IF_STR_EQUAL(dest, robber2);

    str = "Hellre en fågel i handen än tio i skogen";
    to_robber(dest, str);
    CHECK_IF_STR_EQUAL(dest, robber3);

    // ------- Same using dynamic allocation ---------

    str = "Hela dagen";
    char *result = to_robber2(str);
    CHECK_IF_STR_EQUAL(result, robber1);
    free(result);

    str = "Nej, sovmorgon";
    result = to_robber2(str);
    CHECK_IF_STR_EQUAL(result, robber2);
    free(result);

    str = "Hellre en fågel i handen än tio i skogen";
    result = to_robber2(str);
    CHECK_IF_STR_EQUAL(result, robber3);
    free(result);
}


// Version with dest allocated by callee
void to_robber(char *dest, const char *src) {
    // NOTE: See macros above VOWELS etc.
   // TODO
   int cnt=0;

   for(int i=0;src[i]!='\0';i++){
    if(strchr(VOWELS,src[i])==NULL&&strchr(SPACE,src[i])==NULL&& strchr(SEPARATOR,src[i])==NULL){
        dest[cnt]=src[i];
        cnt++;
        dest[cnt]='o';
        cnt++;
        dest[cnt]=src[i];
        cnt++;
    }
    else{dest[cnt]=src[i];cnt++;}
   }
   dest[cnt]='\0';
}


// Function allocates dynamically
char *to_robber2(const char *src) {
   // TODO
    int size=strlen(src);
    char *dest=malloc(size+1);

    int cnt=0;
    for(int i=0;src[i]!='\0';i++){
        if(strchr(VOWELS,src[i])==NULL && strchr(SPACE,src[i])==NULL && strchr(SEPARATOR,src[i])==NULL){
            dest[cnt]=src[i];cnt++;
            dest[cnt]='o';cnt++;
            dest[cnt]=src[i];cnt++;
        }
        else{dest[cnt]=src[i];cnt++;}
    }
    dest[cnt]='\0';


    return dest;
}
