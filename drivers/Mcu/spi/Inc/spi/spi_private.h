/*
 * spi_private.h
 *
 *  Created on: Jan 13, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_PRIVATE_H_
#define MCU_SPI_INC_SPI_SPI_PRIVATE_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */


#include <std_types.h>
#include "spi_private_types.h"
#include "spi_cfg.h"
#include "spi_hw.h"
#include "spi_ll.h"
#include <stddef.h>
#include "stdint.h"

/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
#define SPI_CHANNELLENGTH_MAX 1u

/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Extern Definitions  ---------------------------------------------- */

extern const Spi_ConfigType	* CfgPtr;

extern Spi_DrvierRuntimeType 		Rnt;
extern Spi_HwUnitRuntimeType		hwRnt[SPI_HWID_MAX];
extern Spi_ChannelRuntimeType		channelRnt[SPI_CHANNEL_MAX];
extern Spi_JobRuntimeType 			jobRnt[SPI_JOB_MAX];
extern Spi_SequenceRuntimeType 		seqRnt[SPI_SEQUENCE_MAX];

extern Spi_HwUnitIdType HwIdMap[SPI_HWID_MAX];

extern void Spi_HwUnit_Init(const Spi_ConfigType* ConfigPtr);


extern Std_ReturnType Spi_ChannelHandler_StartAsynch(Spi_HwUnitIdType hwId, Spi_ChannelIdType chId);

/* ========================================================================================================= */
/* -------------------------------------- API Definitions  ------------------------------------------------- */
/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- HwUnit Unit  ----------------------------------------------------- */
Std_ReturnType Spi_HwUnit_SwitchExDev(Spi_HwUnitIdType hwId, Spi_ExDevIdType exDevId);
void Spi_HwUnit_Init(const Spi_ConfigType* ConfigPtr);
/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Channel Unit  ---------------------------------------------------- */
Std_ReturnType Spi_Channel_ReadRxIBBuffer(Spi_ChannelIdType chId, uint16_t *DataBuffer);
Std_ReturnType Spi_Channel_WriteTxIBBuffer(Spi_ChannelIdType chId, const uint16_t *DataBuffer);
Std_ReturnType Spi_ChannelHandler_StartAsynch(Spi_HwUnitIdType hwId, Spi_ChannelIdType chId);
void Spi_Channel_Init(void);
void Spi_Channel_Callback(Spi_HwUnitIdType hwID);
/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Job Unit  -------------------------------------------------------- */
Std_ReturnType Spi_JobHandler(Spi_HwUnitIdType hwId);
Std_ReturnType Spi_JobHandler_StartJob(Spi_HwUnitIdType hwId, Spi_JobIdType requestJobId);
void Spi_JobHandler_Init(void);
/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Seq Unit  -------------------------------------------------------- */
Std_ReturnType Spi_SequenceHandler();
Std_ReturnType Spi_SeqHandler_AsychSeqTrigger(Spi_SequenceIdType seqId);



#endif /* MCU_SPI_INC_SPI_SPI_PRIVATE_H_ */
