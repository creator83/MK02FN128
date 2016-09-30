#include "MK02F12810.h"
#include "gpio.h"
#include "ftm.h"


#ifndef PWM_H
#define PWM_H


class Pwm : public Ftm
{
  //variables
public:

	enum mode {Input, Output_toggle, Output_pulse, Edge_Pwm, Center_Pwm, Software_compare};
	enum toggleMode {toggle=1, clear, set};
	enum pulseMode {output_high=1, output_low};
	enum e_pwm_mode {low_pulse=1, high_pulse};

private:
	Gpio pin;


public:
	Pwm (nFtm n_, channel ch);
	void setModulo (uint16_t val);
	void setDivision (division d);
	void setCount (uint16_t val);
	void clear_flag ();
	void start ();
	void stop ();

private:

};

#endif
