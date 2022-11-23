#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_produto {
    int codigo;                  /* Codigo do produto */
    double preco;                /* Preco do produto */
    struct tipo_produto *proximo;    /* ponteiro próximo -  Proximo elemento da lista encadeada de Produtos */
}  TProduto;

// Protótipo das funções para inserir e listar produtos 

void inserir(TProduto **noinicial); //cabeça = nó inicial - ponteiro para ponteiro
void listar (TProduto *noinicial);

int main()
{
    TProduto *noinicial = NULL;  // ponteiro para a cabeça da lista
    TProduto *noatual;   // ponteiro a ser usado para percorrendo a lista no momento que eu inserir um novo produto       
    char q;    // caractere para receber a opção que o usuário irá digitar                      
    do {
        printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos; \nS -> para sair \n:");
        scanf("%c", &q);     
        switch(q) {
            case 'i': case 'I': inserir(&noinicial); break;
            case 'l': case 'L': listar(noinicial); break;
            case 's': case 'S': break;
            default: printf("\n\n Opcao invalida"); //exceção
        }
        fflush(stdin);   //limpar o buffer de entrada
    } while ((q != 's') && (q != 'S') );

// memoria para alocar os elementos da lista

    noatual = noinicial; //no inicial (anterior)
    while (noatual != NULL) //não chegou no final da lista
    {
        noinicial = noatual->proximo;
        free(noatual); // instrução que indica que eu irei "reciclar" a struct para inserir um novo produto
        noatual = noinicial; 
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

void inserir (TProduto **noinicial) //no inicial - qd eu tenho 2 asteriscos significa que eu tenho um ponteiro para ponteiro
{
    TProduto *noatual, *novono;
    int cod;
    double preco;
    printf("\n Codigo do novo produto: ");
    scanf("%d", &cod);
    printf("\n Preco do produto:R$");
    scanf("%lf", &preco);
    if (*noinicial == NULL)   //se ainda não existe nenhum produto na lista 
    {

        *noinicial = (TProduto *) malloc(sizeof(TProduto)); //aloca memoria para o novo nó 
        (*noinicial)->codigo = cod;
        (*noinicial)->preco = preco;
        (*noinicial)->proximo = NULL;
    }
    else //se já existem elementos na lista, deve percorre-la até o final e inserir o novo produto
    {

        noatual = *noinicial;
        while(noatual->proximo != NULL)
            noatual = noatual->proximo;    // nó atual aponta para o último nó 
        novono = (TProduto *) malloc(sizeof(TProduto)); //aloca memória para o novo nó 
        novono->codigo = cod;
        novono->preco = preco;
        novono->proximo = NULL;
        noatual->proximo = novono;     // faz o ultimo nó apontar para o novo nó 
    }
}