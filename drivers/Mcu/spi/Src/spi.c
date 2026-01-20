/*
 * spi.c
 *
 *  Created on: Jan 8, 2026
 *      Author: smlby
 */


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi.h"
#include "spi_ll.h"
#include <stddef.h>
#include "stdint.h"
#include "spi_private.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
const Spi_ConfigType	* CfgPtr = NULL;


/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
Spi_ControllerRuntimeType 	ControllerRnt[SPI_HWID_MAX];
Spi_DrvierRuntimeType 		Rnt =
{
		.sequenceRnt	= seqRnt,
		.controllerRnt	= ControllerRnt,
		.jobRnt			= jobRnt,
		.channelRnt		= channelRnt,
		.hwRnt			= hwRnt
};

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
static void Spi_RntInit(void);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void Spi_RntInit(void)
{
	uint8_t i;
	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		//ControllerRnt[HwIdMap[i]].activeChannelId	=
		ControllerRnt[HwIdMap[i]].activeContStatus	= SPI_UNINIT;
		ControllerRnt[HwIdMap[i]].activeJobId		= SPI_JOB_UNDEFINED;
		ControllerRnt[HwIdMap[i]].activeSequence	= SPI_SEQUENCE_UNDEFINED;
	}

}
/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

/**
 * @brief	Service for SPI initialization.
 * @param	Base address of the GPIO Handle
 * @return
 */
void Spi_Init(const Spi_ConfigType* ConfigPtr)
{
	uint8_t contId;

	if(NULL == CfgPtr)
	{
		if ((NULL == ConfigPtr) ||
			(NULL == ConfigPtr->controllerConfig) ||
			(NULL == ConfigPtr->externalDeviceConfig) ||
			(NULL == ConfigPtr->jobConfig) ||
			(NULL == ConfigPtr->channelConfig) )
		{
			/* Null Pointer Error*/
		}
		else
		{
			/*Start Channel Init*/
			Spi_Channel_Init();
			/*Start Hw init*/
			Spi_JobHandler_Init();

			Spi_SequenceHandler_Init();

			Spi_RntInit();

			Spi_HwUnit_Init(ConfigPtr);


			for(contId = 0 ; contId < SPI_HWID_MAX ; contId++)
			{
				if(SPI_HW_IDLE == Rnt.hwRnt[contId].hwStatus)
				{
					ControllerRnt[contId].activeContStatus = SPI_IDLE;
				}
				else
				{
					ControllerRnt[contId].activeContStatus = SPI_UNINIT;
				}
			}

			for(contId = 0 ; contId < SPI_HWID_MAX ; contId++)
			{
				if(SPI_IDLE == 	ControllerRnt[contId].activeContStatus)
				{
					Rnt.activeContStatus = SPI_IDLE;
				}
				else
				{
					Rnt.activeContStatus = SPI_UNINIT;
					break;
				}
			}

		}
	}
	else
	{
		/*Already init*/
	}
}


void Spi_Main(void)
{
	if(SPI_UNINIT != Rnt.activeContStatus)
	{
		Spi_SequenceHandler();
	}
}


Std_ReturnType Spi_Asynch_SeqTrigger(Spi_SequenceIdType seqId)
{
	Spi_SeqHandler_AsychSeqTrigger(seqId);
	return E_OK;
}

Std_ReturnType Spi_WriteTxIBBuffer(Spi_ChannelIdType chId, const uint16_t *DataBuffer)
{
	return Spi_Channel_WriteTxIBBuffer(chId, DataBuffer);
}



