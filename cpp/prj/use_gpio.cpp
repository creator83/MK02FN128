#include "MK02F12810.h"                 // Device header
#include "gpio.h"
#include "tact.h"

Tact frq;

const uint8_t led = 1;

int main ()
{
	Gpio A (Gpio::A);
	A.settingPin (led);
	A.setPin(led);

	while (1)
	{
	}
}
