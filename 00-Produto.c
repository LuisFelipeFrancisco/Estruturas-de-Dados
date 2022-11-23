#include <stdio.h>
#include <stdlib.h>



typedef struct tipo_produto {
    int codigo;                  /* Codigo do produto */
    double preco;                /* Preco do produto */
    struct tipo_produto *proximo;    /* ponteiro proximo -  Proximo elemento da lista encadeada de Produtos */
}  TProduto;


// Prototipo das funcoes para inserir e listar produtos 

void inserir(TProduto **cabeca); //cabeca = no inicial - ponteiro para ponteiro
void listar (TProduto *cabeca);

int main()
{
    TProduto *cabeca = NULL;  // ponteiro para a cabeca da lista
    TProduto *noatual;   // ponteiro a ser usado para percorrendo a lista no momento que eu inserir um novo produto       
    char q;    // caractere para receber a opcao que o usuario digitar                      
    do {
        printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos; \nS -> para sair \n:");
        scanf("%c", &q);     
        switch(q) {
            case 'i': case 'I': inserir(&cabeca); break;
            case 'l': case 'L': listar(cabeca); break;
            case 's': case 'S': break;
            default: printf("\n\n Opcao invalida"); //Excecao
        }
        fflush(stdin);   //limpar o buffer de entrada
    } while ((q != 's') && (q != 'S') );


// memoria para alocar os elementos da lista

    noatual = cabeca; //no inicial (anterior)
    while (noatual != NULL) //noo chegou no final da lista
    {
        cabeca = noatual->proximo;
        free(noatual); // instrucao que indica que eu irei "reciclar" a struct para inserir um novo produto
        noatual = cabeca; 
    }
}



void listar (TProduto *noatual)
{
    int i=0;
    while( noatual != NULL)    
    {
        i++;
        printf("\n\nProduto numero %d\nCodigo: %d \nPreco:R$%.2lf", i, noatual->codigo, noatual->preco);
        noatual = noatual->proximo;     
    }
}



void inserir (TProduto **cabeca) //no inicial - qd eu tenho 2 asteriscos significa que eu tenho um ponteiro para ponteiro
{
    TProduto *noatual, *novono;
    int cod;
    double preco;
    printf("\n Codigo do novo produto: ");
    scanf("%d", &cod);
    printf("\n Preco do produto:R$");
    scanf("%lf", &preco);
    if (*cabeca == NULL)   //se ainda noo existe nenhum produto na lista 
    {

        *cabeca = (TProduto *) malloc(sizeof(TProduto)); //aloca memoria para o novo no 
        (*cabeca)->codigo = cod;
        (*cabeca)->preco = preco;
        (*cabeca)->proximo = NULL;
    }
    else //se ja existem elementos na lista, deve percorre-la ate o final e inserir o novo produto
    {

        noatual = *cabeca;
        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    // no atual aponta para o ultimo no 
        novono = (TProduto *) malloc(sizeof(TProduto)); //aloca memoria para o novo no 
        novono->codigo = cod;
        novono->preco = preco;
        novono->proximo = NULL;
        noatual->proximo = novono;     // faz o ultimo no apontar para o novo no 
    }
}
