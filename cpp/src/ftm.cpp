#include "ftm.h"

FTM_MemMapPtr Ftm::ftm_ptr[3]={FTM0, FTM1, FTM2};


Ftm::Ftm (nFtm n_, sourceClock s)
{
	SIM->SCGC6 |= 1 << (SIM_SCGC6_FTM0_SHIFT+n_);
	FTM_MODE_REG(ftm_ptr[num_ftm]) |= FTM_MODE_WPDIS_MASK;
	num_ftm = n_;
	s_clock = s;
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~FTM_SC_CLKS_MASK;
}

void Ftm::setChannel (channel & ch)
{
	num_ch = ch;
}

void  Ftm::setDivision (division div)
{
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~FTM_SC_PS_MASK;
	FTM_SC_REG(ftm_ptr[num_ftm]) |= FTM_SC_PS(div);
}

void Ftm::setPeriod (const uint16_t &val)
{
	FTM_MOD_REG(ftm_ptr[num_ftm]) = val;
}

void Ftm::setChannelValue (const uint16_t &val)
{
	FTM_CnV_REG(ftm_ptr[num_ftm], num_ch) = val;
}

void Ftm::setInitValue (uint16_t &val)
{
	FTM_CNTIN_REG(ftm_ptr[num_ftm]) = val;

}

void Ftm::interruptEnable ()
{
	FTM_SC_REG(ftm_ptr[num_ftm]) |= FTM_SC_TOIE_MASK;
}

void Ftm::start ()
{
	FTM_SC_REG(ftm_ptr[num_ftm]) |= FTM_SC_CLKS(s_clock);
}

void Ftm::stop ()
{
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~FTM_SC_CLKS_MASK;
}

void Ftm::clearTofFlag ()
{
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~ FTM_SC_TOF_MASK;
}

