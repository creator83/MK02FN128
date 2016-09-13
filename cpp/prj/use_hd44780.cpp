#include "MK02F12810.h"                 // Device header
#include "gpio.h"
#include "tact.h"
#include "delay.h"
#include "hd44780.h"

Tact frq;

const uint8_t led = 6;

uint8_t s [8]
		   { 0x1F,
		   0x1F,
		   0x1F,
		   0x1F,
		   0x1F,
		   0x1F,
		   0x1F,
		   0x1F,
		   };

int main ()
{
	Hd44780 display;
	display.set_position (0,7);
	display.send_string ((uint8_t*)"HelloFrom");
	display.newChar(s, 0);
	display.set_position (1,2);
	display.data(0);
	Gpio D (Gpio::D);
	D.settingPin(led);
	while (1)
	{
		D.changePinState(led);
		delay_ms(1000);
	}
}
