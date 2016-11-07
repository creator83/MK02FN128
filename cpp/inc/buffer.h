#include "MK02F12810.h"


#ifndef BUFFER_H
#define BUFFER_H

template <typename T>
class Buffer
{
public:

private:
	static const uint8_t Array_char [10];
	static const uint8_t ArraySegChar [11];
	static const uint8_t ArraySegDpChar [11];
	uint8_t n;
	uint8_t count;
	uint8_t size;
	T arr [];
	T* real;

public:
	Buffer(uint8_t size_);
	void pars (const uint16_t &);
	bool setElement (uint8_t el, uint8_t val);
	uint8_t getArraySize ();
	T * getArray ();
	T * getElement (uint8_t n);
};

	
#endif
