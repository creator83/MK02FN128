#include "MK02F12810.h"
#include "gpio.h"
#include "ftm.h"


#ifndef PWM_H
#define PWM_H


class Pwm : public Ftm
{
  //variables
public:

	enum MODE {Input, Output_toggle, Output_pulse, Edge_Pwm, Center_Pwm, Software_compare};
	enum division {div1, div2, div4, div8, div16, div32, div64, div128};
	enum toggle_mode {toggle=1, clear, set};
	enum pulse_mode {output_high=1, output_low};
	enum e_pwm_mode {low_pulse=1, high_pulse};

private:
	Gpio pin;


public:
	Pwm (N_FTM n_, channel ch);
	void setModulo (uint16_t val);
	void setDivision (division d);
	void setCount (uint16_t val);
	void clear_flag ();
	void start ();
	void stop ();

private:

};

#endif
