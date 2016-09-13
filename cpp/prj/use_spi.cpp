#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "tact.h"
#include "delay.h"


Tact frq;

const uint8_t CS   = 16;
const uint8_t SCK  = 17;
const uint8_t MOSI = 18;
const uint8_t MISO = 19;

int main ()
{
	Spi spi0;
	spi0.set_CS(Spi::E, CS, Spi::CS0);
	spi0.set_SCK(Spi::E, SCK);
	spi0.set_MOSI(Spi::E, MOSI);
	spi0.set_MISO(Spi::E, MISO);
	spi0.set_baudrate(Spi::div16);


	while (1)
	{

	}
}
