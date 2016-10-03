#include "MK02F12810.h"                 // Device header
#include "tact.h"
#include "delay.h"
#include "ftm.h"
#include "pwm.h"
#include "qd.h"
#include "hd44780.h"
#include "buffer.h"

extern "C"
{
	void FTM1_IRQHandler();
}

Tact frq;
Pwm led_pwm (Pwm::FTM_0, Pwm::ch0, Pwm::EdgePwm, Pwm::highPulse);
Qd encoder (100);
Hd44780 display;
Buffer val (3);

const uint8_t period = 100;
const uint8_t duty = 100;

void FTM1_IRQHandler()
{
	display.set_position(1,0);
	val.pars(encoder.getValue());
	display.send_string(3, val.getArray());
	led_pwm.setChannelValue(encoder.getValue());
}

void initPwm ();

int main ()
{
	display.set_position(0, 0);

	initPwm();
	while (1)
	{

		/*
		for (uint8_t i=100;i>0;--i)
		{
			led_pwm.setChannelValue(i);
			delay_ms(10);
		}*/
	}
}

void initPwm ()
{
	led_pwm.setDivision(Pwm::div4);
	led_pwm.setPeriod(period);
	led_pwm.setChannelValue(duty);
	led_pwm.start();
}
