#include "MK02F12810.h"
#include "gpio.h"
#include "ftm.h"


#ifndef PWM_H
#define PWM_H


class Pwm : public Ftm
{
  //variables
public:
	enum alt_mode {Alt0, Alt1, Alt2, Alt3, Alt4, Alt5, Alt6};
	enum MODE {Input, Output_toggle, Output_pulse, Edge_Pwm, Center_Pwm, Software_compare};
	enum division {div1, div2, div4, div8, div16, div32, div64, div128};
	enum toggle_mode {toggle=1, clear, set};
	enum pulse_mode {output_high=1, output_low};
	enum e_pwm_mode {low_pulse=1, high_pulse};

private:
	Gpio pin;


public:
	Pwm (N_FTM n_, channel ch);

	void clear_flag ();
	void start ();
	void stop ();

private:

};

#endif
