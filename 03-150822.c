//PONTEIRO E MALLOC
#include <stdio.h>
#include <malloc.h> 

int main()
{
    int *x = (int *)malloc(sizeof(int)); // x is a pointer to an int
/* Assigning the value 20 to the memory address that x points to. */
    *x = 20; // changes the value of x
/* Assigning the size of an int to z. */
    int z = sizeof(int); // z is an int
    printf("%i\n", *x); // prints 20
    printf("%i\n", z); // prints 4
    printf("%i\n", &x); // prints the address of x
    printf("%i\n", &z); // prints the address of z
    return 0;
}