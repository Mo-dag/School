#include <stdio.h>
int main() {
    
    // TODO Add variables
    int input =0;
    float sum=0;
    int loops=0;
    float avg=0;
    printf("Calculate sum and average (-1 to quit)\n");

    // TODO 
    while(1){
        scanf("%d", &input);
        if(input <0){break;}
        sum += input;
        loops ++;
    }
    avg = sum/loops;
    printf("Sum = %.6f Avg = %.6f", sum , avg);
	return 0;
}
