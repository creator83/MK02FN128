#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "gpio.h"

//Defenitions


#ifndef SHIFT_REGISTR_H
#define SHIFT_REGISTR_H

class Shift
{
private:
	Gpio CS, SCK, MOSI, MISO;
	Spi * mod;
	uint8_t N_CS;
	uint8_t N_CTAR;

//functions
public:
	Shift (Spi &, Spi::CTAR_number c);
	void setMode ();
	void send (uint8_t data);
	void set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m, Spi::CS_number);
	void set_SCK (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	void set_MOSI (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
};
#endif
