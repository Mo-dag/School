#include <stdio.h>

int main()
{
	int z = 0;
    
    while (z < 11) {
        printf("z = %d\n", z);
        z = z + 1;
    }
    // Det är dåligt att ändra till z = z - 1 eftersom loopen kommer at köras för evigt.
}
