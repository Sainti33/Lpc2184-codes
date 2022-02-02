
Interrupt in Lpc2148:-(1)FIQ (2)VectIRQ (3)NonVecIRQ
Interrupt handle by VIC controller in Lpc2148.VIC can handle 32 interrupt request input
but only 16 request can be assigned to a vectored IRQ interrupt in LPc2148.We are given a set of 16 vectored IRQ slots 
to which we can assign any of the 22 requests that are available in LPC2148.The slot numbering goes from 0 to 15 with 
slot no. 0 having highest priority and slot no. 15 having lowest priority.
Regiater Related to Interrupt:-
1) VICIntSelect (R/W) : used to select the type of interrupt like IRQ or FIQ
Writing 0---->IRQ Types--->1)VIRQ 2)NonVIRQ
Writing 1---->FIQ Types
2)VICIntEnable(R/W):-used to enable interrupts. 
Writing a 1 at a given bit location will make the corresponding interrupt Enabled.
3) VICIntEnClr (R/W) :-This register is used to disable interrupts. 
How to define ISR in program so that compiler treat it as special fxn
There are two ways:-
__irq void my_isr(void){
------------
}
void my_isr(void) __irq {
------------
}

External interrupt Types and Polarity:->
-->The external interrupt can be level and edge triggered.
      Level
     _______
    |       |   
    |       |  Edge
	__|       |___
	
-->Edge Triggered interrupt generate interrupt only on edge i,e when interrupt line goes from on state to opposite (1-->0) or (0-->1).
-->Level Triggerd:-when interrupt line is in active state. so for example a low-level-trigger interrupt will generate requests whenever 
   the line is low, and (this is important),will continue to generate requests until the line is brought high. 	
-->The second expact of external interrupt is polarity
    --> For Edge triggered, polarity could be rising edge triggered(0-1) or falling edge triggerd(1-0).
		--> For level triggered, polarity could be low triggered(whenever the input is 0) or high triggerd (whenever the input is 1).
