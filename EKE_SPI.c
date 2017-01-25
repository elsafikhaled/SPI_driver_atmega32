/*
 * EKE_SPI.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "EKE_SPI.h"

void EKE_SPI_init(U8_t MA_SLA_select,U8_t interrEN)
{
	/*************   INITIALIZATION 1  **************/

	                          
	SPCR|=(1<<SPE)|(1<<DORD)|(1<<SPR1)|(1<<SPR0);	 // SPI Enable ,transfer LSB first ,
	                                                 // frequency prescaller  by default 64

   // clock polarity
	SPCR&=~(1<<CPOL)|(1<<CPHA);
	

	/************   INTERRUPT INIT  2  ***************/

	if(interrEN==1)
	{
      sei();
      SPCR|=(1<<SPIE);
      SPSR&=~(1<<SPIF);
	}
	else {SPCR&=~(1<<SPIE);}

	/***********  Master >> slave select mode  ********/

	if(MA_SLA_select==1)
	{
	   // Master
       SPCR|=(1<<MSTR);
       // configure pin in AVR Miso Mosi Sck SS
       EKE_DIO_InitPin('B',5,output); // Mosi output
       EKE_DIO_InitPin('B',4,output); // ss   output
       EKE_DIO_InitPin('B',7,output); // SCK  output
       EKE_DIO_InitPin('B',6,input) ; // Miso input

	}
	else
	{
	  // Slave
	  SPCR&=~(1<<MSTR);
	  // configure pin in AVR Miso Mosi Sck SS
	  EKE_DIO_InitPin('B',5,input) ; // Mosi input
	  EKE_DIO_InitPin('B',4,input) ; // ss   input
	  EKE_DIO_InitPin('B',7,input) ; // SCK  input
	  EKE_DIO_InitPin('B',6,output); // Miso output

	}

}

// /////////////////////////////////////////////////////////////////////////////////////////


/*******************  Mater API function    *****************************/


void EKE_SPI_master(U8_t DATA)
{
	SPDR=DATA;
	while(!(SPSR&(1<<SPIF)));
}

/****************** Slave API function   *******************************/

U8_t EKE_SPI_slave(void)
{
	while(!(SPSR&(1<<SPIF)));
	return SPDR;

}
// ///////////////////////////////////////////////////////////////////////////////////////////



