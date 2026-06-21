/*
 *  The Nim game, player vs computer
 *  See: https://en.wikipedia.org/wiki/Nim
 *
 *  Samples:
 */

#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PILE_SIZE 13


// Get player choice. Force player to enter a number in range 1-3
int get_player_choice(int pile);

// Get computer choice. Add some simple AI. I.e if 2 coins left
// computer should pick one, ... make computer a bit smarter than this.
int get_computer_choice(int pile);

// After game print a message who won
void game_over_msg(bool human_is_player);


/*
 *    The game
 *
 *    It is OK to allow human to always start,
 *    but make a random choice between human and player if you manage
 */
int main() {
    srand((unsigned int) time(NULL));

    int pile = PILE_SIZE;
    int n_coins;
    bool human_is_player = true;

    printf("Welcome to NIM\n");
    human_is_player = rand()%2;

    while(pile>0){

        if(human_is_player){
            printf("There's %d coins in the pile\n", pile);

            n_coins = get_player_choice(pile);
            pile -= n_coins;
            printf("There's %d coins in the pile\n", pile);
            human_is_player = 0;
        }
        else if(!human_is_player){

            n_coins = get_computer_choice(pile);
            pile -= n_coins;
            human_is_player = 1;
        }

    }

    // TODO: Make it work once, then surround with loop i.e. the game loop
    
    
    

    game_over_msg(human_is_player);
    return 0;
}


// ------- Methods below this ------------------------

int get_computer_choice(int pile) {
    // TODO Implement and then use in the game
    while(1){
        int n_coins = rand()%3 +1;
        if(n_coins <= pile){
            printf("Computer took %d \n", n_coins);
            return n_coins;
        }
    }
}

int get_player_choice(int pile) {
    // TODO Implement and then use in the game
    int n_coins = 0;

    while(1){
        printf("Pick coins ");
        scanf("%d", &n_coins);

        if(n_coins >0 && n_coins <= 3 && n_coins <= pile){
            printf("player took %d \n", n_coins);
            break;
        }
    }
    return n_coins;
}

void game_over_msg(bool human_is_player) {
    printf("Game over.\nWinner is: ");
    if (human_is_player) {
        printf("Human\n");
    } else {
        printf("Computer\n");
    }
}






