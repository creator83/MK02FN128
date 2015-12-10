#include "MK02F12810.h"                 // Device header
#include "tact.h"
#include "uart.h"

#define SCK  17
#define MOSI 18
#define MISO 19

#define MASTER 31
#define CPOL 26
#define CPHA 25

void init_spi (void)
{
	
	//init pins
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR [SCK] |= PORT_PCR_MUX(2);
	PORTE->PCR [MOSI] |= PORT_PCR_MUX(2);
	PORTE->PCR [MISO] |= PORT_PCR_MUX(2);
	PTE->PDDR |= 1 << SCK;
	PTE->PDDR |= 1 << MOSI;
	
	//init spi
	SIM->SCGC6 |= SIM_SCGC6_SPI0_MASK;
	SPI0->MCR |= 1 << 31;
	//SPI0->CTAR |= 
}

int main ()
{
	
	init_uart0();
	uart0_tx (0xFF);
	
	while (1)
	{
		
	}
}
