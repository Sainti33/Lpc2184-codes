/*
--->PINSEL0--->P0.0 to P0.15
--->PINSEL1--->P0.16 to P0.31
--->PINSEL2--->P1.16 to P1.31
--->IOPIN----->use to read the status
--->IOSET----->use to set/high the pin
--->IOCLR----->use to reset/low the pin
--->IODIR----->use to control input/output direction the pin
--->Pins P0.24, P0.26 and P0.27 are not available in Lpc2148
--->P0.31 provides digital output functions only
---> P1.0 to P1.15 are not available in LPC2148
--->Up to 9 edge or level sensitive external interrupt pins available.
*/

#include <LPC214x.H>
#include <stdio.h>
#include "Type.h"
#include "delay.h"
void init_external_interrupt(void);
int main(void){
	IODIR0|=(1<<23);
	delay_ms(100);
	IOCLR0|=(1<<23);
	init_external_interrupt();
	while(1){

	}
}

void my_ext_isr(void) __irq {
	IOSET0|=(1<<23);
	delay_ms(1000);
	IOCLR0|=(1<<23);
	EXTINT&=~(1<<2);
	VICVectAddr=0x00;
	//EXTINT|=(1<<2);    // Flag Clear
	EXTINT |= (0x4); 
}

void init_external_interrupt(void){
	PINSEL0=0x80000000;  /* Using P0.15 as an EINT2 */
	EXTMODE|=(1<<2);   /* EINT2 as Edge sensitive input */
	EXTPOLAR|=(1<<2);  /* EINT2 on Falling edge input */
	VICIntSelect&=~(1<<16); /* Making EINT2 as IRQ    */
	VICVectAddr0=(unsigned int) my_ext_isr;
	VICVectCntl0=(1<<5)|16;   /* Assign EINT2 source number &  enable vect int slot */
	VICIntEnable=(1<<16);
	//EXTINT&=~(1<<2);               // Flag Enable
	EXTINT &= ~(0x4); 
}
