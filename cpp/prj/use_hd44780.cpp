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

struct buf
{
	uint8_t array [4];
	uint8_t n;
} buffer;

uint8_t number [10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


void buff_arr (uint16_t mes, buf * arr);


int main ()
{
	Hd44780 display;
	buffer.array[3] = '\0';
	display.set_position (1,7);
	display.send_string ((uint8_t*)"mk02fn128");
	display.newChar(s, 0);
	display.set_position (0,8);
	display.data(0);
	delay_ms(2000);
	display.Shift(Hd44780::Window, Hd44780::Right, 3);
	display.set_position (0,4);
	display.send_string ((uint8_t*)"Ha");
	delay_ms(2000);
	display.command(clear_counter);
	buff_arr (623, &buffer);
	display.set_position (0,1);
	display.send_string(buffer.n, &buffer.array [0]);
	display.set_position (1,2);
	display.send_string(&buffer.array[0]);
	display.set_position (0,10);
	display.send_string ((uint8_t*)"623");

	while (1)
	{/*
		display.Shift(Hd44780::Window, Hd44780::Left, 3);
		delay_ms(500);
		display.Shift(Hd44780::Window, Hd44780::Right, 3);
		delay_ms(500);*/
	}
}

void buff_arr (uint16_t mes, buf * arr)
{
	char hundr, dec, ones = 0;
	uint16_t temp = mes;
	for (hundr=0;temp>=100;++hundr)temp -=100;

	for (dec=0;temp>=10;++dec)temp -=10;

	for (ones=0;temp>=1;++ones)temp--;
	arr->array[2] = number [ones];
	arr->array[1] = number [dec];
	arr->array[0] = number [hundr];
	arr->n = 3;
}
