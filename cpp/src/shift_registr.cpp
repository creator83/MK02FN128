#include "shift_registr.h"


Shift::Shift(Spi &s, Spi::CTAR_number c)
{
	mod = &s;
	N_CTAR = c;
	Spi::set_ctar(*mod, c);
	setMode();
}

void Shift::setMode ()
{
	Spi::set_cpha(*mod, Spi::first);
	Spi::set_cpol(*mod, Spi::neg);
	Spi::set_baudrate(*mod, Spi::div2);
	Spi::set_f_size(*mod);
}

void Shift::send (uint8_t data)
{
	mod->put_data(data, N_CS, N_CTAR);
	while (!mod->flag_tcf());
	mod->clear_flag_tcf();
}

void Shift::set_CS (Gpio::Port p, const uint8_t & pin, Gpio::mux m, Spi::CS_number n)
{
	CS.settingPinPort(p);
	CS.settingPin(pin, m);
	N_CS = n;
	SPI0->MCR |= SPI_MCR_PCSIS(1<<N_CS);
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



