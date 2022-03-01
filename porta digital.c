#include <16F877a.h>
#use delay (clock=16M)
#fuses HS,NOWDT, NOPUT,NOBROWNOUT,NOLVP
#include <bib_LCD_16x2_all.c>
#include <internal_eeprom.c>//não entendi como funciona essa biblioteca

void escreve (int *p);
void zera (int *p, int *p2, int *p3);
void tec (int *p,int *p2, int *p3);
void aste(int *p, int *p2);
void main(){
ini_lcd_16x2();
int a[8]={10,10,10,10,10,10,10,10},b[8]={2,0,1,0,2,6,1,0},x,y=0,c=0,d=0, e[8]={1,2,3,4,5,6,7,8},f=0,g=0;//vetor 'a' é onde digito a senha.
int h[8]={10,10,10,10,10,10,10,10},i[8]={10,10,10,10,10,10,10,10},j=0,z=0;// vetor 'b' onde comparo.
printf(exibe_lcd,"\fSenha:");                                             //'y' conta a quantidade de componetes dos vetores A e B semelhantes.
while (true)                                                              //'c' conta quantos numeros foram difitados.
{                                                                         // o vetor 'e' é a senha de segurança.
if(d==0)                                                                  // 'd' serve para o istabilizar o teclado que dava varios pulsos.
{                                                                          //'f' é o contador para habilitar a senha de segurança.
output_high(PIN_C7);                                                       //'g' é contador que habilida a sequencia para que a senha seja mudada.
if (input(pin_c0))                                                         // o vetor 'h' é usado para armazenar a nova senha.
{                                                                         // o vetor 'i' armazena a repetição da nova senha.
if(c==8)                                                                 // 'j' conta a quantidade de componetes dos vetores H e J semelhantes.
aste(&c,&g);                                                             // para o programa ficar completo falta armazenar a senha na eeprom e 
else                                                                     // conseguir trabalhar com senhas menores que 8 digitos.    
{
a[c]=1;
tec(&c,&d,&g);
}
}
if(input(pin_c1))
{
if(c==8)
{
aste(&c,&g);
}
if(!(c==8))
{
a[c]=4;
tec(&c,&d,&g);
}
}
if(input(pin_c2))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=7;
tec(&c,&d,&g);
}
}
if(input(pin_c3))
{

for (x=0;x<8;x++)
{
if(a[x]==b[x])
 y++;
if(a[x]==e[x])
f++;
}
if(g==3)
{
for (x=0;x<8;x++)
i[x]=a[x];
for(x=0;x<8;x++)
{
if(i[x]==h[x])
j++;
}
if(j==8)
{
printf(exibe_lcd,"\fSENHA ALTERADA\nCOM SUCESSO!");
delay_ms(1000);
for(x=0;x<8;x++)
b[x]=h[x];
g=0;
escreve(&g);
j=0;
goto thyago;
}
if(!(j==8))
{
printf(exibe_lcd,"\f AS SENHAS NÃO \nBATEM!!");
delay_ms(1000);
g=0;
j=0;
escreve(&g);
goto thyago;
}
}
if(g==2)
{
for (x=0;x<8;x++)
h[x]=a[x];
g=3;
printf(exibe_lcd,"\fRepita a Senha:\n");
delay_ms(1000);
escreve(&g);
goto thyago;
}
   if((y==8)&&(g==1))
{
   printf(exibe_lcd,"\fSenha correta");
   delay_ms(1000);
   printf(exibe_lcd,"\fDigite nova\n senha:");
   delay_ms(1000);
   g=2;
   escreve(&g);
   goto thyago;
}
   if((!(y==8))&&(g==1))
{
   printf(exibe_lcd,"\fSenha Invalida");
   delay_ms(1000);
   g=0;
   escreve(&g);
   goto thyago;
}
   if((y==8)&&(g==0))
{
   output_high(PIN_B0);
   printf(exibe_lcd,"\fB");
   delay_ms(200);
   printf(exibe_lcd,"\fBe");
   delay_ms(200);
   printf(exibe_lcd,"\fBem");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-V");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-Vi");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-Vin");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-Vind");
   delay_ms(200);
   printf(exibe_lcd,"\fBem-Vindo");
   delay_ms(400);
   output_low(PIN_B0);
   escreve(&g);
   for(x=0;x<=7;x++)
   a[x]='*';
   goto thyago;
}
   if ((f==8)&&(g==0))
{
   for(x=0;x<4;x++)
    {
    printf(exibe_lcd,"\fTROCA SENHA \nATIVADO!");
   delay_ms(400);
   printf(exibe_lcd,"\f");
   delay_ms(300);
    }
   printf(exibe_lcd,"\fDIGITE\nA SENHA ATUAL");
   delay_ms(1500);
   g=1;
   escreve(&g);
   for(x=0;x<=7;x++)
   a[x]='*';
   goto thyago;
}
   if((!(f==8))&&(!(y==8))&&(g==0))   
{
    printf(exibe_lcd,"\fSenha Invalida");
   delay_ms(1000);
   escreve(&g);
}
   thyago:
   zera(&c,&y,&f);
}
   output_low(pin_c7);
   output_high(pin_c6);
   if(input(pin_c0))
{
   if(c==8)
   aste(&c,&g);
   if(!(c==8))
{
   a[c]=2;
   tec(&c,&d,&g);
}
}
if(input(pin_c1))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=5;
tec(&c,&d,&g);
}
}
if(input(pin_c2))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=8;
tec(&c,&d,&g);
}
}
if(input(pin_c3))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=0;
tec(&c,&d,&g);
}
}
output_low(pin_c6);
output_high(pin_c5);
if(input(pin_c0))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=3;
tec(&c,&d,&g);
}
}
if(input(pin_c1))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=6;
tec(&c,&d,&g);
}
}
if(input(pin_c2))
{
if(c==8)
aste(&c,&g);
if(!(c==8))
{
a[c]=9;
tec(&c,&d,&g);
}
}
if(input(pin_c3))
{
delay_ms(25);
zera(&c,&y,&f);
g=0;
d++;
escreve(&g);
}
output_low(pin_c5);
}
output_high(pin_c7);
output_high(pin_c6);
output_high(pin_c5);
if(d==1)
{
while(input(pin_c0)||input(pin_c1)||input(pin_c2)||input(pin_c3))
delay_ms(25);
d=0;
}
output_low(pin_c7);
output_low(pin_c6);
output_low(pin_c5);
}
}
void aste(int *p, int *p2)
{
int x;
delay_ms(25);
if(*p2==0)
printf(exibe_lcd,"\fSenha:\n");
if(*p2==1)
printf(exibe_lcd,"\fSenha Atual:\n");
if(*p2==2)
printf(exibe_lcd,"\fNova Senha:\n");
if(*p2==3)
printf(exibe_lcd,"\fRepita a Senha:\n");
for(x=0;x<*p;x++)
printf(exibe_lcd,"*");

}
void tec (int *p,int *p2, int *p3)
{
int x;
(*p)++;
(*p2)++;
if(*p3==0)
printf(exibe_lcd,"\fSenha:\n");
if(*p3==1)
printf(exibe_lcd,"\fSenha Atual:\n");
if(*p3==2)
printf(exibe_lcd,"\fNova Senha:\n");
if(*p3==3)
printf(exibe_lcd,"\fRepita a Senha:\n");
for(x=1;x<=*p;x++)
printf(exibe_lcd,"*");
}
void zera (int *p, int *p2, int *p3)
{
(*p)=0;
(*p2)=0;
(*p3)=0;
}
void escreve (int *p)
{
if(*p==0)
printf(exibe_lcd,"\fSenha:\n");
if(*p==1)
printf(exibe_lcd,"\fSenha Atual:\n");
if(*p==2)
printf(exibe_lcd,"\fNova Senha:\n");
if(*p==3)
printf(exibe_lcd,"\fRepita a Senha:\n");
}






























































































































































