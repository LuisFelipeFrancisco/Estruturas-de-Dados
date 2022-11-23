//STRUCT and DEFINE
#include <stdio.h> 
/*Defining a constant called alturamaxima, which is equal to 225.*/
#define alturamaxima 225

/*Creating a new type called pesoaltura, which is a struct with two ints.*/
/**
 * Pesoaltura is a type that contains two ints, one named peso and the other named altura.
 * @property {int} peso - weight
 * @property {int} altura - height
 */
typedef struct
{
    int peso; 
    int altura;
} pesoaltura;

int main()
{
    int n;
/* Creating two variables of type pesoaltura, which is a struct with two ints. */
    pesoaltura pessoa1, pessoa2;
/* Assigning a value to the variable peso, which is inside the struct. */
    pessoa1.peso = 80;
    pessoa2.peso = 90;
/* Assigning a value to the variable altura, which is inside the struct. */
    pessoa1.altura = 230;
    pessoa2.altura = 195;
/* Printing the values of the variables peso and altura, which are inside the struct. */
    printf("Pessoa 1:\nPeso: %i\nAltura: %i cm\n", pessoa1.peso, pessoa1.altura);
    printf("Pessoa 2:\nPeso: %i\nAltura: %i cm\n", pessoa2.peso, pessoa2.altura);
/* Printing the value of the constant alturamaxima. */
    printf("Altura maxima: %i cm\n", alturamaxima);
/* Checking if the value of the variable altura, which is inside the struct pessoa1, is greater than the value of the constant alturamaxima. */
    if (pessoa1.altura > alturamaxima)
    {
        printf("Pessoa 1 e maior que a altura maxima.\n");
    }
    else
    {
        printf("Pessoa 1 nao e maior que a altura maxima.\n");
    }
    if (pessoa2.altura > alturamaxima)
    {
        printf("Pessoa 2 e maior que a altura maxima.\n");
    }
    else
    {
        printf("Pessoa 2 nao e maior que a altura maxima.\n");
    }
return 0;
}