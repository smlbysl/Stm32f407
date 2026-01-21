/*
 * spi_channel.h
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_CHANNEL_H_
#define MCU_SPI_INC_SPI_SPI_CHANNEL_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private_types.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
#define SPI_CHANNELLENGTH_MAX 1u
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Global Variables Definition -------------------------------------- */
extern Spi_ChannelRuntimeType		channelRnt[SPI_CHANNEL_MAX];
/* ========================================================================================================= */
/* -------------------------------------- API Definitions  ------------------------------------------------- */
/* --------------------------------------------------------------------------------------------------------- */
Std_ReturnType Spi_Channel_ReadRxIBBuffer(Spi_ChannelIdType chId, uint16_t *DataBuffer);
Std_ReturnType Spi_Channel_WriteTxIBBuffer(Spi_ChannelIdType chId, const uint16_t *DataBuffer);
Std_ReturnType Spi_ChannelHandler_StartAsynch(Spi_HwUnitIdType hwId, Spi_ChannelIdType chId);
Std_ReturnType Spi_ChannelHandler_EndAsynch(Spi_HwUnitIdType hwId);
Std_ReturnType Spi_ChannelHandler_StartPooling(Spi_HwUnitIdType hwId, Spi_ChannelIdType chId);
void Spi_Channel_Init(void);
void Spi_Channel_Callback(Spi_HwUnitIdType hwID);

#endif /* MCU_SPI_INC_SPI_SPI_CHANNEL_H_ */
