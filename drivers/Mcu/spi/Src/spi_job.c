/*
 * spi_job.c
 *
 *  Created on: Jan 14, 2026
 *      Author: smlby
 */



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
#include "spi_job.h"
#include "gpio.h"
#include "gpio_cfg.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_JobRuntimeType jobRnt[SPI_JOB_MAX];
/* ========================================================================================================= */

/* -------------------------------------- Local Variable Definition  --------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
static void Spi_JobHandler_Assert(Spi_JobIdType	activeJobId);
static void Spi_JobHandler_Deassert(Spi_JobIdType	activeJobId);
static void Spi_JobHandler_EndJob(Spi_HwUnitIdType hwId);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void Spi_JobHandler_EndJob(Spi_HwUnitIdType hwId)
{
	uint8_t i;
	/* Configure device */
	//Std_ReturnType 		retVal			= E_NOT_OK;
	Spi_JobIdType		activeJobId		= Rnt.controllerRnt[hwId].activeJobId;
	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[activeJobId];

	Spi_JobHandler_Deassert(activeJobId);

	Spi_ChannelHandler_EndAsynch(hwId);
	for(i = 0 ; i < jobCfg->channelCount ; i++)
	{
		Rnt.channelRnt[jobCfg->channelList[i]].status = SPI_CHANNEL_OK;
	}
}

static void Spi_JobHandler_Assert(Spi_JobIdType	activeJobId)
{
	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[activeJobId];

	if(STD_TRUE == jobCfg->cs.isCS)
	{
		if(SPI_ACTIVE_LOW == jobCfg->cs.enableLine)
		{
			GPIO_WriteToOutputPin(jobCfg->cs.gpioChnl,  GPIO_PIN_LEVEL_LOW);
		}
		else
		{
			GPIO_WriteToOutputPin(jobCfg->cs.gpioChnl,  GPIO_PIN_LEVEL_HIGH);
		}
	}
}


static void Spi_JobHandler_Deassert(Spi_JobIdType	activeJobId)
{
	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[activeJobId];

	if(STD_TRUE == jobCfg->cs.isCS)
	{
		if(SPI_ACTIVE_LOW == jobCfg->cs.enableLine)
		{
			GPIO_WriteToOutputPin(jobCfg->cs.gpioChnl,  GPIO_PIN_LEVEL_HIGH);
		}
		else
		{
			GPIO_WriteToOutputPin(jobCfg->cs.gpioChnl,  GPIO_PIN_LEVEL_LOW);
		}
	}
}
/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_JobHandler_Init(void)
{
	uint8_t i;
	for(i = 0 ; i < SPI_JOB_MAX ; i++)
	{
		jobRnt[i].status		= SPI_SEQ_OK;
		Spi_JobHandler_Deassert(jobIdMap[i]);
	}
}

void Spi_JobHandler(Spi_HwUnitIdType hwId)
{
	Std_ReturnType 	retVal = E_NOT_OK;
	Spi_JobIdType			jobId	= Rnt.controllerRnt[hwId].activeJobId;
	const Spi_JobConfigType	*jobCfg	= &CfgPtr->jobConfig[jobId];


	if(SPI_TRANSFER_INTERRUPT == jobCfg->transferMode)
	{
		/*Do Nothing*/
	}
	else
	{
			/*Pooling*/
		Spi_Channel_Callback(hwId);
	}

	if(Rnt.hwDone == STD_TRUE)
	{
		Rnt.hwDone = STD_FALSE;

		if(jobCfg->channelCount > Rnt.controllerRnt[hwId].channelIndex + 1)
		{
			if(SPI_TRANSFER_INTERRUPT == jobCfg->transferMode)
			{
				retVal = Spi_ChannelHandler_StartAsynch(hwId,  jobCfg->channelList[Rnt.controllerRnt[hwId].channelIndex + 1]);
			}
			else
			{
					/*Pooling*/
				retVal = Spi_ChannelHandler_StartPooling(hwId, jobCfg->channelList[Rnt.controllerRnt[hwId].channelIndex + 1]);
			}

			if(E_OK == retVal)
			{
				Rnt.controllerRnt[hwId].channelIndex++;
			}
			else
			{
				/*Trigger Attemp Failed */
			}
		}
		else
		{
			jobRnt[jobId].status = SPI_JOB_OK;
			Spi_JobHandler_EndJob(hwId);
		}
	}
	else
	{
		//Channel not okay yet
	}
}

Std_ReturnType Spi_JobHandler_StartJob(Spi_HwUnitIdType hwId, Spi_JobIdType requestJobId)
{
	/* Configure device */
	Std_ReturnType 	retVal = E_NOT_OK;

	uint8_t i;

	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[requestJobId];

	if (SPI_JOB_QUEUED  == jobRnt[requestJobId].status)
	{
		retVal = Spi_HwUnit_SwitchExDev(hwId, jobCfg->exDeviceID);
		if(E_OK != retVal)
		{
			/* Return Not ok*/
		}
		else
		{
			Rnt.controllerRnt[hwId].activeJobId = requestJobId;
			Rnt.jobRnt[requestJobId].status 	= SPI_JOB_PENDING;
			Rnt.controllerRnt[hwId].channelIndex = 0;
			for(i = 0 ; i < jobCfg->channelCount ; i++)
			{
				if (SPI_CHANNEL_PENDING != Rnt.channelRnt[jobCfg->channelList[i]].status)
				{
					return E_NOT_OK;
				}
			}

			Spi_JobHandler_Assert(requestJobId);

			if(SPI_TRANSFER_INTERRUPT == jobCfg->transferMode)
			{
				retVal = Spi_ChannelHandler_StartAsynch(hwId,  jobCfg->channelList[Rnt.controllerRnt[hwId].channelIndex]);
			}
			else
			{
					/*Pooling*/
				retVal = Spi_ChannelHandler_StartPooling(hwId, jobCfg->channelList[Rnt.controllerRnt[hwId].channelIndex]);
			}
		}
	}
	else
	{
		/*Return Not Okay*/
	}
	return retVal;
}

