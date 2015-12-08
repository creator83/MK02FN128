#include "MK02F12810.h"                 // Device header

#define F_CPU 20971
#define BAUD  9600

#define RX 1
#define TX 0

#ifndef UART_H
#define UART_H

void init_uart0 (void);
void uart0_tx (uint8_t data);


#endif
