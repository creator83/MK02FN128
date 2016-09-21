#include "shift_registr.h"


Shift::Shift(Spi &s, Spi::CTAR_number c)
{
	mod = &s;
	Spi::set_ctar(*mod, c);
	setMode();
}

void Shift::setMode ()
{
	Spi::set_cpha(*mod, Spi::first);
	Spi::set_cpol(*mod, Spi::neg);
	Spi::set_baudrate(*mod, Spi::div32);
}

void Shift::send (uint8_t data)
{
	mod->put_data(data);
	while (!mod->flag_tcf());
}

void Shift::set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	CS.settingPinPort(p);
	CS.settingPin(pin, m);
}

void Shift::set_SCK (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	SCK.settingPinPort(p);
	SCK.settingPin(pin, m);

}

void Shift::set_MOSI (Gpio::Port p, const uint8_t & pin, Gpio::mux m)
{
	MOSI.settingPinPort(p);
	MOSI.settingPin(pin, m);
}



