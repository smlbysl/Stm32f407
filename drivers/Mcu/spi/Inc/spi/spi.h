/*
 * spi.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_H_
#define MCU_SPI_INC_SPI_SPI_H_

#include "spi_private_types.h"


Std_ReturnType Spi_Asynch_SeqTrigger(Spi_SequenceIdType seqId);
void Spi_Init(const Spi_ConfigType* ConfigPtr);
void Spi_Main(void);
Std_ReturnType Spi_WriteTxIBBuffer(Spi_ChannelIdType chId, const uint16_t *DataBuffer);
#endif /* MCU_SPI_INC_SPI_SPI_H_ */

