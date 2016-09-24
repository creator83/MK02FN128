#include "MK02F12810.h"                 // Device header
#include "spi.h"
#include "delay.h"


//Defenitions


#ifndef MAX6675_H
#define MAX6675_H

class Max6675
{
//variables
public:
	char buffer_value[2];
	static char number [10];
private:
	Gpio CS, SCK, MOSI, MISO;
	Spi * mod;
	uint8_t N_CS;
	uint8_t N_CTAR;
	uint16_t byte_code;
//functions
public:
	Max6675 (Spi &s, Spi::CTAR_number c);
	void setMode ();
	bool readCelsius();
	void set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m, Spi::CS_number);
	void set_SCK (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	void set_MOSI (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	void set_MISO (Gpio::Port p, const uint8_t & pin, Gpio::mux m);
	uint16_t & getTemp ();
};

#endif
