#include "MK02F12810.h"                 // Device header
#include "gpio.h"
#include "tact.h"
#include "delay.h"
#include "buffer.h"

Tact frq;

const uint8_t led = 6;

int main ()
{
	Buffer <uint8_t> val (5);
	Gpio * pins [2];

	Gpio D (Gpio::Port::D);
	D.settingPin(led);
	pins[0] = &D;
	pins[0]->setPin(led);
	while (1)
	{
		D.toglePin (led);
		delay_ms(1000);
	}
}
