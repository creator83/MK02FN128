#include "shift_registr.h"


Shift::Shift(Spi &s, CTAR_number c)
{
	mod = &s;
	Spi::set_ctar(*mod, c);
}





