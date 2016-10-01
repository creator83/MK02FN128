#include "ftm.h"

//FTM_MemMapPtr Ftm::ftm_ptr[3]={FTM0_BASE_PTR, FTM1_BASE_PTR, FTM2_BASE_PTR};

FTM_MemMapPtr Ftm::ftm_ptr[3]={FTM0, FTM1, FTM2};


Ftm::Ftm (N_FTM n_, channel ch, source_clock s)
{
	SIM->SCGC6 |= 1 << (24+n_);
	num_ftm = n_;
	n_ch = ch;
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~FTM_SC_CLKS_MASK;
	FTM_SC_REG(ftm_ptr[num_ftm]) |= FTM_SC_CLKS(s);
}

void  Ftm::setDivision (division div)
{
	FTM_SC_REG(ftm_ptr[num_ftm]) &= ~FTM_SC_PS_MASK;
	FTM_SC_REG(ftm_ptr[num_ftm]) |= FTM_SC_PS(div);
}

void setPeriod (uint16_t &val)
{

}

void setVal (uint16_t &val)
{

}

void setInitVal (uint16_t &val)
{

}

void Ftm::start ()
{
	//TPM_SC_REG(tpm_ptr [num_tpm]) |= TPM_SC_CMOD(1);
}

void Ftm::stop ()
{
	//TPM_SC_REG(tpm_ptr [num_tpm]) &= ~TPM_SC_CMOD_MASK;
}

