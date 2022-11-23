#include<stdio.h>

typedef struct {
    float peso;
    int idade;
    float altura;
} pessoa;

void imprime(pessoa p) {
    printf("%f %d %f\n", p.peso, p.idade, p.altura);
}

int main() {
    pessoa joao, p2;
    pessoa povo[10];

    joao.idade=15;
    joao.peso=60.5;
    joao.altura=1.75;

    povo[4].idade=23;
    povo[4].peso=75.3;
    povo[4].altura=1.89;

    p2=povo[4];
        p2.idade++;

 /* 
    printf ("Joao tem %i anos, pesa %.2f kg e tem %.2f m de altura.\n", joao.idade, joao.peso, joao.altura);
    printf ("Povo[4] tem %i anos, pesa %.2f kg e tem %.2f m de altura.\n", povo[4].idade, povo[4].peso, povo[4].altura);
    printf ("P2 tem %i anos, pesa %.2f kg e tem %.2f m de altura.\n", p2.idade, p2.peso, p2.altura);
*/
    imprime(joao);
    imprime(povo[4]);
    imprime(p2);

    return 0;
}
