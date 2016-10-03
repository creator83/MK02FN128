#include "MK02F12810.h"
#include "gpio.h"
#include "ftm.h"

/*
 * FTM1
 * PHA - PTA12 (Alt7)
 * PHB - PTA13 (Alt7)
 * PHA - PTB0 (Alt6)
 * PHB - PTB1 (Alt6)
 *
 * FTM2
 * PHA - PTB18 (Alt6)
 * PHB - PTB19 (Alt6)
 */

namespace QdDef
{
//===Defenitions===//
const Ftm::nFtm N = Ftm::FTM_1;
//PHA
const Gpio::Port PhaPort = Gpio::A;
const Gpio::mux PhaAlt = Gpio::Alt7;
const uint8_t PhaPin = 12;

//PHB
const Gpio::Port PhbPort = Gpio::A;
const Gpio::mux PhbAlt = Gpio::Alt7;
const uint8_t PhbPin = 13;
}




#ifndef PWM_H
#define PWM_H


class Qd : public Ftm
{
  //variables
public:

private:
	Gpio pha, phb;


public:
	Qd ();
	void setMode ();

private:

};



#endif
