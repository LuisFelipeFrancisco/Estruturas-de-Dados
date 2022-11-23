/* 
a) Escreva uma instrução que declare uma matriz de Produto com 10 itens de produtos; 
b) Atribua os valores "Pé de Moleque", 13205 e R$0,20 aos membros da posição 0 
e os valores "Cocada Baiana", 15202 e R$0,50 aos membros da posição 1 da matriz anterior;
c) Faça as mudanças que forem necessárias para usar um ponteiro para Produto ao invés 
de uma matriz de Produtos. Faça a alocação de memória de forma que se possa 
armazenar 10 produtos na área de memória apontada por este ponteiro e refaça as 
atribuições da letra b;
d) Escreva as instruções para imprimir os campos que foram atribuídos na letra c.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    char nome[30]; // Nome do produto
    int codigo;    // Codigo do produto
    double preco;  // Preco do produto
} Produto;

void imprimir(Produto *prod){ // Imprime os produtos
    system("cls");
    printf("Lista de Produtos:\n");
    int i=0;
    for(i=0; i<10; i++){
        if (prod[i].codigo !=0)
        {
            printf("\nCodigo: %d",prod[i].codigo);
            printf("\nNome: %s", prod[i].nome);
            printf("\nPreco : R$ %.2f\n", prod[i].preco);
        }
    }
    system("pause");
    system("cls");    
}

int main()
{
    Produto *produtos; // Ponteiro para a matriz de produtos
    int i=0, op;
    printf("valor ptr antes da alocacao: %ld\n", produtos);
    produtos = (Produto *)malloc(10 * sizeof(Produto)); // Alocação de memória para a matriz de produtos
    printf("valor ptr depois da alocacao: %ld\n", produtos);
    for (int z = 0; z < 10; z++)
    {
        //zerar produtos.codigo
        produtos[z].codigo = 0;
    }

    strcpy(produtos[0].nome, "Pe de Moleque");
    produtos[0].codigo = 13205;
    produtos[0].preco = 0.20;
    strcpy(produtos[1].nome, "Cocada Baiana");
    produtos[1].codigo = 15202;
    produtos[1].preco = 0.50;

    do
    {
        printf("1 - Cadastro de Produtos:\n2 - Impressao de Produtos:\n3 - Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nDigite o codigo do produto: ");
            scanf("%d", &produtos[i].codigo);
            printf("\nDigite o nome do produto: ");
            fflush(stdin);
            fgets(produtos[i].nome, 30, stdin);
            printf("\nDigite o preco do produto: ");
            scanf("%lf", &produtos[i].preco);
            i++;
            break;
        case 2:
            imprimir(produtos);
            break;
        case 3:
            break;
        default:
            printf("\nOpcao invalida\n");
        }
    } while (op != 3);
    return 0;
}