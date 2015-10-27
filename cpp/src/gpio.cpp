#include "gpio.h"

uint32_t gpio::PortBase [5] = {PORTA_BASE , PORTB_BASE , PORTC_BASE, PORTD_BASE , PORTE_BASE};
uint32_t gpio::GpioBase [5] = {PTA_BASE , PTB_BASE , PTC_BASE , PTD_BASE , PTE_BASE};

gpio::gpio (Port p)
{
  prt = p;
  //takt port
  SIM->SCGC5 |= (0x200 << p);
}

gpio::gpio(uint8_t p )
{
  prt = p;
//takt port
  SIM->SCGC5 |= (0x200 << p);
}

void gpio::setOutPin (unsigned char pin , mode m , out o)	
{
  *(reg)(PortBase[prt]+(pin<<2)) |= PORT_PCR_MUX(m);
  *(reg)(PortBase[prt]+(pin<<2)) |= o << PORT_PCR_ODE_SHIFT;
  *(reg)(GpioBase[prt]+PDDR) |= 1 << pin;
}

void gpio::setPin (unsigned int pin )
{
  *(reg)(GpioBase[prt]+PSOR) |= 1 << pin;
}

void gpio::clearPin (unsigned char pin)
{
  *(reg)(GpioBase[prt]+PCOR) |= 1 << pin;
}

void gpio::ChangePinState (unsigned char pin)
{
  *(reg)(GpioBase[prt]+PTOR) |= 1 << pin;
}

void gpio::SetPinState (unsigned char pin , unsigned char state)
{
  if (state)setPin (pin);
  else clearPin (pin);  
}

void gpio::setValPort (uint32_t value)
{
  *(reg)(GpioBase[prt]+PDOR) = value;
}
