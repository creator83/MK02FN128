#include "Spi.h"

Spi::Ctar_set* Spi::set [2] = {&Spi::C0, &Spi::C1};


Spi::Spi(CTAR_number n, Role r)

{
  //===Settings pins===//

  //Settings pins SCK, MOSI, MISO as ALT3

  //Turn on tacting Spi1
  SIM->SCGC6 |= SIM_SCGC6_SPI0_MASK;

  //===Settings Spi1===//
  //Settings number CTAR
  ctar_N = n;

  //Settings role
  SPI0->MCR &= ~ SPI_MCR_MSTR_MASK;
  SPI0->MCR |= r << SPI_MCR_MSTR_SHIFT;

  //Start
  SPI0->MCR &= ~SPI_MCR_HALT_MASK;

}

void Spi::set_CS (PORT p, uint8_t pin, CS_number c,  Mux m)
{
	pin_CS.settingPinPort(p);
	pin_CS.settingPin(pin, m);
	cs_N = c;
	CS.port = p;
	CS.pin = pin;
	CS.mux = m;
}

void Spi::set_SCK (PORT p, uint8_t pin, Mux m)
{
	pin_SCK.settingPinPort(p);
	pin_SCK.settingPin(pin, m);
	SCK.port = p;
	SCK.pin = pin;
	SCK.mux = m;
}

void Spi::set_MOSI (PORT p, uint8_t pin, Mux m)
{
	pin_MOSI.settingPinPort(p);
	pin_MOSI.settingPin(pin, m);
	MOSI.port = p;
	MOSI.pin = pin;
	MOSI.mux = m;
}

void Spi::set_MISO (PORT p, uint8_t pin, Mux m)
{
	pin_MISO.settingPinPort(p);
	pin_MISO.settingPin(pin, m);
	MISO.port = p;
	MISO.pin = pin;
	MISO.mux = m;
}

void Spi::set_cpol (Cpol c)
{
	C1.cpol = c;
	SPI0_CTAR(ctar_N) = SPI_CTAR_SLAVE_CPOL(c);
}

void Spi::set_cpha (Cpha c)
{
	C1.cpha = c;
	SPI0_CTAR(ctar_N) = SPI_CTAR_SLAVE_CPHA(c);
}

void Spi::set_f_size (Fsize f)
{
	C1.f_size = f;
	SPI0_CTAR(ctar_N) = SPI_CTAR_FMSZ(f);
}

void Spi::set_baudrate (Division d)
{
	//C1.br = d;
	SPI0_CTAR(ctar_N) = SPI_CTAR_BR (d);
}


void Spi::transmit (uint8_t data)
{

}


uint8_t Spi::receive ()
{

}

uint8_t Spi::exchange (uint8_t data)
{

}

void Spi::put_data (uint8_t data)
{
	SPI0->PUSHR = SPI_PUSHR_PCS(cs_N)|SPI_PUSHR_TXDATA(data);
}

uint8_t Spi::get_data ()
{

}

bool Spi::flag_tcf ()
{
	return SPI0->SR&SPI_SR_TCF_MASK;
}

void Spi::assert_CS()
{
	pin_CS.clearPin(CS.pin);
}

void Spi::disassert_CS()
{
	pin_CS.setPin(CS.pin);
}
