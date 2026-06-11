#include <stdio.h>

int main()
{
    int a;
    int b;
    printf("Insert a: \n");
    scanf("%d", &a);
    printf("Insert b: \n");
    scanf("%d", &b);
    if(a==b){printf("a is equal to b");return 0;}
    (a > b)? printf("a is greater than b") : printf("b is greater than a");
    return 0;
    // write code here
}
