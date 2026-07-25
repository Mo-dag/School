// Implement pseudocode here
#include <stdio.h>




int main(void){

    int a=0;
    int b=1;

    printf("%d,%d,",a,b);

    for(int i=0;i<15;i++){
        int t=a+b;
        a=b;
        b=t;
        printf("%d,",t);
    }
    printf("\n");



    return 0;
}
