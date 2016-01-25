// AARTHY SUNDARAM (EDM12B002), KAVIYA.R (EDM12B015)
//This code controls the LEDs that are connected to the TM4C123G 

#include <stdint.h>
#include "tm4c123gh6pm.h"

unsigned long in ; //input from PF4
unsigned long out ; //input from PF2
int
main(void)
{
    volatile uint32_t ui32Loop;
		volatile uint32_t ui32Loop1;
	  int ctr;
		SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;
    ui32Loop = SYSCTL_RCGC2_R;    /////// PF3 IS OUTPUT
    GPIO_PORTF_LOCK_R = 0x4C4F434B; // 2) unlock GPIO Port F
		GPIO_PORTF_CR_R = 0x1F; // allow changes to PF4-0
		GPIO_PORTF_AMSEL_R = 0x00; // 3) disable analog on PF
		GPIO_PORTF_PCTL_R = 0x00000000; // 4) PCTL GPIO on PF4-0
		GPIO_PORTF_DIR_R = 0x0E; // 5) PF4,PF0 in, PF3-1 out
		GPIO_PORTF_AFSEL_R = 0x00; // 6) disable alt funct on PF7-0
		GPIO_PORTF_PUR_R  = 0x11;// enable pull-up on PF0 and PF4
		GPIO_PORTF_DEN_R = 0x1F; // 7) enable digital I/O on PF4-0 
	  
	  SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOD;
    ui32Loop1 = SYSCTL_RCGC2_R;
   // GPIO_PORTD_LOCK_R = 0x4C4F434B; // 2) unlock GPIO Port F
	//	GPIO_PORTD_CR_R = 0x1F; // allow changes to PF4-0
		GPIO_PORTD_AMSEL_R = 0x00; //////////// 3)   PD0 , PD1  inputs
 		GPIO_PORTD_PCTL_R = 0x00000000; // 4) PCTL GPIO on PF4-0
		GPIO_PORTD_DIR_R = 0x00; // 5) PF4,PF0 in, PF3-1 out
		GPIO_PORTD_AFSEL_R = 0x00; // 6) disable alt funct on PF7-0
		GPIO_PORTD_PUR_R  = 0x11;// enable pull-up on PF0 and PF4
		GPIO_PORTD_DEN_R = 0x03; // 7) enable digital I/O on PF4-0 
	
		//ctr = 0;
    //
    // Loop forever.
    //
    while(1)
    {
			GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & 0x00;
			in = GPIO_PORTD_DATA_R & 0x01; 
			
			if (in == 0x01  ){
		//		ctr = ctr +1;
				GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & 0x00; 
			  GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | 0x08 ;
			}
		else if (in == 0x10)
		{
			//1ctr = ctr +1;
			GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & 0x00;
			GPIO_PORTF_DATA_R =GPIO_PORTF_DATA_R | 0x02 ;
			
		}
	  
		
		
			}
