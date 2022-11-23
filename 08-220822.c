#include<stdio.h>

typedef struct
{
    float peso;
    int idade;
    float altura;
} pessoa;

pessoa Setpessoa(float peso, int idade, float altura){
    pessoa p;
    p.peso = peso;
    p.idade = idade;
    p.altura = altura;
    return p;
}

void Imprimir(pessoa p){
    printf("Peso: %.2f\nIdade: %d\nAltura: %.2f\n", p.peso, p.idade, p.altura);
}

int main(){
    pessoa p = Setpessoa(80.0, 20, 1.70);
    Imprimir(p);
    return 0;
}