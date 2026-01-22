/*
 * spi_sequence.c
 *
 *  Created on: Jan 15, 2026
 *      Author: smlby
 */




/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
#include "spi_sequence.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_SequenceRuntimeType seqRnt[SPI_SEQUENCE_MAX];
/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
static Spi_SeqStateMachType seqStateMach[SPI_HWID_MAX];
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
static Std_ReturnType Spi_SeqHandler_EndSeq(Spi_HwUnitIdType hwId);
static void Spi_SeqHandler_StartSeq(Spi_HwUnitIdType hwId);
static void Spi_SequenceHandler_RntInit(void);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void Spi_SeqHandler_StartSeq(Spi_HwUnitIdType hwId)
{
	uint8_t i;
	const Spi_SequenceConfigType *seqCfg;
	Spi_SequenceIdType 	temp = SPI_SEQUENCE_UNDEFINED;

	seqCfg = CfgPtr->seqConfig;

	for(i = 0 ; i < SPI_SEQUENCE_MAX  ; i++)
	{
		if((SPI_SEQ_PENDING == seqRnt[seqIdMap[i]].status) &&
				(seqCfg[seqIdMap[i]].hwUnitID == hwId))
		{
			if(SPI_SEQUENCE_UNDEFINED != temp)
			{
				if (seqCfg[seqIdMap[i]].priority < seqCfg[temp].priority)
				{
					temp = seqIdMap[i];
				}

			}
			else
			{
				temp = seqIdMap[i];
			}
		}
	}

	if(SPI_SEQUENCE_UNDEFINED != temp)
	{
		seqStateMach[hwId] = SPI_SEQUENCE_PROCEDING;
		/*Sequence Prepare*/
		Rnt.controllerRnt[hwId].activeSequence = temp;
		seqRnt[temp].jobIndex = 0;
		for (i = 0 ; i < seqCfg[temp].jobCount ; i++)
		{
			Rnt.jobRnt[seqCfg[temp].jobList[i]].status = SPI_JOB_QUEUED;
		}
	}
	else
	{
		/* No find Sequence*/
	}
}
static Std_ReturnType Spi_SeqHandler_EndSeq(Spi_HwUnitIdType hwId)
{
	Std_ReturnType retVal = E_NOT_OK;

	seqStateMach[hwId] = SPI_SEQUENCE_IDLE;
	retVal = E_OK;
	return retVal;
}

void Spi_SequenceHandler_RntInit(void)
{
	uint8_t i;
	for(i = 0 ; i < SPI_SEQUENCE_MAX ; i++)
	{
		seqRnt[seqIdMap[i]].sequenceId 	= seqIdMap[i];
		seqRnt[seqIdMap[i]].status		= SPI_SEQ_OK;
		seqRnt[seqIdMap[i]].jobIndex	= 0;
	}

	for (i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		seqStateMach[HwIdMap[i]] = SPI_SEQUENCE_INIT;
	}
}


/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_SequenceHandler_Init(void)
{
	/* Init Rnt */
	Spi_SequenceHandler_RntInit();
}

void Spi_SequenceHandler()
{
	Std_ReturnType 			retVal	= E_NOT_OK;
	uint8_t i;
	const Spi_SequenceConfigType *seqCfg;
	Spi_SequenceIdType 	actSeqId;
	Spi_JobIdType		actJobId;
	Spi_HwUnitIdType  	hwId;

	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		hwId = hwRnt[i].hwUnitId;

		if((SPI_SEQUENCE_INIT == seqStateMach[hwId]) ||
			(SPI_SEQUENCE_IDLE == seqStateMach[hwId])	)
		{

			Spi_SeqHandler_StartSeq(hwId);

		}
		if (SPI_SEQUENCE_PROCEDING == seqStateMach[hwId])
		{
			actSeqId = Rnt.controllerRnt[hwId].activeSequence;
			actJobId = Rnt.controllerRnt[hwId].activeJobId;

			seqCfg = &CfgPtr->seqConfig[actSeqId];

			if (actJobId == seqCfg->jobList[seqRnt[actSeqId].jobIndex])
			{
				if(SPI_JOB_FAILED == Rnt.jobRnt[actJobId].status)
				{
					seqRnt[actSeqId].status = SPI_SEQ_FAILED;
					retVal = Spi_SeqHandler_EndSeq(hwId);
				}
				else if (SPI_JOB_OK == Rnt.jobRnt[actJobId].status)
				{
					/*Next Job */
					if(seqCfg->jobCount > seqRnt[actSeqId].jobIndex + 1)
					{
						retVal = Spi_JobHandler_StartJob(hwId,  seqCfg->jobList[seqRnt[actSeqId].jobIndex + 1]);

						if(E_OK == retVal)
						{
							seqRnt[actSeqId].jobIndex ++;
							Spi_JobHandler(hwId);
						}
						else
						{
							/*Error Report Job Failed for the Channel*/
							seqRnt[actSeqId].status = SPI_SEQ_FAILED;
							retVal = Spi_SeqHandler_EndSeq(hwId);
						}
					}
					else
					{
						/* Seq is ended*/
						seqRnt[actSeqId].status = SPI_SEQ_OK;
						retVal = Spi_SeqHandler_EndSeq(hwId);
					}
				}
				else if (SPI_JOB_QUEUED == Rnt.jobRnt[actJobId].status)
				{
					retVal = Spi_JobHandler_StartJob(hwId, seqCfg->jobList[seqRnt[actSeqId].jobIndex]);
				}
				else
				{
					/* Current Job Pending or Queued*/
					Spi_JobHandler(hwId);
				}
			}
			else
			{
				retVal = Spi_JobHandler_StartJob(hwId, seqCfg->jobList[seqRnt[actSeqId].jobIndex]);
			}
		}
	}
	/*Check if channels */
}

Std_ReturnType Spi_SeqHandler_AsychSeqTrigger(Spi_SequenceIdType seqId)
{
	Std_ReturnType 	retVal = E_NOT_OK;
	if ( seqId < SPI_SEQUENCE_MAX)
	{
		if(SPI_SEQ_PENDING != seqRnt[seqId].status)
		{
			seqRnt[seqId].status = SPI_SEQ_PENDING;
			retVal = E_OK;
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
	return retVal;
}

Std_ReturnType Spi_SeqHandler_SyncTransmitTrigger(Spi_SequenceIdType Sequence)
{
	Std_ReturnType 	retVal = E_NOT_OK;
	uint8_t i;
	const Spi_SequenceConfigType *seqCfg = &CfgPtr->seqConfig[Sequence];
	Spi_HwUnitIdType  	hwId = seqCfg->hwUnitID;

	seqCfg = CfgPtr->seqConfig;


	if((SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus) &&
			((SPI_SEQUENCE_IDLE == seqStateMach[hwId]) ||
					(SPI_SEQUENCE_INIT == seqStateMach[hwId])))
	{
		seqStateMach[hwId] = SPI_SEQUENCE_PROCEDING;
		/*Sequence Prepare*/
		Rnt.controllerRnt[hwId].activeSequence = Sequence;
		seqRnt[Sequence].jobIndex = 0;
		for (i = 0 ; i < seqCfg[Sequence].jobCount ; i++)
		{
			Rnt.jobRnt[i].status = SPI_JOB_QUEUED;
		}

		while((SPI_SEQUENCE_IDLE != seqStateMach[hwId]))
		{
			Spi_SequenceHandler();
		}

		retVal = E_OK;
	}
	else
	{

	}

	return retVal;
}

