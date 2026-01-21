/*
 * spi_channel_cfg.h
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_CHANNEL_CFG_H_
#define MCU_SPI_INC_SPI_SPI_CHANNEL_CFG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private_types.h"
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
#define SPI_JOB1_CHANNEL_MAX	1u
#define SPI_JOB2_CHANNEL_MAX	2u
#define SPI_CHANNEL_LENGTH_MAX	1u
/* ========================================================================================================= */
/* -------------------------------------- Global Variables Definition -------------------------------------- */
extern const Spi_ChannelConfigType ChannelConfigs[SPI_CHANNEL_MAX];
extern const Spi_ChannelIdType ChannelList1 [SPI_JOB1_CHANNEL_MAX];
extern const Spi_ChannelIdType ChannelList2 [SPI_JOB2_CHANNEL_MAX];

/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */


#endif /* MCU_SPI_INC_SPI_SPI_CHANNEL_CFG_H_ */
