/*
 * spi_job.c
 *
 *  Created on: Jan 14, 2026
 *      Author: smlby
 */



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_JobRuntimeType jobRnt[SPI_JOB_MAX];
/* ========================================================================================================= */

/* -------------------------------------- Local Variable Definition  --------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
Std_ReturnType Spi_JobHandler_StartJob(Spi_HwUnitIdType hwId, Spi_JobIdType requestJobId);
static Std_ReturnType Spi_JobHandler_EndJob(Spi_HwUnitIdType hwId);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static Std_ReturnType Spi_JobHandler_EndJob(Spi_HwUnitIdType hwId)
{
	/* Configure device */
	Std_ReturnType 		retVal			= E_NOT_OK;
	Spi_JobIdType		activeJobId		= Rnt.controllerRnt[hwId].activeJobId;
	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[activeJobId];

	if(SPI_JOB_OK == jobRnt[activeJobId].status)
	{
		Rnt.controllerRnt[hwId].prevJobId 	= Rnt.controllerRnt[hwId].activeJobId;
		Rnt.controllerRnt[hwId].activeJobId = SPI_JOB_UNDEFINED;
		retVal = E_OK;
	}
	else if (SPI_JOB_FAILED == jobRnt[activeJobId].status)
	{
		/*Error Report*/
		if (SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus /*Add timer check when available */)
		{
			/* SPI_BUSY in determined time interval Error */
			/* Add SPI Reset Process*/
		}
		else if (SPI_UNINIT == Rnt.controllerRnt[hwId].activeContStatus)
		{
			/* Controller Not initiated Error */
		}
		else if (jobRnt[activeJobId].channelIndex < jobCfg->channelCount)
		{
			/* Channels Failed Error */
		}
		else
		{
			/* Do Nothing */
		}
		retVal = E_OK;
		Rnt.controllerRnt[hwId].prevJobId 	= Rnt.controllerRnt[hwId].activeJobId;
		Rnt.controllerRnt[hwId].activeJobId = SPI_JOB_UNDEFINED;
	}
	else if (SPI_JOB_QUEUED  == jobRnt[activeJobId].status)
	{
		retVal = E_OK;
		Rnt.controllerRnt[hwId].prevJobId 	= Rnt.controllerRnt[hwId].activeJobId;
		Rnt.controllerRnt[hwId].activeJobId = SPI_JOB_UNDEFINED;
	}
	else
	{
		/* End request for ongoing job Error */
		/* Return E_NOT_OK*/
	}

	return retVal;
}

void Spi_JobHandler_RntInit(void)
{
	uint8_t i;
	for(i = 0 ; i < SPI_JOB_MAX ; i++)
	{
		jobRnt[i].channelIndex 	= 0;
		jobRnt[i].status		= SPI_SEQ_OK;
	}
}

/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_JobHandler_Init(void)
{
	/* Init Rnt */
	Spi_JobHandler_RntInit();
}

Std_ReturnType Spi_JobHandler(Spi_HwUnitIdType hwId)
{
	Std_ReturnType 			retVal	= E_NOT_OK;
	Spi_JobIdType			jobId	= Rnt.controllerRnt[hwId].activeJobId;
	const Spi_JobConfigType	*jobCfg	= &CfgPtr->jobConfig[jobId];

	if(NULL != CfgPtr)
	{
		if(SPI_JOB_PENDING == jobRnt[jobId].status)
		{
			if(SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus)
			{
				/* Next Channel*/
				/* if ther is no channel job endded*/
				if(jobCfg->channelCount >jobRnt[jobId].channelIndex)
				{
					retVal = Spi_ChannelHandler_StartAsynch(hwId,  jobCfg->channelList[jobRnt[jobId].channelIndex]);

					if(E_OK == retVal)
					{
						jobRnt[jobId].channelIndex ++;
					}
					else
					{
						/*Error Report Job Failed for the Channel*/
						jobRnt[jobId].status = SPI_JOB_FAILED;
					}
				}
				else
				{
					/* Job is ended*/
					jobRnt[jobId].status = SPI_JOB_OK;
				}
			}
			else if (SPI_UNINIT == Rnt.controllerRnt[hwId].activeContStatus)
			{
				/*E_NOT_OK*/
				/*Controller Not initiated Error*/
				retVal = Spi_JobHandler_EndJob(hwId);
			}
			else
			{
				/* Current Channel busy wait*/
				/* Add Cycle Counter Here */
				retVal = E_OK;
			}
		}
		else if(SPI_JOB_QUEUED == jobRnt[jobId].status)
		{
			/*Start current Job */
			jobRnt[jobId].status = SPI_JOB_PENDING;
			retVal = E_OK;
		}
		else
		{
			/* Current Job status OK or FAILED*/
		}

		if((SPI_JOB_OK == jobRnt[jobId].status) ||
			(SPI_JOB_FAILED == jobRnt[jobId].status))
		{
			/* Completed Notifye Upper Layer*/
			retVal = Spi_JobHandler_EndJob(hwId);
		}
	}
	else
	{
		/*Error Report*/
	}
	return retVal;
	/*Check if channels */
}

Std_ReturnType Spi_JobHandler_StartJob(Spi_HwUnitIdType hwId, Spi_JobIdType requestJobId)
{
	/* Configure device */
	Std_ReturnType 	retVal = E_NOT_OK;

	uint8_t i;
	Spi_JobIdType		activeJobId	= Rnt.controllerRnt[hwId].activeJobId;

	const Spi_JobConfigType		*jobCfg	= &CfgPtr->jobConfig[requestJobId];

	if ((SPI_JOB_PENDING != jobRnt[activeJobId].status) &&
		(SPI_JOB_QUEUED  == jobRnt[requestJobId].status))
	{
		retVal = Spi_HwUnit_SwitchExDev(hwId, jobCfg->exDeviceID);

		if(E_OK != retVal)
		{
			/* Return Not ok*/
		}
		else
		{
			Rnt.controllerRnt[hwId].prevJobId 	= Rnt.controllerRnt[hwId].activeJobId;
			Rnt.controllerRnt[hwId].activeJobId = requestJobId;
			jobRnt[requestJobId].channelIndex   = 0;
			for(i = 0 ; i < jobCfg->channelCount ; i++)
			{
				Rnt.channelRnt[jobCfg->channelList[i]].status = SPI_CHANNEL_PENDING;

			}

			Spi_JobHandler(hwId);
		}
	}
	else
	{
		/*Return Not Okay*/
	}
	return retVal;
}

