#include "MK02F12810.h"                 // Device header
#include "gpio.h"
#include "tact.h"
#include "delay.h"


Tact frq;

const uint8_t led = 6;

int main ()
{
	Gpio D (Gpio::Port::D);
	D.settingPin(led);
	while (1)
	{
		D.toglePin (led);
		delay_ms(1000);
	}
}
