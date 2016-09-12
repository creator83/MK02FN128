#include "MK02F12810.h"                 // Device header

#ifndef GPIO_H
#define GPIO_H

typedef uint32_t* reg;


class Gpio
{
//variables
public:
  enum Port {A , B , C , D , E};
  enum mux {Analog, GPIO , Alt2 , Alt3 , Alt4 , Alt5 , Alt6 , Alt7};
  enum mode {Input, Output};
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
  static PORT_MemMapPtr PortBase [5];
  static GPIO_MemMapPtr GpioBase [5];
//static unsigned int pAdr [3];	
  unsigned char prt;
//functions
public:
  Gpio(Port p );
  Gpio(uint8_t p );
  //function for pins
  void settingPin (uint8_t pin , mux mx = GPIO, mode m = Output);
  void setPin (unsigned int pin );
  void clearPin (unsigned char pin);
  void changePinState (unsigned char pin);
  void setPinState (unsigned char pin , unsigned char state);
  bool pinState (unsigned char pin);

  //function for port
  void settingPort (uint32_t val, mux mx = GPIO, mode m = Output);
  void setValPort (uint32_t value);
  void clearValPort (uint32_t value);

};

#endif



