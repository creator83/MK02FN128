#include "max6675.h"


char Max6675::number [10] = {'0','1','2','3','4','5','6','7','8','9'};

Max6675::Max6675 ()
:spi0 (Spi::CTAR1)
{
	spi0.set_CS(Spi::D, CS, Spi::CS0);
	spi0.set_SCK(Spi::E, SCK);
	spi0.set_MOSI(Spi::E, MOSI);
	spi0.set_MISO(Spi::E, MISO);
	spi0.set_baudrate(Spi::div32);
	spi0.set_cpol();
	spi0.set_cpha(Spi::second);
	spi0.set_f_size(Spi::bit_16);
}

uint16_t Max6675::readCelsius()
{
	/*union
	{
		uint16_t full_val;
		uint8_t half_val[2];
	}val;*/
	uint16_t val;
	spi0.put_data(0);
	while (!spi0.flag_tcf());
	val = spi0.get_data();


	if (val & 0x4)
	  {
    // uh oh, no thermocouple attached!
    return 0; 
    //return -100;
  }
	val *=10;
	return val>>=5;;
}



void Max6675::buffer (uint16_t t)
{
	char dec, ones;
	uint16_t temp = t;
	
	for (dec=0;temp>=10;++dec)temp -=10;

	for (ones=0;temp>=1;++ones)temp--;
	
	buffer_value [0]= number [dec];
	buffer_value [1]= number [ones];
}


