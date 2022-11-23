/* It takes a string and a mask, and returns a string with the mask applied to it */
#include <stdio.h>  //biblioteca de entrada e saida de dados
#include <conio.h>  //para usar o getch()
#include <string.h> //para usar o strcpy()

void mascara(char *frase, char formato[]) // formato de mascara
{
    char cpfaux[15]; 
    int i = 0; 

    while (*frase)
    {
        if (formato[i] != '#') 
        {
            cpfaux[i] = formato[i];
            i++;
        }
        else
        {
            cpfaux[i] = *frase;
            frase++;
            i++;
        }
    }
    cpfaux[i] = 0;

    printf("CPF COM MASCARA APLICADA\n%s", cpfaux); 
    getch();
}
int main()
{
    char frase[11]; 
    printf("DIGITE SEU CPF SEM PONTOS E HIFEN:\n");
    scanf("%11s", frase); // le apenas 11 primeiros caracteres
    mascara(frase, "###.###.###-##"); // formato de mascara
}