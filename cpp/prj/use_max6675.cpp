#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "tact.h"
#include "delay.h"
#include "pit.h"
#include "max6675.h"
#include "buffer.h"




Tact frq;
Spi spi0;
Pit pit1 (Pit::ch1, 1000, Pit::ms);
extern "C" {
	void PIT1_IRQHandler();
}

const uint8_t CS   = 16;
const uint8_t SCK  = 17;
const uint8_t MOSI = 18;
const uint8_t MISO = 19;

void PIT1_IRQHandler()
{
	pit1.clear_flag();
	static bool flag;
	if (flag)
	{
		spi0.put_data(0xF0);
		flag = false;
	}
	else
	{
		spi0.put_data(0x0F);
		flag = true;
	}
}

int main ()
{
	pit1.interrupt_enable();
	spi0.set_CS(Spi::E, CS, Spi::CS0);
	spi0.set_SCK(Spi::E, SCK);
	spi0.set_MOSI(Spi::E, MOSI);
	spi0.set_MISO(Spi::E, MISO);
	spi0.set_baudrate(Spi::div16);
	spi0.set_cpha();
	spi0.set_cpol();
	spi0.set_f_size();

	while (1)
	{
		/*
		spi0.put_data(0xF0);
		delay_ms(1000);
		spi0.put_data(0x0F);
		delay_ms(1000);*/
	}
}
