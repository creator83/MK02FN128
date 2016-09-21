#include "Spi.h"

Spi::Ctar_set Spi::C1;
Spi::Ctar_set Spi::C0;

//Spi::Ctar_set* Spi::set_ctar [2] = {&Spi::C0, &Spi::C1};
Spi::ctarPtr Spi::s_ctar [2] = {&Spi::C0, &Spi::C1};

void Spi::set_cpol (Spi &s, Cpol c)
{
	s.set_cpol(c);
}

void Spi::set_cpha (Spi &s, Cpha c)
{
	s.set_cpha(c);
}

void Spi::set_ctar (uint8_t n)
{
	ctar_N = n;
}

void Spi::set_ctar (Spi &s, uint8_t c)
{
	s.set_ctar(c);
}

void Spi::set_baudrate (Spi &s, Division d)
{
	s.set_baudrate(d);
}



Spi::Spi( Role r)
{
  //Turn on tacting Spi1
  SIM->SCGC6 |= SIM_SCGC6_SPI0_MASK;

  //Settings role and turn off tx and rx fifo
  SPI0->MCR &= ~ (SPI_MCR_MSTR_MASK|SPI_MCR_DIS_TXF_MASK|SPI_MCR_DIS_RXF_MASK);
  SPI0->MCR |= r << SPI_MCR_MSTR_SHIFT;

  //Start
  SPI0->SR |= SPI_SR_EOQF_MASK;
  SPI0->MCR &= ~(SPI_MCR_HALT_MASK|SPI_MCR_FRZ_MASK);
}

void Spi::set_cpol (Cpol c)
{
	s_ctar [ctar_N]->cpol = c;
	SPI0_CTAR(ctar_N) = SPI_CTAR_SLAVE_CPOL(c);
}

void Spi::set_cpha (Cpha c)
{
	s_ctar [ctar_N]->cpha = c;
	SPI0_CTAR(ctar_N) = SPI_CTAR_SLAVE_CPHA(c);
}

void Spi::set_f_size (Fsize f)
{
	s_ctar [ctar_N]->f_size = f;
	SPI0_CTAR(ctar_N) = SPI_CTAR_FMSZ(f);
}

void Spi::set_baudrate (Division d)
{
	s_ctar [ctar_N]->br = d;
	SPI0_CTAR(ctar_N) = SPI_CTAR_BR (d);
}


void Spi::transmit (uint16_t data)
{

}


uint8_t Spi::receive ()
{

}

uint8_t Spi::exchange (uint8_t data)
{

}

void Spi::put_data (uint16_t data)
{
	SPI0->PUSHR = SPI_PUSHR_PCS(cs_N)|SPI_PUSHR_TXDATA(data);
}

uint16_t Spi::get_data ()
{
	return  SPI0->POPR; //(uint16_t)
}

bool Spi::flag_tcf ()
{
	return SPI0->SR&SPI_SR_TCF_MASK;
}

bool Spi::flag_tfff ()
{
	return SPI0->SR&SPI_SR_TFFF_MASK;
}

bool Spi::flag_tfuf ()
{
	return SPI0->SR&SPI_SR_TFUF_MASK;
}

