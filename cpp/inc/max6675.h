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
	enum {CS , SCK, MOSI, MISO};
	Spi spi0;
	

//functions
public:
	Max6675 ();
	uint16_t readCelsius();
	void buffer (uint16_t t);
};
#endif
