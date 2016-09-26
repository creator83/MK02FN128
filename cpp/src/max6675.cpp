#include "max6675.h"




Max6675::Max6675 (Spi &s, Spi::CTAR_number c)
{
	mod = &s;
	N_CTAR = c;
	Spi::set_ctar(*mod, c);
	setMode();
}

void Max6675::setMode ()
{
	Spi::set_cpha(*mod, Spi::second);
	Spi::set_cpol(*mod, Spi::neg);
	Spi::set_baudrate(*mod, Spi::div32);
	Spi::set_f_size(*mod, Spi::bit_16);
}

bool Max6675::readCelsius()
{
	mod->put_data(0, N_CS, N_CTAR);
	//while (!mod->flag_rfdf());

	while (!mod->flag_tcf());
	byte_code = mod->get_data();
	mod->clear_flag_tcf();
	//mod->clear_flag_rfdf();
	if (byte_code & 0x4)
	  {
    // uh oh, no thermocouple attached!
    return false;
    //return -100;
  }
	byte_code *=10;
	byte_code>>=5;
	return true;
}

void Max6675::set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m, Spi::CS_number n)
{
	CS.settingPinPort(p);
	CS.settingPin(pin, m);
	N_CS = n;
	SPI0->MCR |= SPI_MCR_PCSIS(1<<N_CS);
}

void Max6675::set_SCK (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	SCK.settingPinPort(p);
	SCK.settingPin(pin, m);
}

void Max6675::set_MOSI (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	MOSI.settingPinPort(p);
	MOSI.settingPin(pin, m);
}

void Max6675::set_MISO (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	MISO.settingPinPort(p);
	MISO.settingPin(pin, m);
}

uint16_t & Max6675::getTemp ()
{
	return byte_code;
}
