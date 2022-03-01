#include <16F877A.h>
#device adc=8
#use delay(clock=20000000)
#fuses NOWDT,XT, NOPUT, NOPROTECT, NODEBUG, BROWNOUT, LVP, NOCPD, NOWRT



int i,k=0, numbin[10]={  0x3F,// 0
                      0x06,// 1
                      0x5B,// 2
                      0x4F,// 3
                      0x66,// 4
                      0x6D,// 5
                      0x7C,// 6
                      0x07,// 7
                      0xFF,// 8
                      0x67};// 9
                    

 

void main()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   set_tris_b(0xFF);
   
   // Projeto 1
   while(1){
 
      for(i=0;i<10;i++){
 
         output_d(numbin[i]);
         delay_ms(1000);


       }
   }
   // Projeto 2
 /*   output_d(numbin[0]);
    while(1){
       i = input(PIN_B0);
       if(i){
           if (k==9)
               k=0;
           else
               k++;
           delay_ms(150);
       }
       output_d(numbin[k]);
       
       
    }
 */
   
}
