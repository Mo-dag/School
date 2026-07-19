/*
 *   Check for matching parentheses.
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

bool is_closing(char open, char close);

// Return index of ch in str. If not found return -1.
int index_of(const char *str, char ch);

// True if parentheses match
bool matches(const char *str);


int main() {

    CHECK_IF_EQUAL(matches("((()))"), true);
    CHECK_IF_EQUAL(matches("((())"), false);
    CHECK_IF_EQUAL(matches("(<({})>)"), true);
    CHECK_IF_EQUAL(matches("(<({)}>)"), false);
    CHECK_IF_EQUAL(matches("()<[]>{}"), true);

    return 0;
}
/*
Den kan luras.
bool matches(const char *str) {
    // TODO
    int loop = strlen(str);
    int open_loop;
    int close_loop;
    char open_check[] ="{[<(";
    char close_check[]="}]>)";
    char open;
    char close;
    if(loop%2==0){
        open_loop = (loop/2)-1;
        close_loop= (loop/2);
    }
    else{
        open_loop = (loop/2);
        close_loop= open_loop;
    }
    int x=close_loop;
    int i=open_loop;

    while(x<loop){
        for(;i>=0;i--){
            for(int j=0;j<strlen(open_check);j++){
                if(str[i]==open_check[j]){
                i--;
                open=str[i+1];
                break;
                }
            }
        }
        for(;x<loop;x++){
            for(int y=0;y<strlen(close_check);y++){
                if(str[x]==close_check[y]){
                    x++;
                    close=str[x-1];
                    break;
                }
            }
        }
        if(is_closing(open,close)!= true){
            return false;
        }
    }


}

*/
/*
Den får godkänd på test men den kan luras.
bool matches(const char *str) {
    // TODO
    char open_check[] ="{[(<";
    char close_check[]="}])>";

    int loop = 0;
    int str_length = strlen(str);

    int i=0;
    int open,close;
    while(loop < str_length){
        for(int i=0;i<str_length;i++){
            for(int j=0;j<strlen(open_check);j++){
                if(str[i]==open_check[j]){
                    open = str[i];
                    for(int x=i;x<str_length;x++){
                        if(str[x]==close_check[j]){
                            close=str[x];
                            if(is_closing(open,close)==false){return false;}
                        }    
                    }
                }
            }
        }
        loop++;        
    }

}

*/


bool matches(const char *str) {
    // TODO
    char bracket[30];
    int top=-1;

    for(int i=0;str[i]!='\0';i++){
        char ch = str[i];
        if(ch == '{' || ch == '[' || ch == '(' || ch == '<'){
            bracket[++top]=ch;
        }
        else if(ch == '}' || ch == ']' || ch == ')' || ch == '>'){
            if(top!=-1){
                if(!is_closing(bracket[top],ch)){
                    return false;
                }
                else{top--;}
            }
            else{return false;}
        }
    }
    if(top==-1){return true;} //bracket att jämföra finns inte kvar. 
    else{return false;}

}

int index_of(const char *str, char ch) {
    // TODO
    const char *p = strchr(str,ch);
    if(p != NULL){
        int place = p-str;
        return place;
    }
    return -1;
}
 
bool is_closing(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '<' && close == '>') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
