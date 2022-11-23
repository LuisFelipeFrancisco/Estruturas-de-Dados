//Maximo divisor comum recursão

#include <stdio.h>

int mdc(int a, int b){
    if(b==0){
        return a;
    }
    else{
        return mdc(b,a%b);
    }
}

int main(){
    int a,b;
    printf("Digite dois numeros: ");
    scanf("%d %d",&a,&b);
    printf("MDC de %d e %d = %d",a,b,mdc(a,b));
    return 0;
}
