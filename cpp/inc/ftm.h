#include "MK02F12810.h"
#include "tact.h"


#ifndef FTM_H
#define FTM_H


class Ftm
{
  //variables
public:
	enum channel : uint8_t {ch0, ch1, ch2, ch3, ch4, ch5};
	enum nFtm : uint8_t {FTM_0, FTM_1, FTM_2};
	enum sourceClock : uint8_t {Off, System_clk, Fixed_clk, Ext_clk};
	enum division : uint8_t {div1, div2, div4, div8, div16, div32, div64, div128};


private:
	channel num_ch;
	nFtm num_ftm;
	sourceClock s_clock;
	static FTM_MemMapPtr ftm_ptr[3];


public:
	Ftm (nFtm n_, channel ch, sourceClock s = System_clk);
	void setDivision (division & div);
	void setPeriod (uint16_t &);
	void setVal (uint16_t &);
	void setInitVal (uint16_t &);
	void clear_flag ();
	void start ();
	void stop ();

private:

};

#endif
