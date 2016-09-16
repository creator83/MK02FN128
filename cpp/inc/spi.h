#include "MK02F12810.h"                  // Device header
#include "gpio.h"


/*
 Spi0
 Alt2
 E: CS0-16, SCK-17, MOSI-18,MISO-19
 C: CS4-0, CS3-1, CS2-2, CS1-3, CS0-4
 SCK-5, MOSI-6,MISO-7
 D: CS0-0, SCK-1, MOSI-2,MISO-3
 CS1-4, CS2-5, CS3-6
*/

#ifndef Spi_H
#define Spi_H


//typedef (Ctar_set*) Spi::setptr;



class Spi
{


//variables
public:
  enum Division {div2 , div4 , div8 , div16 , div32 , div64 , div128 , div256, div512};
  enum Role {slave , master};
  enum Cpol : uint8_t {neg, pos};
  enum Cpha {first, second};
  enum CS_number {CS0, CS1, CS2, CS3, CS4};
  enum CTAR_number {CTAR0, CTAR1};
  enum Fsize {bit_4=3, bit_5, bit_6, bit_7, bit_8, bit_9, bit_10, bit_11, bit_12, bit_13, bit_14, bit_15, bit_16};

  enum Mux {Alt0, Alt1, Alt2, Alt3, Alt4, Alt5, Alt6, Alt7};
  static uint8_t pins_d[4];
  enum PORT {C=2, D, E};



  /*uint8_t CS [2];
  uint8_t SCK [2];
  uint8_t MOSI [2];
  uint8_t MISO [2];*/




private:

  struct
  {
	  unsigned port : 3;
	  unsigned pin  : 5;
	  unsigned mux  : 3;
  }CS, SCK, MOSI, MISO;



static struct Ctar_set
  {
	  uint8_t cpol;
	  uint8_t cpha;
	  uint8_t f_size;
	  uint8_t lsbfe;
	  uint8_t dbr;
	  uint8_t pcssck;
	  uint8_t pask;
	  uint8_t pdt;
	  uint8_t pbr;
	  uint8_t cssck;
	  uint8_t asc;
	  uint8_t dt;
	  uint8_t br;
  }C0, C1;
  using ctarPtr = Spi::Ctar_set*;

  static ctarPtr s_ctar [2];

  //static Ctar_set * set_ctar [2];

  /*
  struct
  {
	  unsigned cpol    : 1;
	  unsigned cpha    : 1;
	  unsigned f_size  : 4;
	  unsigned lsbfe   : 1;
	  unsigned dbr     : 1;
	  unsigned pcssck  : 2;
	  unsigned pask    : 2;
	  unsigned pdt     : 2;
	  unsigned pbr     : 2;
	  unsigned cssck   : 4;
	  unsigned asc     : 4;
	  unsigned dt      : 4;
	  unsigned br      : 4;
  }Ctar0, Ctar1;*/

	uint8_t cs_N;
	uint8_t ctar_N;
	Gpio pin_CS;
	Gpio pin_SCK;
	Gpio pin_MOSI;
	Gpio pin_MISO;

//functions
public:

  Spi(Role r=master);

  void set_CS (PORT p, uint8_t pin, CS_number c, Mux m=Alt2);
  void set_SCK (PORT p, uint8_t pin, Mux m=Alt2);
  void set_MOSI (PORT p, uint8_t pin, Mux m=Alt2);
  void set_MISO (PORT p, uint8_t pin, Mux m=Alt2);
  void set_cpol (Cpol c = neg);
  void set_cpha (Cpha c = first);
  void set_f_size (Fsize f = bit_8);
  void set_baudrate (Division d);
  void set_ctar (uint8_t n);

  static void set_cpol (Spi &, Cpol c);
  static void set_cpha (Spi &, Cpha c);
  static void set_ctar (Spi &, uint8_t c);

  void settings ();
  void transmit (uint16_t data);
  uint8_t receive ();
  uint8_t exchange (uint8_t data);

  void assert_CS();


  void disassert_CS();

  void put_data (uint16_t data);
  uint16_t get_data ();
  bool flag_tcf ();

};



typedef uint16_t(Spi::*PotMemFn)() ;
typedef uint16_t(Spi::*ptr_ex)(uint16_t) ;

typedef void(Spi::*PotMemF)(uint16_t) ;

#endif

