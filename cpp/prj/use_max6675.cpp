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
Pit pit1 (Pit::ch1, 1, Pit::ms);
Max6675 sensor (spi0, Spi::CTAR0);
Hd44780 display;
Buffer temp (4);

const char char_celsium [8]=
{
	0x18,
	0x18,
	0x00,
	0x0F,
	0x09,
	0x08,
	0x09,
	0x0F
};

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
	temp.pars(sensor.getTemp());
	display.set_position(1, 1);
	display.send_string(3,temp.getArray());
}

int main ()
{
	sensor.set_CS (Gpio::E, CS, Gpio::Alt2, Spi::CS0);
	sensor.set_SCK (Gpio::E, SCK, Gpio::Alt2);
	sensor.set_MOSI (Gpio::E, MOSI, Gpio::Alt2);
	sensor.set_MISO (Gpio::E, MISO, Gpio::Alt2);
	display.set_position(0, 1);
	display.send_string("Heat Gun");
	display.newChar(char_celsium, 0);
	display.set_position(1, 4);
	display.data(0);
	/*pit1.interrupt_enable();
	pit1.start();*/

	while (1)
	{
		sensor.readCelsius();
		temp.pars(sensor.getTemp());
		display.set_position(1, 1);
		display.send_string(3,temp.getArray());
		delay_ms(500);
	}
}
