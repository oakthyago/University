#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

char inversa (char a[100]);

     
    int  main ()
     {
         
         char a[100];
         
         gets (a);
         
      inversa(a);
         
         
         system ("pause");
         }
             
         
char inversa (char a[100])
{
     int x,y=0;
     
     x=strlen(a);
     
     for (y=x-1;y>=0;y--)
         {
     printf("%c",a[y]);
     
     }
     }     
