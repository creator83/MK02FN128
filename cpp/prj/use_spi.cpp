#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "tact.h"
#include "delay.h"
#include "pit.h"
#include "shift_registr.h"
#include "list.h"

Tact frq;
Spi spi0;
Shift reg (spi0, Spi::CTAR0);
List functions;

Pit pit1 (Pit::ch1, 1000, Pit::ms);
extern "C" {
	void PIT1_IRQHandler();
}

const uint8_t CS   = 4;
const uint8_t SCK  = 5;
const uint8_t MOSI = 6;


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

void send_shift ();

int main ()
{
	reg.set_CS (Gpio::A, CS, Gpio::Alt2);
	reg.set_SCK(Gpio::A, SCK, Gpio::Alt2);
	reg.set_MOSI(Gpio::A, MOSI, Gpio::Alt2);
	functions.addToHead(send_shift, 1000);

	pit1.interrupt_enable();
	pit1.start();

	while (1)
	{
	}
}

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

}
