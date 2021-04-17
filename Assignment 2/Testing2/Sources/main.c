#include <hidef.h>      /* common defines and macros */
#include <stdio.h>
#include <math.h>
#include "derivative.h"      /* derivative-specific definitions */
//#include "mc9s12dg256.h"

volatile double timeCounter = 0;

#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Interrupt section for this module. Placement will be in NON_BANKED area. */
__interrupt void overFlowCheck(void) {
  
  double time_Elapsed = pow(2.73,-1000);
  timeCounter += time_Elapsed;
  
}

void main(void) {
  /* put your own code here */
  volatile double t = timeCounter;
  volatile double x = 1, y = 2;
  volatile double z; //= x + y;*/
  
  
  TSCR1 = 0x90;    // enable timer counter
  //TSCR2 = 0x06;    // set prescaler to 64
  
  
  t = TCNT;
  
  //z = sqrt(x);
  z = x + y;
  
  //t = timeCounter;
  
  t = TCNT;
  
   /*unsigned int edge1, period;
   TSCR1 = 0x90;
   TIOS &= ~TIOS0; // enable input-capture 0
   TSCR2 5 0x06; // disable TCNT overflow interrupt, set prescaler to 64
   TCTL4 5 0x01; // capture the rising edge of the PT0 pin
   TFLG1 5 0x01; // clear the C0F flag 
   while (!(TFLG1 & C0F)); // wait for the arrival of the first rising edge
   edge1 5 TC0; // save the first captured edge and clear the C0F flag
   while (!(TFLG1 & C0F)); // wait for the arrival of the second rising edge
   period 5 TC0 2 edge1;
   while(1);              */
  
  //movb #$F0,TIOS

	EnableInterrupts;
               
  for(;;) {
    _FEED_COP(); /* feeds the dog */
    /*z = x + y;
  
    t = timeCounter;
    break; */
    
  } /* loop forever */
  /* please make sure that you never leave main */
}