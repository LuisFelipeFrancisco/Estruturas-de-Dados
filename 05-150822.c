//STRUCT

#include<stdio.h> //printf scanf 
#include<stdlib.h> //malloc free exit system 
#include<string.h> //strlen strcpy strcat strcmp 
#include<locale.h> //setlocale 
typedef struct
{
    int codigo;
    char nome[200];
    float nota;
} aluno;

aluno aluno_especial;

int main()
{
    setlocale(LC_ALL, "Portuguese"); //seta a linguagem para portugues
    aluno_especial.codigo = 37; //seta o codigo do aluno
    strcpy (aluno_especial.nome, "Luis Felipe"); //seta o nome do aluno
    aluno_especial.nota = 9.5; //seta a nota do aluno
    printf("Codigo: %i\nNome: %s\nNota: %.2f\n", aluno_especial.codigo, aluno_especial.nome, aluno_especial.nota);
    return 0;
}