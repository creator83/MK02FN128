#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "tact.h"
#include "delay.h"
#include "pit.h"
#include "shift_registr.h"


Tact frq;
Spi spi0;
Shift reg (spi0, Spi::CTAR0);


Pit pit1 (Pit::ch1, 300, Pit::ms);
extern "C" {
	void PIT1_IRQHandler();
}

const uint8_t CS   = 16;
const uint8_t SCK  = 17;
const uint8_t MOSI = 18;


void PIT1_IRQHandler()
{
	pit1.clear_flag();
	static bool flag;
	if (flag)
	{
		reg.send(0x0F);
		flag = false;
	}
	else
	{
		reg.send(0xF0);
		flag = true;
	}
}

//void send_shift ();

int main ()
{

	reg.set_CS (Gpio::E, CS, Gpio::Alt2, Spi::CS0);
	reg.set_SCK(Gpio::E, SCK, Gpio::Alt2);
	reg.set_MOSI(Gpio::E, MOSI, Gpio::Alt2);


	pit1.interrupt_enable();
	pit1.start();

	while (1)
	{
		/*reg.send(0xF0);
		delay_ms(500);
		reg.send(0x0F);
		delay_ms(500);*/
	}
}
/*
void send_shift ()
{
	static bool flag;
	if (flag)
	{
		reg.send(0xF0);
		flag = false;
	}
	else
	{
		reg.send(0x0F);
		flag = true;
	}

}*/
