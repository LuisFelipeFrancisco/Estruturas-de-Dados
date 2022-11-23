/* DESENVOLVA UM PROGRAMA PARA VENDAS DE PASSAGENS DE ÔNIBUS.
DEFINA UMA STRUCT, CRIE O MENU DE OPÇÕES E TODAS AS FUNÇÕES NECESSÁRIAS PARA MANIPULAR O STRUCT.
1 - Selecao de destinos com valores pre definidos;
2 - Cadastro de passageiro (i++)
    nome, CPF, data de partida, data de volta;
Consulta de passageiro
    passagens cadastradas; -> selecao da passagem a ser consultada;
        destino, valor, nome, CPF, data de partida, data de volta;
3  -Sair do programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct
{
    char nome[80];
    char CPF[15];
    char destino[50];
    float valor;
    char dataIda[11];
    char dataVolta[11];
} passagem;
void mascara(char *frase, char formato[]) // formato de mascara
{
    char cpfaux[14]; // cpf auxiliar
    int i = 0;       // contador

    while (*frase) // enquanto o ponteiro não chegar no final da string
    {
        if (formato[i] != '#') // se o formato não for #
        {
            cpfaux[i] = formato[i]; // copia o formato para o cpfaux
            i++;                    // incrementa o contador
        }
        else // se o formato for #
        {
            cpfaux[i] = *frase; // copia o caracter da string para o cpfaux
            frase++;            // incrementa o ponteiro
            i++;                // incrementa o contador
        }
    }
    cpfaux[i] = 0; // finaliza o cpfaux

    printf("CPF: %s\n", cpfaux); // imprime o cpfaux
}

int main()
{
    passagem ticket[100];
    /*zerar vetor ticket para nao ter problemas com lixo de memoria*/
    int z = 0;
    for (z = 0; z < 100; z++)
    {
        ticket[z].nome[0] = '\0';
        ticket[z].CPF[0] = '\0';
        ticket[z].destino[0] = '\0';
        ticket[z].valor = 0;
        ticket[z].dataIda[0] = '\0';
        ticket[z].dataVolta[0] = '\0';
    }
    int i = 0, opcao;
    char cpf1[14];
    do
    {
        printf("============== Viacao FATEC ==============\n");
        printf("1 - Cadastrar Passagem\n2 - Consultar Passagem\n3 - Sair\n");
        printf("==========================================\n");
        scanf("%i", &opcao);
        switch (opcao)
        {
        case 1:
            i++; // cria nova passagem
            system("cls");
            printf("============== Viacao FATEC ==============\n");
            printf("=== Escolha seu Destino ======== Valor ===\n"); // menu de destinos e valores
            printf("1 - Sao Paulo, SP. -------------- R$ 112,98\n2 - Rio de Janeiro, RJ. --------- R$ 139,99\n3 - Vitoria, ES. ---------------- R$ 439,91\n4 - Curitiba, PR. --------------- R$ 199,99\n5 - Belo Horizonte, MG. --------- R$ 279,99\n6 - Cancelar e sair.\n");
            scanf("%i", &opcao); // pega a opção do menu
            switch (opcao)
            {
            case 1:                                         // se a opção for 1
                strcpy(ticket[i].destino, "Sao Paulo, SP"); // copia o destino para a struct
                ticket[i].valor = 112.98;                   // copia o valor para a struct
                printf("Sao Paulo, SP\nR$ 112,98\n");       // imprime o destino e o valor
                break;                                      // finaliza o switch
            case 2:
                strcpy(ticket[i].destino, "Rio de Janeiro, RJ");
                ticket[i].valor = 139.99;
                printf("Rio de Janeiro, RJ\nR$ 139,99\n");
                break;
            case 3:
                strcpy(ticket[i].destino, "Vitoria, ES");
                ticket[i].valor = 439.91;
                printf("Vitoria, ES\nR$ 439,91\n");
                break;
            case 4:
                strcpy(ticket[i].destino, "Curitiba, PR");
                ticket[i].valor = 199.99;
                printf("Curitiba, PR\nR$ 199,99\n");
                break;
            case 5:
                strcpy(ticket[i].destino, "Belo Horizonte, MG");
                ticket[i].valor = 279.99;
                printf("Belo Horizonte, MG\nR$ 279,99\n");
                break;
            case 6:
                printf("Saindo...\n"); // se a opção for 6, sai do programa
                return 0;              // finaliza o programa
            default:
                printf("Opcao Invalida!\n");
                break;
            }
            system("cls");
            printf("============== Viacao FATEC ==============\n");
            printf("============== Dados da Viagem ===========\n");
            printf("Destino: %s\n", ticket[i].destino);    // imprime o destino
            printf("Valor: R$ %.2f\n\n", ticket[i].valor); // imprime o valor
            printf("============ Dados do Passageiro =========\n");
            printf("Nome:\n");
            fflush(stdin);
            fgets(ticket[i].nome, 80, stdin);
            // scanf("%s", &ticket[i].nome);
            // não consegui usar scanf em string com espaços
            printf("CPF (Sem pontos ou hifen):\n");
            scanf("%s", ticket[i].CPF);
            printf("Data de Partida (DD/MM/AAAA):\n");
            scanf("%s", ticket[i].dataIda);
            printf("Data de Volta (DD/MM/AAAA):\n");
            scanf("%s", ticket[i].dataVolta);
            system("cls");
            break;
        case 2:
            system("cls");
            printf("Passagens cadastradas:\n");
            for (i = 0; i < 100; i++)
            {
                if (ticket[i].nome[0] != '\0') // se o nome não for vazio
                {
                    printf("%.3i - %s\n", i, ticket[i].nome); // imprime numero da passagem e o nome
                }
            }
            printf("Numero da passagem a ser consultada: ");
            scanf("%i", &i);
            printf("============== Viacao FATEC ==============\n");
            printf("============== Dados da Viagem ===========\n\n");
            printf("=============== PASSAGEM %i ===============\n", i);
            printf("Destino: %s\n", ticket[i].destino);
            printf("Valor: R$ %.2f\n", ticket[i].valor);
            printf("Data de Partida: %s\n", ticket[i].dataIda);
            printf("Data de Volta: %s\n", ticket[i].dataVolta);
            printf("Nome: %s", ticket[i].nome);
            strcpy(cpf1, ticket[i].CPF); // copia o cpf para a variavel cpf1
            mascara(cpf1, "###.###.###-##\n");
            printf("========= Tenha uma Boa Viagem!! ==========\n");
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("Saindo...");
            system("pause");
            system("cls");
            break;
        default:
            system("cls");
            printf("Opcao invalida");
            system("pause");
            system("cls");
            break;
        }
    } while (opcao != 3);
    return 0;
}