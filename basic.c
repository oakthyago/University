#include <16F877A.h>
#device adc=8
#use delay(clock=20000000)
#fuses NOWDT,XT, NOPUT, NOPROTECT, NODEBUG, BROWNOUT, LVP, NOCPD, NOWRT        
void main (){
         while(1){
                output_high(PIN_d0);
                delay_ms(1000);
                output_low(PIN_d0);
                delay_ms(1000);
         }
}

