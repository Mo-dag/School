#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

    int table = 0;
    int answer; 
    int n_answers = 0;  //no. of answers.
    int correct = 0;
    int quest;          //rand number.


    printf("Practise multiplication!\n");
    printf("Select table (2-9) to train (-1 to quit): ");
    scanf("%d", &table);
    if(table == -1){return 0;}
    srand((unsigned int) time(NULL));  // Init random generator
    
    while(1){
        // TODO: Make it work once, then surround with loop!
        quest = rand()%9+1;
        int correct_answer = quest * table;

        printf("%d * %d = ", quest, table);
        scanf("%d", &answer);

        if(answer == -1){break;}
        if(answer == correct_answer){
            printf("Correct !\n");
            correct ++;
        }
        else{printf("Sorry, answer was %d!\n", correct_answer) ;}
        n_answers ++;
    }

    printf("Number of questions = %d. Number of correct = %d \n", n_answers, correct);

    return 0;
}

