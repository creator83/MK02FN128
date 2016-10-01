#include "MK02F12810.h"                 // Device header
#include "tact.h"
#include "delay.h"
#include "ftm.h"
#include "pwm.h"


Tact frq;
Pwm led_pwm (Pwm::FTM_0, Pwm::ch0, Pwm::EdgePwm, Pwm::highPulse);
const uint8_t period = 100;
const uint8_t duty = 100;


void initPwm ();

int main ()
{

	initPwm();
	while (1)
	{
		for (uint8_t i=100;i>0;--i)
		{
			led_pwm.setChannelValue(i);
			delay_ms(10);
		}
	}
}

void initPwm ()
{
	led_pwm.setDivision(Pwm::div1);
	led_pwm.setPeriod(period);
	led_pwm.setChannelValue(duty);
	led_pwm.start();
}
