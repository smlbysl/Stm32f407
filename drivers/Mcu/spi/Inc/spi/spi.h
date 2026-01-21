/*
 * spi.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_H_
#define MCU_SPI_INC_SPI_SPI_H_

#include "spi_private_types.h"



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Global Variables Definition -------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */
void Spi_Init(const Spi_ConfigType* ConfigPtr);
void Spi_Main(void);
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceIdType seqId);
Std_ReturnType Spi_WriteIB(Spi_ChannelIdType chId, const uint8_t *DataBuffer);
Std_ReturnType Spi_ReadIB(Spi_ChannelIdType chId, const uint8_t *DataBuffer);
Std_ReturnType Spi_SetupEB( Spi_ChannelIdType Channel,
							const uint16_t* SrcDataBufferPtr,
							uint16_t* DesDataBufferPtr,
							uint8_t Length );
Std_ReturnType Spi_SyncTransmit (Spi_SequenceIdType Sequence);

#endif /* MCU_SPI_INC_SPI_SPI_H_ */

