#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Put function declarations here.

// Define how long a line is allowed to be.
const int MAX_LINE_LENGTH = 500;
int count_word(FILE *file);
int count_char(FILE *file);
FILE *open_file(const char *path,char *mode);
// TODO
// Define full path to text file here.
const char file_path[] = "";

int main() {
  // Some useful varuables.
  int n_words = 0, n_words_total = 0, n_chars = 0;
  
  //bool eof_reached = false;
  //char s[MAX_LINE_LENGTH];
  printf("Welcome to Text analysis program.\n");
  printf("Please insert the path to the file you want to use : ");
  char path[160];
  fgets(path,160,stdin);
  path[strcspn(path,"\n")]='\0';
  printf("File contents:\n");
  printf("-------------\n");
  FILE *test = open_file(path,"r");
  // TODO Call your functions to get the desired result.
  n_words_total = count_word(test);
  rewind(test);
  n_chars= count_char(test);
  printf("-------------\n");
  printf("Characters in file: %d\n", n_chars);
  printf("Words in file: %d\n", n_words_total);
  fclose(test);
  return 0;
}

// TODO Here you define your functions
FILE *open_file(const char *path,char *mode){
  FILE *file=fopen(path,mode);
  if(file==NULL){
    printf("Opening file FAILED ! ! !");
    exit(EXIT_FAILURE);
  }
  return file;
}
// Ett ord : vilken samling bokstäver som hlest, inklusiv sammanfogande ord, men inte siffror. 

int count_word(FILE *file){
  int cnt =0;
  char *ch;
  char text[MAX_LINE_LENGTH];
  while((ch=fgets(text,MAX_LINE_LENGTH,file))!=NULL){
    for(;*ch!='\0';ch++){
      if((isspace(*(ch+1))&&isalpha(*ch))||(*(ch+1)=='.'&&isalpha(*ch))){cnt++;}
    }
  }
  return cnt;
}

int count_char(FILE *file){
  char joint_word = '-';

  char text[MAX_LINE_LENGTH];
  int cnt=0;
  char *ch;
  while((ch=fgets(text,MAX_LINE_LENGTH,file))!=NULL){
    for(;*ch!='\0';ch++){
      if(*ch!='\n'){cnt++;}
    }
  }
  return cnt;
}
