/*
 *     Assignment 1b, Bulls and cows
 *
 *     (Read ASSIGNMENT1b.pdf carefully before you start coding)
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// ----------- Declare functions used in main ----------

// Get input from player
int get_player_guess();
int get_digit_position(int number,int digit);
int guess_generator();
bool is_digit_in(int num,int digit);
void compare_user_answer(int guess, int answer, int *cows,int *bulls);
// TODO declare functions that are used in main 
// NOTE do not give any arguments to get_player_guess() function

//------------- Program starts here --------------------
int main() {
    
    srand((unsigned int) time(NULL));     // Init random number generator
    while(1){
    int answer = guess_generator();
    printf("answer is : %d\n",answer);  // TODO call get_random_digits to initiate the answer   
    // Hint print the answer to make it easier to debug

    printf("Welcome to Bulls and Cows\n");
    printf("Try to guess a 4 digit number with digits 1-9\n");
    printf("and no repeating digits (-1 to abort).\n\n");
    printf("Bulls = correct digit(s) in correct positions.\n");
    printf("Cows = correct digit(s).\n\n");

    bool aborted = false;
    int n_guess = 0;
    int guess;
    int bulls = 0;
    int cows = 0;
    int want_play=1;
    // ----- The game loop ------

    // TODO Use functions declared above (and more) to implement the game
    // TODO Try to sketch one round, then surround with a loop.
    // NOTE There should be no recursion in the main function
    while(!aborted) {
        
        guess  = get_player_guess();
        if(guess==-1){aborted=true;break;}
        n_guess++;
        compare_user_answer(guess,answer,&bulls,&cows);
        printf("There are %d bulls and %d cows\n", bulls,cows);
        if(bulls==4){
            printf("Done, number was %d you needed %d guesses\n",answer,n_guess);
            printf("Select 0 or 1 to quit game or to play again: ");
            scanf("%d",&want_play);
            if(want_play==0){aborted = true;}
            break;
        }
    }
    // --- End game loop --------

    if (aborted) {
        printf("Game aborted\n");
        return 0;
    }
    }
    // TODO Ask the player if they want to play again (by selecting either 0 or 1)

    return 0;
}

// ------- Function definitions --------------------------------
bool is_digit_in(int num,int digit){
    while(num>0){
        if(num%10==digit){return true;}
        num/=10;
    }
    return false;
}


int guess_generator(){
    int num=rand()%9+1;
    int nr_of_digits=1;
    while(nr_of_digits<4){
        int new_rand = rand()%9+1;
        if(!is_digit_in(num,new_rand)){
            num*=10;
            num+=new_rand;
            nr_of_digits++;
        }
    }
    return num;
}

// TODO Put function definitions from part 1a here

// TODO implement the function 'get_player_guess'
int get_player_guess(){
    int guess;
    printf("Guess > ");
    scanf("%d",&guess);
    return guess;
}

int get_digit_position(int num, int digit){
    int position=0;
    while(num>0){
        if(num%10==digit){
            return position;
        }
        position++;
        num/=10;
    }
    return -1;
}

void compare_user_answer(int guess,int answer,int *cows,int *bulls){
    *bulls = 0;
    *cows  = 0;
    
    int digit_position=0;
    while(guess>0){
        int compare = guess%10;
        if(is_digit_in(answer,compare)){
            int answer_position = get_digit_position(answer,compare);

            if(answer_position == digit_position){*bulls = *bulls+1;}

            else{*cows = *cows +1;}
        }
        guess/=10;
        digit_position++;
    }
}
