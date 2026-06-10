#include <stdio.h>

int main()
{
    int a;
    printf("Select a positive or negative start number: ");
    scanf("%d", &a);
    
    int i = a;  
    
    while (i != 0) {
        printf("%d\n", i);
        if (a > 0){
            i = i - 1;
        } else {
            i = i + 1;
        }
    }
    printf("%d\n", i);
}
// Om jag anger 0 som värde för a, kommer programmet att skriva ut : 0 
