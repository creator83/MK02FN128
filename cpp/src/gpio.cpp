#include "gpio.h"

GPIO_MemMapPtr Gpio::GpioBase [5] = {PTA_BASE_PTR , PTB_BASE_PTR , PTC_BASE_PTR, PTD_BASE_PTR, PTE_BASE_PTR};
PORT_MemMapPtr Gpio::PortBase [5] = {PORTA_BASE_PTR, PORTB_BASE_PTR, PORTC_BASE_PTR, PORTD_BASE_PTR, PORTE_BASE_PTR};


Gpio::Gpio ()
{

}

Gpio::Gpio (Port p)
{
  prt = static_cast <uint8_t> (p);
  //takt port
  SIM->SCGC5 |= (0x200 << prt);
}

Gpio::Gpio (uint8_t p )
{
	prt = p;
	//takt port
	SIM->SCGC5 |= (0x200 << p);
}

void Gpio::settingPinPort (Port p)
{
	prt = static_cast <uint8_t> (p);
	//takt port
	SIM->SCGC5 |= (0x200 << prt);
}

void Gpio::settingPinPort (uint8_t p)
{
	prt = p;
	//takt port
	SIM->SCGC5 |= (0x200 << p);
}

void Gpio::settingPin (unsigned char pin , mux mx, mode m)
{
	PORT_PCR_REG(PortBase[prt],pin) |= (uint8_t)mx << PORT_PCR_MUX_SHIFT;
	GPIO_PDDR_REG(GpioBase[prt]) &= ~(1 << pin);
	GPIO_PDDR_REG(GpioBase[prt]) |= ((uint8_t)m << pin);
}

void Gpio::settingPinDirection (uint8_t pin , mode m)
{
	GPIO_PDDR_REG(GpioBase[prt]) &= ~(1 << pin);
	GPIO_PDDR_REG(GpioBase[prt]) |= ((uint8_t)m << pin);
}

void Gpio::PuPdPin (uint8_t pin, state s, PP p)
{
	PORT_PCR_REG(PortBase[prt],pin) &= ~(1 << PORT_PCR_PE_MASK);
	PORT_PCR_REG(PortBase[prt],pin) |= (uint8_t)s << PORT_PCR_PE_MASK;
	PORT_PCR_REG(PortBase[prt],pin) &= ~ (1 << PORT_PCR_PS_MASK);
	PORT_PCR_REG(PortBase[prt],pin) |= 1 << PORT_PCR_PS_MASK;
}

void Gpio::setPin (uint8_t pin )
{
	GPIO_PSOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::clearPin (uint8_t pin)
{
	GPIO_PCOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::toglePin (uint8_t pin)
{
	GPIO_PTOR_REG(GpioBase[prt]) |= 1 << pin;
}

void Gpio::setPinState (uint8_t pin , state s)
{
	clearPin (pin);
	GPIO_PDOR_REG(GpioBase[prt]) |= (uint8_t) s << pin;
}

bool Gpio::pinState (uint8_t pin)
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
	PORT_GPCLR_REG(PortBase[prt]) = (val.half[0]<<16| (uint8_t)mx << PORT_PCR_MUX_SHIFT);
	PORT_GPCHR_REG(PortBase[prt]) = (val.half[1]<<16| (uint8_t)mx << PORT_PCR_MUX_SHIFT);
	if ((uint8_t)mx==(uint8_t)mux::GPIO&&(uint8_t)m)
	{
		GPIO_PDDR_REG(GpioBase[prt]) |= value;
	}
}

void Gpio::settingPortDirection (uint32_t val, mode m)
{
	if (m == mode::Output) GPIO_PDDR_REG(GpioBase[prt]) |= val;
	else GPIO_PDDR_REG(GpioBase[prt]) &= ~val;
}

void Gpio::setValPort (uint32_t value)
{
	GPIO_PSOR_REG(GpioBase[prt])  |= value;
}

void Gpio::clearValPort (uint32_t value)
{
	GPIO_PCOR_REG(GpioBase[prt])  |= value;
}

