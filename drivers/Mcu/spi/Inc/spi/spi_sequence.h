/*
 * spi_sequence.h
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_SEQUENCE_H_
#define MCU_SPI_INC_SPI_SPI_SEQUENCE_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private_types.h"
#include "spi_job.h"
#include "spi_channel.h"
#include "spi_hwunit.h"
#include "spi_hwunit_cfg.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
#define SPI_CHANNELLENGTH_MAX 1u
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Extern Definitions  ---------------------------------------------- */
extern Spi_SequenceRuntimeType 		seqRnt[SPI_SEQUENCE_MAX];
/* ========================================================================================================= */
/* -------------------------------------- API Definitions  ------------------------------------------------- */
void Spi_SequenceHandler();
Std_ReturnType Spi_SeqHandler_AsychSeqTrigger(Spi_SequenceIdType seqId);
void Spi_SequenceHandler_Init(void);
Std_ReturnType Spi_SeqHandler_SyncTransmitTrigger(Spi_SequenceIdType Sequence);

#endif /* MCU_SPI_INC_SPI_SPI_SEQUENCE_H_ */
