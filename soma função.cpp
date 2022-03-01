#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>


   int par(int x)
    {
        if (x%2)
        return (0);
        return (1);
        }  





int main ()
{
    int n,p;
    
    scanf ("%d",&n);
    p=par(n);
    if(p)
    printf("Par");
    else
    printf("Impar");

system ("pause");
  
  
  
}


