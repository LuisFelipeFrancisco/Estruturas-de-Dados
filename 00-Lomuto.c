//ordenação usando lomuto

#include <stdio.h>

void lomuto(int *v, int n){
    int i, j, pivo, aux;
    for(i = 0; i < n; i++){
        pivo = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > pivo){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = pivo;
    }
}

int main(){
    int v[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;
    lomuto(v, 10);
    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }
    return 0;
}