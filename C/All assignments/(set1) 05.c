#include <stdio.h>

int main() {
    int num=0;
    int sum=0;
    // TODO
    printf("Please insert an integer number : ");
    scanf("%i", &num);
    while(num >=3){
        sum +=3;
        num -=3;
        printf("%d ",sum);
    }
    return 0;

}
