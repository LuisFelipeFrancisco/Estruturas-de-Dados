// STRUCT, PONTEIRO E MALLOC
#include<stdio.h>
#include<malloc.h>
#define alturamaxima 225

typedef struct
{
    int peso;
    int altura;
} pesoaltura;

int main(){
    pesoaltura* pessoa1 = (pesoaltura*) malloc(sizeof(pesoaltura));
    pessoa1->peso = 80;
    pessoa1->altura = 195;
    printf("Pessoa 1:\nPeso: %i\nAltura: %i\n", pessoa1->peso, pessoa1->altura);
    if (pessoa1->altura > alturamaxima)
    {
        printf("Pessoa 1 e maior que a altura maxima.\n");
    }
    else
    {
        printf("Pessoa 1 nao e maior que a altura maxima.\n");
    }
}