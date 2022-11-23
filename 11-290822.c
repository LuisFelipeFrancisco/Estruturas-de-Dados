#include <stdio.h>
 int main(void)
 {
    enum { black, blue, green, cyan, red, purple, yellow, white} cores;

    cores = green;

     switch(cores) {
         case 0:
           printf("Cor preto \n");
           break;
         case 1:
           printf("Cor azul \n");
           break;
         case 2:
           printf("Cor verde \n");
           break;
         case 3:
           printf("Cor ciano \n");
           break;
         case 4:
           printf("Cor vermelho \n");
           break;
         case 5:
           printf("Cor roxo \n");
           break;
         case 6:
           printf("Cor amarelo \n");
           break;
         default:
           printf("Cor branco \n");
     }
  return  0 ;

 }