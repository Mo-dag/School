#include <stdio.h>
#include <stdbool.h>
int main()
{

    // write code here
    bool isRunning = true;
    float flyttal;
    while(isRunning){
        printf("Please insert a floating point less than or equal to 10\n");
        scanf("%f", &flyttal);
        if(flyttal <= 10)
        isRunning = false;
    }
    printf("%.2f", flyttal);
    
    
    
}
