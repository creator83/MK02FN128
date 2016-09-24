#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "tact.h"
#include "delay.h"
#include "pit.h"
#include "max6675.h"
#include "buffer.h"
#include "hd44780.h"




Tact frq;
Spi spi0;
Pit pit1 (Pit::ch1, 500, Pit::ms);
Max6675 sensor (spi0, Spi::CTAR0);

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
	sensor.readCelsius();
}

int main ()
{

	pit1.interrupt_enable();
	sensor.set_CS (Gpio::E, CS, Gpio::Alt2, Spi::CS0);
	sensor.set_SCK (Gpio::E, SCK, Gpio::Alt2);
	sensor.set_MOSI (Gpio::E, MOSI, Gpio::Alt2);
	sensor.set_MISO (Gpio::E, MISO, Gpio::Alt2);


	while (1)
	{
		/*
		spi0.put_data(0xF0);
		delay_ms(1000);
		spi0.put_data(0x0F);
		delay_ms(1000);*/
	}
}
