/*
 * spi_sequence.c
 *
 *  Created on: Jan 15, 2026
 *      Author: smlby
 */




/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_SequenceRuntimeType seqRnt[SPI_SEQUENCE_MAX];
/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
static Spi_SequenceIdType seqIdMap[SPI_SEQUENCE_MAX] =
{
		SPI_SEQUENCE_1
};
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
static Std_ReturnType Spi_SeqHandler_EndSeq(Spi_HwUnitIdType hwId);
static Std_ReturnType Spi_SeqHandler_StartSeq(Spi_HwUnitIdType hwId);
static void Spi_SequenceHandler_RntInit(void);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
Std_ReturnType Spi_SeqHandler_StartSeq(Spi_HwUnitIdType hwId)
{
	uint8_t i;
	Std_ReturnType 	retVal = E_NOT_OK;
	const Spi_SequenceConfigType *seqCfg;
	Spi_SequenceIdType 	actSeqId = Rnt.controllerRnt[hwId].activeSequence;
	Spi_SequenceIdType 	temp = actSeqId;

	actSeqId = Rnt.controllerRnt[hwId].activeSequence;
	seqCfg = CfgPtr->seqConfig;

	if((SPI_SEQ_OK == seqRnt[actSeqId].status) ||
		(SPI_SEQ_FAILED == seqRnt[actSeqId].status) ||
		(SPI_SEQ_CANCELED == seqRnt[actSeqId].status))
	{
		for(i = 0 ; i < SPI_SEQUENCE_MAX  ; i++)
		{
			if ((SPI_SEQ_PENDING == seqRnt[seqIdMap[i]].status) &&
				(seqCfg[seqIdMap[i]].priority < seqCfg[temp].priority) &&
				(seqCfg[seqIdMap[i]].hwUnitID == hwId))
			{
					temp = seqIdMap[i];
			}
		}
		if(actSeqId != temp)
		{

			Rnt.controllerRnt[hwId].activeSequence = temp;
			seqRnt[temp].jobIndex = 0;
			for (i = 0 ; i < seqCfg[temp].jobCount ; i++)
			{
				Rnt.jobRnt[i].status = SPI_JOB_QUEUED;
			}
			retVal = E_OK;
		}
		else
		{
			/*Return Not Ok*/
		}
	}
	else
	{
		/* Stil ongoing */
		/*Return Not Ok*/
	}

	return retVal;
}
static Std_ReturnType Spi_SeqHandler_EndSeq(Spi_HwUnitIdType hwId)
{
	Std_ReturnType retVal = E_NOT_OK;

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
}


/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_SequenceHandler_Init(void)
{
	/* Init Rnt */
	Spi_SequenceHandler_RntInit();
}

Std_ReturnType Spi_SequenceHandler()
{
	Std_ReturnType 			retVal	= E_NOT_OK;
	uint8_t i;
	const Spi_SequenceConfigType *seqCfg;
	Spi_SequenceIdType 	actSeqId;
	Spi_JobIdType		actJobId;
	Spi_HwUnitIdType  	hwId;

	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		actSeqId = Rnt.controllerRnt[hwId].activeSequence;
		actJobId = Rnt.controllerRnt[hwId].activeJobId;
		hwId = hwRnt[i].hwUnitId;
		seqCfg = &CfgPtr->seqConfig[actSeqId];

		if ( actSeqId < SPI_SEQUENCE_MAX)
		{
			if(SPI_SEQ_PENDING == seqRnt[actSeqId].status)
			{
				if(SPI_JOB_FAILED == Rnt.jobRnt[actJobId].status)
				{
					seqRnt[actSeqId].status = SPI_SEQ_FAILED;
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
						}
					}
					else
					{
						/* Seq is ended*/
						seqRnt[actSeqId].status = SPI_SEQ_OK;
					}
				}
				else
				{
					Spi_JobHandler(hwId);
				}
			}
			else if(SPI_SEQ_CANCELED == seqRnt[actSeqId].status)
			{
				/*Start another seq from queue*/
			}
			else
			{
				/*Do Nothing*/
			}

			if((SPI_SEQ_OK == seqRnt[actSeqId].status) ||
				(SPI_SEQ_FAILED == seqRnt[actSeqId].status))
			{
				/* Completed Notifye Upper Layer*/
				retVal = Spi_SeqHandler_EndSeq(hwId);
				retVal = Spi_SeqHandler_StartSeq(hwId);
			}
		}
		else
		{
			/*Undefined Sequence*/
			/*Init condition*/
			retVal = Spi_SeqHandler_StartSeq(hwId);
		}
	}
	return retVal;
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

