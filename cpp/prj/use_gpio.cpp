#include "MK02F12810.h"                 // Device header
#include "gpio.h"


gpio B (gpio::B);
extern "C" {
   void PIT0_IRQHandler();
}

#define LED 1 

void PIT0_IRQHandler()
{
	B.ChangePinState (LED);
	PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;
}

void fll_init ()
{/*
  MCG->C2 |= MCG_C2_RANGE(1) | MCG_C2_HGO_MASK | MCG_C2_EREFS_MASK;
  MCG->C1 |= MCG_C1_CLKS(2) | MCG_C1_FRDIV(3);
  while (!(MCG->S & MCG_S_OSCINIT0_MASK));
  while (MCG->S & MCG_S_IREFST_MASK);
  while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2);
  MCG->C6 = 0;*/
	MCG->C1 &= ~(3 << MCG_C1_CLKS_SHIFT);
	while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT));
	MCG->C2 |= MCG_C2_EREFS_MASK;
	while (!(MCG->S & MCG_S_IREFST_MASK));
	
	MCG->C2 &= ~(3 << MCG_C2_RANGE_SHIFT);
	SIM->CLKDIV1 &= ~(0x0F << SIM_CLKDIV1_OUTDIV1_SHIFT|0x0F << SIM_CLKDIV1_OUTDIV2_SHIFT|0x0F << SIM_CLKDIV1_OUTDIV4_SHIFT);
	SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(1) | SIM_CLKDIV1_OUTDIV4(3);
	MCG->C4 |= MCG_C4_DRST_DRS(3);
	while (((MCG->C4 & MCG_C4_DRST_DRS_MASK) >> MCG_C4_DRST_DRS_SHIFT) != 3) ;
  //SIM->SOPT2 |=

  //SIM
  
	
  
}

void pit_init (uint32_t div)
{
  SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
  PIT->MCR = 0;
  PIT->CHANNEL[0].LDVAL = div;
  PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK;
  PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK;
  NVIC_EnableIRQ (PIT0_IRQn);
}

int main ()
{
//  pll_init ();

 // SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	fll_init ();

	//SIM->CLKDIV1 |= SIM_CLKDIV1_OUTDIV2(2)|SIM_CLKDIV1_OUTDIV4(4);
  B.setOutPin (LED);
	
  //PORTB->PCR [LED] |= PORT_PCR_MUX(1);
  //PTB->PDDR |= 1 << LED;
	//PTB->PDOR |= 1 << LED;
  pit_init (40966816);
  while (1)
  {
  }
}
