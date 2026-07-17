/*
 *    Encrypt/Decrypt a file.
 *    Using Caesar cipher, see: https://en.wikipedia.org/wiki/Caesar_cipher
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAX_BUF 100

bool read_str(char str[], int max_len);

void clean_stdin(void);

FILE *open_file(const char *name, const char *mode);

void encrypt(const char *dest, const char *src, int key);

void decrypt(const char *dest, const char *src, int key);


int main() {

    setlocale(LC_ALL, "");  // Use users settings for locale (language, encodings etc.)

    int selection;
    int key;
    char in_file_name[MAX];
    char out_file_name[MAX];

    while (true) {
        printf("Select\n1) Encrypt\n2) Decrypt (-1 to quit)\n> ");
        scanf("%d", &selection);
        if (selection < 0) {
            break;
        }
        printf("Input (de)cipher key (small int) > ");
        scanf("%d", &key);

        clean_stdin();

        printf("In file name > ");
        read_str(in_file_name, MAX);
        printf("Out file name > ");
        read_str(out_file_name, MAX);
        if (selection == 1) {
            encrypt(out_file_name, in_file_name, key
            );
        } else if (selection == 2) {
            decrypt(out_file_name, in_file_name, key
            );
        } else {
            printf("Unknown selection? > ");
        }
    }

    return 0;
}


void encrypt(const char *dest, const char *src, int key){
    FILE *in = open_file(src,"r");
    FILE *out = open_file(dest,"w");
    // TODO

    // För encrypt skulle vi använda : fgetc, fputc för att skriva och läsa från in, out. 
    int ch;

    while((ch=fgetc(in))!= EOF){

        if((ch>='A' && ch<='Z') || (ch>='a'&&ch<='z')){
            for(int i=0;i<abs(key);i++){
                if(key>0){
                    if(ch=='Z'){
                        ch='A';
                    }
                    else if(ch=='z'){
                        ch='a';
                    }
                    else{ch++;}
                }
                else if(key<0){
                    if(ch=='A'){
                        ch='Z';
                    }
                    else if(ch=='a'){
                        ch='z';
                    }
                    else{ch--;}

                }
            }
            fputc(ch,out);
        }
        else{fputc(ch,out);}
    }
    fclose(in);
    fclose(out);
}



void decrypt(const char *dest, const char *src, int key) {
    // TODO
    // Jag kan bara anropa encrypt med minus tecken på key. 
    FILE *in  = open_file(src,"r");
    FILE *out = open_file(dest,"w");

    int ch;

    while((ch=fgetc(in))!=EOF){
        if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z')){
            for(int i=0;i<abs(key);i++){
                if(key>0){
                    if(ch=='a'){
                        ch='z';
                    }
                    else if(ch=='A'){
                        ch='Z';
                    }
                    else{ch--;}
                }
                else if (key<0){
                    if(ch=='z'){
                        ch = 'a';
                    }
                    else if(ch=='Z'){
                        ch='A';
                    }
                    else{ch++;}
                }

            }
            fputc(ch,out);
        }
        else{fputc(ch,out);}
    }
    fclose(in);
    fclose(out);
}

FILE *open_file(const char *name, const char *mode) {
    FILE *f = fopen(name, mode);
    if (f == NULL) {
        printf("Couldn't open file %s!", name);
        exit(EXIT_FAILURE);
    }
    return f;
}

// --------- IO -----------------
/*
 * Reading strings from keyboard is complex
 * Here are some helper functions
 */

// Remove possible trailing char in stdin (keyboard buffer)
void clean_stdin(void) {
    int c;
    // Read until we hit \n or EOF
    while ((c = getchar()) != '\n' && c != EOF);    // <-- Empty statement
}

// Remove possible \n in string (new line)
bool remove_nl(char *str) {
    size_t i = strlen(str) - 1;
    if (str[i] == '\n') {   // Is there a \n (enter key) to the left?
        str[i] = '\0';      // If so replace
        return true;
    }
    return false;
}

// Read string from keyboard

bool read_str(char str[], int max_len) {
// Use fgets to limit user input.
if (fgets(str, max_len, stdin) == NULL) {
    return false;   // Input failed for some reason...
}
if (!remove_nl(str)) {
    clean_stdin();       // Didn't read \n
}
return true;
}
