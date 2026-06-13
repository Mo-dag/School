#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Initialise the random number generator
    srand((unsigned int)time(NULL));

    int dice;
    for(int i =0 ; i<5; i++){
        dice = rand()%6 +1;
        printf("%d ", dice);
    }
    
    // TODO
    
    return 0;
}
