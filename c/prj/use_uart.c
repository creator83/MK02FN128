#include "MK02F12810.h"                 // Device header
#include "tact.h"
#include "uart.h"


int main ()
{
	
	init_uart0();
	uart0_tx (0xFF);
	
	while (1)
	{
		
	}
}
