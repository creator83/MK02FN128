#include "MK02F12810.h"                 // Device header
#include "spi.h"

//Defenitions


#ifndef SHIFT_REGISTR_H
#define SHIFT_REGISTR_H

class Shift
{
//variables
public:
	enum CTAR_number: uint8_t {CTAR0, CTAR1};
private:

	Spi * mod;

//functions
public:
	Shift (Spi &, CTAR_number c);
	void setCpol ();
	void setCpha ();
};
#endif
