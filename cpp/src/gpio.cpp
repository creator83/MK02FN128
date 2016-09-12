#include "gpio.h"

GPIO_MemMapPtr Gpio::GpioBase [5] = {PTA_BASE_PTR , PTB_BASE_PTR , PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};
PORT_MemMapPtr Gpio::PortBase [5] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};

Gpio::Gpio (Port p)
{
  prt = p;
  //takt port
  SIM->SCGC5 |= (0x200 << p);
}

Gpio::Gpio (uint8_t p )
{
  prt = p;
//takt port
  SIM->SCGC5 |= (0x200 << p);
}



void Gpio::settingPin (unsigned char pin , mux mx, mode m)
{
	PORT_PCR_REG(PortBase[prt],pin) |= mx << PORT_PCR_MUX_SHIFT;
	GPIO_PDDR_REG(GpioBase[prt]) &= ~(1 << pin);
	GPIO_PDDR_REG(GpioBase[prt]) |= (m << pin);
}

void Gpio::setPin (unsigned int pin )
{
	GPIO_PSOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::clearPin (unsigned char pin)
{
	GPIO_PCOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::changePinState (unsigned char pin)
{
	GPIO_PTOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::setPinState (unsigned char pin , unsigned char state)
{
	clearPin (pin);
	GPIO_PDOR_REG(GpioBase[prt]) = (state << pin);
}

bool Gpio::pinState (unsigned char pin)
{
	return (GPIO_PDIR_REG(GpioBase[prt])&(1 << pin));
}

void Gpio::settingPort (uint32_t value, mux mx, mode m )
{
	union
	{
		uint32_t full;
		uint16_t half[2];
	}val;
	val.full = value;
	PORT_GPCLR_REG(PortBase[prt]) = (val.half[0]<<16| mx << PORT_PCR_MUX_SHIFT);
	PORT_GPCHR_REG(PortBase[prt]) = (val.half[1]<<16| mx << PORT_PCR_MUX_SHIFT);
	if (mx==GPIO&&m)
	{
		GPIO_PDDR_REG(GpioBase[prt]) |= value;
	}
}

void Gpio::setValPort (uint32_t value)
{
	GPIO_PSOR_REG(GpioBase[prt])  |= value;
}

void Gpio::clearValPort (uint32_t value)
{
	GPIO_PCOR_REG(GpioBase[prt])  |= value;
}

