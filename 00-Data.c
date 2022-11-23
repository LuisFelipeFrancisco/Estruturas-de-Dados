/* It compares two dates and prints a message if the second date is before the first date */
#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

int main()
{
    data d1, d2; // criação de duas datas
    printf("Digite a data de ida (dia/mes/ano): ");
    scanf("%i/%i/%i", &d1.dia, &d1.mes, &d1.ano);
    printf("Digite a data de volta (dia/mes/ano): ");
    scanf("%i/%i/%i", &d2.dia, &d2.mes, &d2.ano);

if (d2.ano < d1.ano)
    { // ano de volta menor que ano de ida
        printf("se o ano de volta for menor que o ano de ida, entao e invalido\n");
    }
    else if (d2.ano == d1.ano)
    { // ano de ida e ano de volta iguais
        if (d2.mes < d1.mes)
        { // mes de volta menor que mes de ida, ano igual, entao e invalido
            printf("Data de ida antes de data volta\n");
        }
        else if (d2.mes == d1.mes)
        { // mes de ida e mes de volta iguais, ano igual, entao e invalido
            if (d2.dia < d1.dia)
            { // dia de volta menor que dia de ida, mes igual, ano igual, entao e invalido
                printf("Data de ida antes de data volta\n");
            }
            else
            { // dia igual, mes igual, ano igual, então é válido
                printf("Data de volta depois da data de ida\n");
            }
        }
        else
        { // mes de ida maior que mes de volta, ano igual, então é válido
            printf("Data de volta depois da data de ida\n");
        }
    }
    else
    { // ano de ida maior que ano de volta
        printf("Data de volta depois da data de ida\n");
    }
    printf("Data de ida: %i/%i/%i\n", d1.dia, d1.mes, d1.ano);
    printf("Data de volta: %i/%i/%i\n", d2.dia, d2.mes, d2.ano);
    return 0;
}