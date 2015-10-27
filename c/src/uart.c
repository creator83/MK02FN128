#include "uart.h"


void init_uart0 (void)
{
	uint16_t ubd, bfra;
	uint8_t temp;
	//Settings pins
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR [RX] |= PORT_PCR_MUX(3);
	PORTE->PCR [TX] |= PORT_PCR_MUX(3);
	PTE->PDDR |= 1 << TX;
	
	//Settings uart
	SIM->SCGC4 |= SIM_SCGC4_UART1_MASK;
	UART1->C2 &= ~(UART_C2_TE_MASK|UART_C2_RE_MASK);
	UART1->C1 = 0;
	ubd = (uint16_t) ((F_CPU*1000)/(BAUD*16));
	temp = UART1->BDH & ~(UART_BDH_SBR(0x1F));
	UART1->BDH = temp | UART_BDH_SBR(((ubd & 0x1F00) >> 8));
	UART1->BDL = (uint8_t) (ubd & UART_BDL_SBR_MASK);
	bfra = (((F_CPU*32000)/(BAUD*16)) - (ubd*32));
	temp = UART1->C4 & ~(UART_C4_BRFA(0x1F));
	UART1->C4 = temp | UART_C4_BRFA(bfra);
	UART1->C2 |= UART_C2_RE_MASK|UART_C2_TE_MASK;	
}

void uart0_tx (uint8_t data)
{
}
