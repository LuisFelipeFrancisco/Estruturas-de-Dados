//PONTEIRO
#include<stdio.h>

int main(){
    int x = 25; // x is a pointer to an int
    int *y = &x; // y is a pointer to an int
    printf("Valor de x: %i\n", x); // prints 25
    printf("Valor de y: %i\n", *y); // prints 25
    printf("Endereco de x: %i\n", &x); // prints address of x
    printf("Endereco de y: %i\n", &y); // prints address of y
    printf("Mudando o valor de x usando y\n");
    *y = 30; // changes the value of x
    printf("Valor de x: %i\n", x); // prints 30
    printf("Valor de y: %i\n", *y); // prints 30
    printf("Endereco de x: %i\n", &x); // prints address of x
    printf("Endereco de y: %i\n", &y); // prints address of y
    return 0;

}