#include "MK02F12810.h"
#include "tact.h"


#ifndef FTM_H
#define FTM_H


class Ftm
{
  //variables
public:
	enum channel : uint8_t {ch0, ch1, ch2, ch3, ch4, ch5};
	enum N_FTM : uint8_t {FTM_0, FTM_1, FTM_2};
	enum source_clock : uint8_t {Off, System_clk, Fixed_clk, Ext_clk};
	enum MODE {Input, Output_toggle, Output_pulse, Edge_Pwm, Center_Pwm, Software_compare};
	enum division : uint8_t {div1, div2, div4, div8, div16, div32, div64, div128};
	enum toggle_mode {toggle=1, clear, set};
	enum pulse_mode {output_high=1, output_low};
	enum e_pwm_mode {low_pulse=1, high_pulse};
	uint8_t n_ch;
	uint8_t num_ftm;
private:

	static FTM_MemMapPtr ftm_ptr[3];


public:
	Ftm (N_FTM n_, channel ch, source_clock s = System_clk);
	void setDivision (division div);
	void clear_flag ();
	void start ();
	void stop ();

private:

};

#endif
