#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
    srand((unsigned int) time(NULL));     // Initialize random number generator by reading system time
    int r = rand()%2;                       // Call rand() to get a large random number. 
    //Modulus operator n = q*d + r >> Modulus ger r. [n = talet vi delar] [q = kvoten av talet vi delar med modulus värde] [d = modulus värde] [resten]   
    (r == 0) ? printf("Result of coin tossing : head") : printf("Result of coin tossing : tail");
    // TODO 
	return 0;
}
