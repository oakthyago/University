#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>


int fatorial(int x)
{
    int f=1,k;
    
    for(k=2;k<=x;k++)
    f*=k;
    
    return (f);
    
}    
int main ()
{
    int a,b;


scanf ("%d",&a);

b=fatorial(a);

printf("%d",b);

system("pause");

}    
    
