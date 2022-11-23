#include<stdio.h>

typedef struct
{
int dia, mes, ano;
}registro;

typedef struct
{
    char nome[30];
    registro data;
    float salario;
}funcionario;

int main(){
    funcionario f;
    printf("Digite o nome do funcionario: ");
    scanf("%s", f.nome);
    printf("Digite a data de nascimento do funcionario: (DD MM AAAA): ");
    scanf("%d %d %d", &f.data.dia, &f.data.mes, &f.data.ano);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &f.salario);
    printf("\nNome: %s\nData de nascimento: %d/%d/%d\nSalario: %.2f", f.nome, f.data.dia, f.data.mes, f.data.ano, f.salario);
    return 0;
}
