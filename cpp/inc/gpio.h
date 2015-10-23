#include "MK02F12810.h"                 // Device header

#ifndef GPIO_H
#define GPIO_H

typedef uint32_t* reg;


class gpio
{
//variables
public:
  enum Port {A , B , C , D , E};
  enum mode {Analog , GPIO , Alt1 , Alt2 , Alt3 , Alt4 , Alt5 , Alt6 , Alt7};
  enum speed {Low = 0 , Medium = 1 , High=3};
  enum out {PushPull , OpenDrain};
  enum PP {NoPP , PullUp , PullDown};
  enum rgstr {
  PDOR = 0x00,
  PSOR = 0x04,
  PCOR = 0x08,
  PTOR = 0x0C,
  PDIR = 0x10,
  PDDR = 0x14
};
private:
  static uint32_t PortBase [5];
  static uint32_t GpioBase [5];
//static unsigned int pAdr [3];	
  unsigned char prt;
//functions
public:
  gpio(Port p );
  gpio(uint8_t p );
  void setOutPin (unsigned char pin , mode m = GPIO , out o = PushPull);	
  void setInPin (unsigned char pin , PP p = NoPP);
  void setPin (unsigned int pin );
  void clearPin (unsigned char pin);	
  void setValPort (uint32_t value);	
  void setOutPort (unsigned int value, speed s = Low );		
  void ChangePinState (unsigned char pin);
  void SetPinState (unsigned char pin , unsigned char state);
  void PuPd (unsigned char pin , PP p);
  bool PinState (unsigned char pin);
};


#endif



