/*
 * spi_job_cfg.c
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_job_cfg.h"
#include "spi_channel_cfg.h"
#include "gpio_cfg.h"
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
/* ---------------------------------------------------------------- */
/* ----------------- Job Configs ---------------------------------- */
const Spi_JobConfigType JobConfigs [] =
{
	{
		/* ID */
		SPI_JOB_1,
		/* Hw Unit ID*/
		SPI_SPI1,
		/* External Device ID*/
		SPI_SENSOR,
		/*Transfer Type */
		SPI_TRANSFER_POLLING,
		//SPI_TRANSFER_INTERRUPT,
		/* Channel Lists */
		ChannelList1,
		/* Channel Number */
		1,
		{
			/*CS is used */
			STD_TRUE,
			/*GPOI CHNL*/
			GPIO_CHANNEL_PA3,
			/*Enable Line*/
			SPI_ACTIVE_LOW
		}
	},
	{
		/* ID */
		SPI_JOB_2,
		/* Hw Unit ID*/
		SPI_SPI1,
		/* External Device ID*/
		SPI_SENSOR,
		/*Transfer Type */
		SPI_TRANSFER_INTERRUPT,
		/* Channel Lists */
		ChannelList2,
		/* Channel Number */
		2,
		{
			/*CS is used */
			STD_TRUE,
			/*GPOI CHNL*/
			GPIO_CHANNEL_PA3,
			/*Enable Line*/
			SPI_ACTIVE_LOW
		}
	}
};

const Spi_JobIdType joblist1 [SPI_JOB_MAX] =
{
		SPI_JOB_1,
		SPI_JOB_2
};

const Spi_JobIdType jobIdMap[SPI_JOB_MAX] =
{
		SPI_JOB_1,
		SPI_JOB_2
};

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


