/* Crie uma struct para descrever restaurantes. 
Os campos devem armazenar o nome do restaurante, o endereço, 
o tipo de comida (brasileira, chinesa, francesa, italiana, japonesa etc) 
e uma nota para a cozinha. Nota maxima 5, minima 0.
Crie uma lista encadeada com esta struct e escreva um programa que:
a) Insira um novo restaurante na lista;
b) Liste todos os restaurantes na tela;
e) Liste os restaurantes em ordem decrescente do melhor para o pior. 5 ao 0
f) Liste todos os restaurantes com determinado tipo de comida, determinado pelo usuário.
extra: 
ordem alfabetica - ok
alterar - ok
excluir - ok
Autor: Luis Felipe Francisco Fermino Ferreira - 23/11/22.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct restaurants{
    char name[20];
    char address[50];
    char type[20];
    int rating;
    struct restaurants *next;
} Cadrestaurants;

void insert(Cadrestaurants **head);
void list(Cadrestaurants *head);
void listrating(Cadrestaurants *head);
void listtype(Cadrestaurants *head);
void listalpha(Cadrestaurants *head);
void change(Cadrestaurants *head);
void delete(Cadrestaurants **head);

int main(){
        system("cls");
    Cadrestaurants *head = NULL;
    Cadrestaurants *newcad = NULL;
    int rating;
    char type[20];
    int op;
    do{
        printf("Digite a opcao desejada\n");
        printf("1 - Cadastrar novo restaurante.\n");
        printf("2 - Listar restaurantes cadastradros.\n");
        printf("3 - Listar por estrelas.\n");
        printf("4 - Listar por tipo de culinaria.\n");
        printf("5 - Listar em ordem alfabetica.\n");
        printf("6 - Alterar um cadastro.\n");
        printf("7 - Excluir um cadastro.\n");
        printf("8 - Sair.\n");
        scanf("%d", &op);
        switch(op){
            case 1: insert(&head); break;
            case 2: list(head); break;
            case 3: listrating(head); break;
            case 4: listtype(head); break;
            case 5: listalpha(head); break;
            case 6: change(head); break;
            case 7: delete(&head); break;
            case 8: 
                printf("Saindo...\n");
                Sleep(1000);
                break;
            default: printf("Opcao invalida!\n");
        }
        fflush(stdin);
    }while(op != 8);
    newcad = head;
    while(newcad != NULL){
        head = newcad->next;
        free(newcad);
        newcad = head;
    }
}
//inserting new restaurants
void insert(Cadrestaurants **head){
    system("cls");
    Cadrestaurants *newcad;
    newcad = (Cadrestaurants*)malloc(sizeof(Cadrestaurants));
    printf("Cadastrando um novo restaurante:\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(newcad->name, 20, stdin);
    printf("Endereco: ");
    fflush(stdin);
    fgets(newcad->address, 50, stdin);
    printf("Tipo de culinaria: ");
    fflush(stdin);
    fgets(newcad->type, 20, stdin);
    do {
        printf("Estrelas:\n");
        printf("0 - Pessimo\n");
        printf("1 - Ruim\n");
        printf("2 - Medio\n");
        printf("3 - Bom\n");
        printf("4 - Otimo\n");
        printf("5 - Excelente\n");
        scanf("%d", &newcad->rating);
    } while (newcad->rating < 0 || newcad->rating > 5);
    newcad->next = *head;
    *head = newcad;
    system("pause");
    system("cls");
}
//listing all restaurants
void list(Cadrestaurants *head){
    system("cls");
    Cadrestaurants *newcad;
    newcad = head;
    while(newcad != NULL){
        printf("--------------------------------------------------\n");
        printf("Nome: %s", newcad->name);
        printf("End.: %s", newcad->address);
        printf("Culinaria: %s", newcad->type);
        printf("Estrelas: %d", newcad->rating);
        printf("\n--------------------------------------------------\n");
        newcad = newcad->next;
    }
    system("pause");
    system("cls");
}
//listing filtering by higher rating to lower rating.
void listrating(Cadrestaurants *head){
    system("cls");
    Cadrestaurants *newcad;
    newcad = head;
    int i;
    for(i = 5; i >= 0; i--){
        while(newcad != NULL){
            if(newcad->rating == i){
                printf("--------------------------------------------------\n");
                printf("Nome: %s", newcad->name);
                printf("End.: %s", newcad->address);
                printf("Culinaria: %s", newcad->type);
                printf("Estrelas: %d", newcad->rating);
                printf("\n--------------------------------------------------\n");
            }
            newcad = newcad->next;
        }
        newcad = head;
    }
    system("pause");
    system("cls");
}
//listing filtering by type
void listtype(Cadrestaurants *head){
    system("cls");
    Cadrestaurants *newcad;
    char type[20];
    printf("Tipo De Culinaria: ");
    fflush(stdin);
    fgets(type, 20, stdin);
    newcad = head;
    while(newcad != NULL){
        if(strcmp(newcad->type, type) == 0){
            printf("--------------------------------------------------\n");
            printf("Nome: %s", newcad->name);
            printf("End.: %s", newcad->address);
            printf("Culinaria: %s", newcad->type);
            printf("Estrelas: %d", newcad->rating);
            printf("\n--------------------------------------------------\n");
        }
        newcad = newcad->next;
    }
    system("pause");
    system("cls");
}
//listing filtering by alphabetical order
void listalpha(Cadrestaurants *head){
    //linpar console
    system("cls");
    //variavel auxiliar
    Cadrestaurants *aux = head;
    //variavel para armazenar o nome do restaurante
    char name[20];
    //variavel para armazenar o endereço do restaurante
    char adress[50];
    //variavel para armazenar o tipo de comida
    char food[20];
    //variavel para armazenar a nota do restaurante
    int note;
    //variavel para armazenar o proximo restaurante
    Cadrestaurants *next;
    //loop para percorrer a lista
    while(aux!=NULL){
        next = aux->next;
        //loop para percorrer a lista
        while(next!=NULL){
            //condicional para ordenar por nome
            if(strcmp(aux->name, next->name)>0){
                //atribuição dos valores
                strcpy(name, aux->name);
                strcpy(adress, aux->address);
                strcpy(food, aux->type);
                note = aux->rating;
                //atribuição dos valores
                strcpy(aux->name, next->name);
                strcpy(aux->address, next->address);
                strcpy(aux->type, next->type);
                aux->rating = next->rating;
                //atribuição dos valores
                strcpy(next->name, name);
                strcpy(next->address, adress);
                strcpy(next->type, food);
                next->rating = note;
            }
            //atribuição do proximo restaurante
            next = next->next;
        }
        //atribuição do proximo restaurante
        aux = aux->next;
    }
    //variavel auxiliar
    aux = head;
    //loop para percorrer a lista
    while(aux!=NULL){
        //impressão dos dados
        printf("--------------------------------------------------\n");
        printf("Nome: %s", aux->name);
        printf("End.: %s", aux->address);
        printf("Culinaria: %s", aux->type);
        printf("Estrelas: %d", aux->rating);
        printf("\n--------------------------------------------------\n");
        //atribuição do proximo restaurante
        aux = aux->next;
    }
    system("pause");
    system("cls");
}
//Changing a restaurant
void change(Cadrestaurants *head){
    system("cls");
    Cadrestaurants *newcad;
    char name[20];
    int i;
    printf("Nome do restaurante: ");
    fflush(stdin);
    fgets(name, 20, stdin);
    newcad = head;
    while(newcad != NULL){
        if(strcmp(newcad->name, name) == 0){
            printf("--------------------------------------------------\n");
            printf("Nome: %s", newcad->name);
            printf("End.: %s", newcad->address);
            printf("Culinaria: %s", newcad->type);
            printf("Estrelas: %d", newcad->rating);
            printf("\n--------------------------------------------------\n");
            printf("Novo nome: ");
            fflush(stdin);
            fgets(newcad->name, 20, stdin);
            printf("Novo endereco: ");
            fflush(stdin);
            fgets(newcad->address, 50, stdin);
            printf("Novo tipo de culinaria: ");
            fflush(stdin);
            fgets(newcad->type, 20, stdin);
            do {
                printf("Novas estrelas:\n");
                printf("0 - Pessimo\n");
                printf("1 - Ruim\n");
                printf("2 - Medio\n");
                printf("3 - Bom\n");
                printf("4 - Otimo\n");
                printf("5 - Excelente\n");
                scanf("%d", &newcad->rating);
            } while (newcad->rating < 0 || newcad->rating > 5);
            system("pause");
            system("cls");
            return;
        }
        newcad = newcad->next;
    }
    printf("Restaurante nao encontrado!\n");
    system("pause");
    system("cls");
}

//Delete a restaurant
void delete(Cadrestaurants **head){
    system("cls");
    Cadrestaurants *newcad;
    Cadrestaurants *aux;
    char name[20];
    printf("Nome do restaurante: ");
    fflush(stdin);
    fgets(name, 20, stdin);
    newcad = *head;
    if(strcmp(newcad->name, name) == 0){
        *head = newcad->next;
        free(newcad);
        printf("Restaurante excluido com sucesso!\n");
        system("pause");
        system("cls");
        return;
    }
    while(newcad != NULL){
        if(strcmp(newcad->name, name) == 0){
            aux->next = newcad->next;
            free(newcad);
            printf("Restaurante excluido com sucesso!\n");
            system("pause");
            system("cls");
            return;
        }
        aux = newcad;
        newcad = newcad->next;
    }
    printf("Restaurante nao encontrado!\n");
    system("pause");
    system("cls");
}
