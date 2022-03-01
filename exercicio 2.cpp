#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

  int conjunto (int a,int b[15]);

int main ()
{
    int x,a[15],b=0,m;
    printf("escreva 15 numeros");
    
    for (x=0;x<=14;x++)
    {
        scanf("%d",&a[x]);
        }
        
        printf("escreva um numero");
        scanf("%d",&b);
        
        m=conjunto(b,a);
        
        printf("retorno foi %d", m);
        
        system ("pause");
        
        }
    

    int conjunto (int a,int b[15])
{
    int x=0;
    
    for (x=0;x<=14;x++){
    if(a==b[x])
    return(1);
    return(0);
}
}
