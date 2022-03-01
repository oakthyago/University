#include "msp430g2452.h"
//#include <signal.h>


int x=0,j=1,y=0,z=0;
unsigned int delay ( unsigned int x);
int main( void )
{
  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR |= 0xFF; //  P1 como saida
  P1OUT = 0;       // todas portas em de P1 em 0
  P2REN = 0x01 + 0x02;  // P2.9 e P2.1 como entrada
  P2OUT = 0x00;         // todas portas de P2  em 0
   P2IE = 0x01 + 0x02;  // interrupção p2.0 e p2.1
   P2IFG = 0x00; //Limpa a flag de interrupção da porta P2, informando que não existem interrupções pendentes
   _BIS_SR(GIE);   // Habilita interrupções com mspgcc (General Interrupt Enable)
  P2IES = 0x00;   // Configura a interrupção na borda de subida
    while (1)
  {
  delay(100); 
    if (x)
    {
      P1OUT = j;
      j=j*2;
      if (j>128)
        { 
          j=1 ;
        }
    }
      if (y)
    {
       P1OUT = j;
        j=j/2; 
        if (j==(1/2))
          { 
            j=128 ;
          }
    }
   
  }
}  

#pragma vector=PORT2_VECTOR  // rotina de tratamento de interrupção da porta 1  
__interrupt void Port_2(void)
{
  if ((P2IN & 0x01) == 0x01)
      {
      x=1;
    y=0;
      }
     if ((P2IN & 0x02) == 0x02)
    {
      x=0;
    y=1;
    if(z==0)
      j=128;
    z++;
    } 
   P2IFG = 0x00;
}
unsigned int delay ( unsigned int x)
{
unsigned int i,j;
for (i = 0; i<= x; i++)
{
for(j=0;j<=500; j++)
;
}
return 0;
}