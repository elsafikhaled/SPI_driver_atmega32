/*
 * EKE_SPI.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#include "C:\EL-SAFI\Embedded Systems\Embedded fab\EKE   MY Dr.layers\Microcontroller Abstraction Layers\SPI\DIO LAYER\DIO_layer.h"
#include "C:\EL-SAFI\Embedded Systems\Embedded fab\EKE   MY Dr.layers\Microcontroller Abstraction Layers\SPI\DIO LAYER\std_data_types_EKE.h"
#include "EKE_SPI_CONFIG.h"


#ifndef EKE_SPI_H_
#define EKE_SPI_H_

void EKE_SPI_init(U8_t MA_SLA_select,U8_t interrEN);
/**********************************************************************
 * Function    :: void EKE_SPI_init(U8_t MA_SLA_select,U8_t interrEN);
 *
 * Paramaters  :: MA_SLA_select, interrEN
 *
 * Discription :: MA_SLA_select  - master --->  pass 1
 *                               - slave  --->  pass 0
 *                interrEN       - Enable --->  pass 1
 *                               - Disable--->  pass 0
 * return      :: void
 *********************************************************************/

void EKE_SPI_master(U8_t DATA);
/**********************************************************************
 *Function    :: void EKE_SPI_master(U8_t DATA);
 *
 *Parameters  :: DATA
 *
 *Discription ::DATA which will be transfers to slave
 *
 *return      :: void
 *
 *********************************************************************/

U8_t EKE_SPI_slave(void);
/**********************************************************************
 *Function    :: U8_t EKE_SPI_slave(void);
 *
 *Parameters  :: void
 *
 *Discription :: DATA which will  be recieved from master
 *
 *return      :: Data
 *
 *********************************************************************/

#endif /* EKE_SPI_H_ */
