#include <stdio.h>
#include <string.h>
int main( ) { 
  union {
   int i;
   float f;
   char str[20];
  } dado;
 
  dado.i = 10; /* union sera do tipo inteiro */
  printf( "Sou inteiro : %d\n", dado.i);
  dado.f = 34.5; /* union sera do tipo float */
  printf( "Sou real : %f\n", dado.f);
  strcpy(dado.str,"Sou String"); /* union sera do tipo String */
  printf( "Sou string : %s\n", dado.str);

   return 0;
}
