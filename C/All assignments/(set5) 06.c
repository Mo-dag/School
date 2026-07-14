/*
 *    Simply read and write a text file
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#define MAX 100

FILE *open_file(const char *name, const char *mode);

int main() {

    setlocale(LC_ALL, "");  // Use users settings for locale (language, encodings etc.)

    // Read a file
    // TODO: Add path to file location!
    char input_file[MAX]="text.txt";    // NOTE: might need to put an absolute path here
    FILE *in  = open_file(input_file, "r");
    // TODO: print text in input_file
    char buffer[MAX];
    while(fgets(buffer, MAX,in)!=NULL){
        printf("%s",buffer);
    }

    fclose(in);

    // Write a file
    // TODO: Add path to file location!
    char output_file[MAX]= "out_text.txt"; // NOTE: might need to put an absolute path here
    FILE *out = open_file(output_file, "w");
    char text[50] = "This text we want to write in our text! ";
    // TODO: write the text in the output_file using fprintf
    fprintf(out,"%s",text);    
    fclose(out);

    return 0;
}

// Helper function to open a file and check if the file was opened correctly
FILE *open_file(const char *name, const char *mode) {
    FILE *f = fopen(name, mode);
    if (f == NULL) {
        printf("Couldn't open file %s!", name);
        exit(EXIT_FAILURE);
    }
    return f;
}

