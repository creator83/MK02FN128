#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "gpio.h"

//Defenitions


#ifndef SHIFT_REGISTR_H
#define SHIFT_REGISTR_H

class Shift
{
//variables
public:
/*	enum CTAR_number: uint8_t {CTAR0, CTAR1};
	enum Port :uint8_t {A , B , C , D , E};
	enum mux :uint8_t {Alt2 = 2 , Alt3 , Alt4 , Alt5 , Alt6 , Alt7};*/
private:
	Gpio CS, SCK, MOSI, MISO;
	Spi * mod;

//functions
public:
	Shift (Spi &, Spi::CTAR_number c);
	void setMode ();
	void send (uint8_t data);
	void set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	void set_SCK (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	void set_MOSI (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
};
#endif
