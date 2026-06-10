#include <stdio.h>

int main()
{
    int a;
    printf("Select a positive integer to start and negative to end: ");
    scanf("%d", &a);
    
    if (a>0)
    {
        printf("Starting ...\n");
    }
    else
    {
        printf("Ending ...\n");
    }
}
