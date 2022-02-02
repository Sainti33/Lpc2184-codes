
Interrupt in Lpc2148:-(1)FIQ (2)VectIRQ (3)NonVecIRQ
Interrupt handle by VIC controller in Lpc2148.VIC can handle 32 interrupt request input
but only 16 request can be assigned to a vectored IRQ interrupt in LPc2148.We are given a set of 16 vectored IRQ slots 
to which we can assign any of the 22 requests that are available in LPC2148.The slot numbering goes from 0 to 15 with 
slot no. 0 having highest priority and slot no. 15 having lowest priority.


