#include "MK02F12810.h"                 // Device header
#include "gpio.h"
#include "tact.h"
#include "delay.h"
#include "hd44780.h"
#include "buffer.h"


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

const char * menu_iron = "Solder Iron";
const char * menu_heat_gun = "Heat Gun";


int main ()
{
	Buffer temp (3);
		Hd44780 display;

	display.set_position (1,7);
	display.send_string ("mk02fn128");
	display.newChar(s, 0);
	display.set_position (0,8);
	display.data(0);
	delay_ms(2000);
	display.Shift(Hd44780::Window, Hd44780::Right, 3);
	display.set_position (0,4);
	display.send_string ("Ha");
	delay_ms(2000);
	display.command(clear_counter);
	temp.pars(356);
	display.set_position (1,1);
	display.send_string (temp.getArray());
	display.set_position (0,1);
	display.send_string (menu_iron);
	display.set_position(0, 17);
	display.send_string (menu_heat_gun);

	while (1)
	{/*
		display.Shift(Hd44780::Window, Hd44780::Left, 3);
		delay_ms(500);
		display.Shift(Hd44780::Window, Hd44780::Right, 3);
		delay_ms(500);*/
	}
}


