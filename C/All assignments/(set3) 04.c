#include <stdio.h>

int main() {
    /*
    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int no_alpha = sizeof(alpha)/sizeof(alpha[0]);
    //TODO print the alphabet in two rows
    for(int i=0;i<no_alpha;i++){
        printf("%c ", alpha[i]);
        if(i == 12){
            printf("\n");
        }
    }
    // FEL ! 
    */
   // Jag måste använda en enda CHAR variable, två nästed for loops och Print statment. 
    

   char alpha = 'a';

   for(int i=0;i<2;i++){

    for(int j=0;j<13;j++){
        printf("%c ", alpha);
        alpha++;
    }
    printf("\n");
   }
    return 0;
}

