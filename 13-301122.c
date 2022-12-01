/*Cadastre 5 numeros em uma fila dinamica e mais 5 em uma pilha dinamica. Em seguida, mostre
tres relatorios.
I. Os numeros que estao nas duas estruturas.
II. Os que estao na fila.
III. Os que estao na pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*registro que reprensentar? cada elemento da pilha*/
struct Elemento_pilha
{
	int num;
	struct Elemento_pilha *prox;
};
typedef struct Elemento_pilha Elemento_pilha;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha
{
	struct Elemento_pilha *topo; /*aponta para o elemento qu esta Elemento topo da pilha*/
};
typedef struct Pilha Pilha;

/*ponteiro auxiliar*/
Elemento_pilha *aux;

/*registro que reprensentar? cada elemento da pilha*/
struct Elemento_fila
{
	int num;
	struct Elemento_fila *prox;
};
typedef struct Elemento_fila Elemento_fila;

/*registro do tipo Lista contento dois ponteiros do tipo n? para controlar a fila*/
struct Fila
{
	struct Elemento_fila *inicio; /*aponta para o elemento do in?cio da fila*/
	struct Elemento_fila *fim;	  /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

/*ponteiro auxiliar*/
Elemento_fila *aux2;

Pilha *cria_pilha()
{
	/*alocacao do ponteiro pi para controlar a pilha*/
	Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
	if (pi != NULL)
	{
		pi->topo = NULL; /*a pilha inicia-se vazia, portanto seu topo ? igual a NULL*/
	}
	return pi;
}

Fila *cria_fila()
{
	/*alocacao do ponteiro li para controlar a lista*/
	Fila *fi = (Fila *)malloc(sizeof(Fila));
	if (fi != NULL)
	{
		/*a fila inicia-se vazia, portanto inicio e fim sao iguais a NULL*/
		fi->fim = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

/*todo elemento sera inserido no topo da pilha*/
void insere_elemento_pilha(Pilha *pi)
{
	/*a cada insercao alocamos dinamicamente um espaco para um novo elemento*/
	Elemento_pilha *novo = (Elemento_pilha *)malloc(sizeof(Elemento_pilha));
	printf("\nDigite o numero a ser inserido na pilha: ");
	scanf("%d", &novo->num);
	/*como o numero inserido sera o novo topo, ele apontara para o topo atual que sera o segundo elemento da pilha*/
	novo->prox = pi->topo;
	/*topo aponta para o endereco de novo*/
	pi->topo = novo;
	printf("\nNumero inserido na pilha!\n");
	getch();
}

void insere_elemento_fila(Fila *fi)
{
	/*a cada insercao alocamos dinamicamente um espaco para um novo elemento*/
	Elemento_fila *novo = (Elemento_fila *)malloc(sizeof(Elemento_fila));
	printf("\nDigite o numero a ser inserido na fila: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido sera o primeiro e o ultimo */
	if (fi->inicio == NULL)
	{
		fi->inicio = novo;
		fi->fim = novo;
		/*caso a pilha ja contenha algum elemento, o novo elemento sera sempre inserido no fim da fila*/
	}
	else
	{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNumero inserido na fila!\n");
	getch();
}

/* funcao verifica os numeros que estao nas duas estruturas
cada elemento da pilha eh comparado os todos elementos da fila verificando a igualdade*/
void consulta_iguais(Pilha *pi, Fila *fi)
{
	int achou;
	aux = pi->topo;
	/*looping da pilha*/
	do
	{
		achou = 0;
		aux2 = fi->inicio;
		/*looping da fila*/
		do
		{
			if (aux2->num == aux->num)
				achou++;
			aux2 = aux2->prox;
		} while (aux2 != NULL);

		if (achou > 0)
			printf(" %d", aux->num);
		aux = aux->prox;
	} while (aux != NULL);
	getch();
}
/* funcao verifica os numeros que estao somente na fila
cada elemento da fila eh comparado os todos elementos da pilha*/
void consulta_fila(Pilha *pi, Fila *fi)
{
	int achou;
	aux2 = fi->inicio;
	/*looping da fila*/
	do
	{
		achou = 0;
		aux = pi->topo;
		/*looping da pilha*/
		do
		{
			if (aux2->num == aux->num)
				achou++;
			aux = aux->prox;
		} while (aux != NULL);
		if (achou == 0)
			printf(" %d", aux2->num);
		aux2 = aux2->prox;
	} while (aux2 != NULL);
	getch();
}
/* funcao verifica os numeros que estao somente na pilha
cada elemento da pilha eh comparado os todos elementos da fila*/
void consulta_pilha(Pilha *pi, Fila *fi)
{
	int achou;
	aux = pi->topo;
	/*looping da pilha*/
	do
	{
		achou = 0;
		aux2 = fi->inicio;
		/*looping da fila*/
		do
		{
			if (aux2->num == aux->num)
				achou++;
			aux2 = aux2->prox;
		} while (aux2 != NULL);
		if (achou == 0)
			printf(" %d", aux->num);
		aux = aux->prox;
	} while (aux != NULL);
	getch();
}

/*a pilha sera esvaziada e o espaco ocupado por ela sera desalocado*/
void esvazia_pilha(Pilha *pi)
{
	if (pi->topo == NULL)
	{
		printf("\nPilha Vazia!!");
	}
	else
	{
		aux = pi->topo;
		do
		{
			pi->topo = pi->topo->prox;
			free(aux);
			aux = pi->topo;
		} while (aux != NULL);
		printf("\nPilha Esvaziada!!");
	}
	getch();
}
/*a fila sera esvaziada e o espaco ocupado por ela sera desalocado*/
void esvazia_fila(Fila *fi)
{
	if (fi->inicio == NULL)
	{
		printf("\nFila Vazia!!");
	}
	else
	{
		aux2 = fi->inicio;
		do
		{
			fi->inicio = fi->inicio->prox;
			free(aux2);
			aux2 = fi->inicio;
		} while (aux2 != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int main()
{
	int i;
	Pilha *pi = cria_pilha();
	Fila *fi = cria_fila();
	/*inserindo elementos na pilha*/
	for (i = 1; i <= 5; i++)
	{
		insere_elemento_pilha(pi);
		system("CLS");
	}
	/*inserindo elementos na fila*/
	for (i = 1; i <= 5; i++)
	{
		insere_elemento_fila(fi);
		system("CLS");
	}
	/*relatorio 1*/
	printf("\nNumeros que estao nas duas estruturas\n");
	consulta_iguais(pi, fi);
	/*relatorio 2*/
	printf("\nNumeros que estao somente na fila\n");
	consulta_fila(pi, fi);
	/*relatorio 3*/
	printf("\nNumeros que estao somente na pilha\n");

	consulta_pilha(pi, fi);

	/*esvaziando pilha e fila utilizadas*/
	esvazia_fila(fi);
	esvazia_pilha(pi);
	return 0;
}

/*
O que é fila?
Fila é uma estrutura de dados que segue o princípio FIFO (First In First Out), ou seja, o primeiro a entrar é o primeiro a sair. Quando um elemento é inserido na fila, ele é colocado no final da mesma, e o primeiro elemento a ser inserido é o primeiro a ser removido. Em outras palavras, a fila é uma lista linear, na qual as operações de inserção são realizadas no final da estrutura e as operações de remoção são realizadas no início da estrutura.

O que é pilha?
Pilha é uma estrutura de dados que segue o princípio LIFO (Last In First Out), ou seja, o último a entrar é o primeiro a sair. Quando um elemento é inserido na pilha, ele é colocado no topo da mesma, e o primeiro elemento a ser inserido é o último a ser removido. Em outras palavras, a pilha é uma lista linear, na qual as operações de inserção e remoção são realizadas no mesmo ponto da estrutura.

Como a fila e a pilha são estruturas de dados lineares, elas são organizadas de forma sequencial, ou seja, cada elemento da fila ou da pilha possui um endereço de memória que é sequencial ao endereço do elemento anterior. Para facilitar o entendimento, podemos imaginar que a fila e a pilha são listas de compras, onde cada elemento é um item da lista de compras. Imagine que você está na fila do supermercado e que a cada 10 segundos um cliente é atendido. Neste caso, o primeiro cliente que chegou na fila será o primeiro a ser atendido. Agora imagine que você está na fila do supermercado e que a cada 10 segundos um cliente é atendido, mas que o último cliente a entrar na fila é o primeiro a ser atendido. Neste caso, o último cliente que chegou na fila será o primeiro a ser atendido. Veja que a diferença entre a fila e a pilha é que na fila o primeiro a entrar é o primeiro a sair, enquanto na pilha o último a entrar é o primeiro a sair.

Filas e pilhas

Filas e pilhas são estruturas usualmente implementadas através de listas, retringindo a política de manipulação dos elementos da lista.

Uma fila (queue) tipicamente estabelece uma política FIFO -- first in, first out -- de acesso aos dados. Em outras palavras, a ordem estabelecida na lista é a ordem de inserção. No momento de retirar um nó da lista, o nó mais antigo (o primeiro que entrou) é o primeiro a ser retirado.

Como as políticas de inserção e remoção são pré-definidas, para esse tipo de estrutura as operações são descritas de forma genérica, INSERT e REMOVE. Há duas possibilidades para implementar as operações de uma fila usando os procedimentos descritos para listas:

    1- restringir a inserção ao procedimento INSERT e a remoção ao procedimento REMOVELAST, ou

    2- restringir a inserção ao procedimento APPEND e a remoção ao procedimento REMOVEFIRST.

Uma estrutura de pilha (stack), por outro lado, estabelece uma política LIFO -- last in, first out. Uma estrutura de pilha também oferece basicamente duas operações de manipulação, PUSH, para inserção no topo da pilha, e POP, para retirada do topo da pilha.

Embora também fosse possível implementar uma pilha através de lista usando os procedimentos que acrescentam e removem os nós no final da lista, por razões óbvias de desempenho uma pilha é usualmente implementada usando os procedimentos INSERT e REMOVEFIRST, que não requerem a varredura da lista para estabelecer essa política de manipulação de dados. 
*/
