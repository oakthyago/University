#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

int main ()
{ 
  char nome[25],sexo;
  int idade,nota1,nota2;
  float media ;
 printf ("\t\tControle Academico\n");
  printf ("Nome:\n");
  gets (nome);
  

  printf ("Idade:\n");
  scanf ("%d%c",&idade);
  
  printf ("Sexo (M)ou(F):\n");
  sexo=getchar() ;
  printf ("\t\tAvaliacoes\n");
  printf ("1 nota\n");
  scanf("%d",&nota1);
  printf ("2 nota\n");
  scanf("%d",&nota2);
  media = (nota1 + nota2)/2.0;   
  printf("\t\tMedia\n\t\t%0.2f\n\n\n\n\n",media);
  system ("pause");
}
