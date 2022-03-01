#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int main ()
{

    char fr[81],l;
   
    int c=0,k;
   
    gets (fr);
  
    for (k=0;fr[k];k++){
  
    l=fr[k];
  
    if(strchr("AEIOUaoeiu",l))
    
    c++;

}

printf("%d\n" ,c);
getch();
system ("pause");
}
//leia uma frase de no maximo 80 caracteres e informe a quantidade de vogais.

