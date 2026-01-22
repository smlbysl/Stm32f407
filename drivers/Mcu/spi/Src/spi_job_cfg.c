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
		SPI_JOB1_CHANNEL_MAX,
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
		SPI_TRANSFER_POLLING,
		/* Channel Lists */
		ChannelList2,
		/* Channel Number */
		SPI_JOB2_CHANNEL_MAX,
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
		SPI_JOB_3,
		/* Hw Unit ID*/
		SPI_SPI2,
		/* External Device ID*/
		SPI_EXDEV_1,
		/*Transfer Type */
		SPI_TRANSFER_INTERRUPT,
		/* Channel Lists */
		ChannelList3,
		/* Channel Number */
		SPI_JOB3_CHANNEL_MAX,
		{
			/*CS is used */
			STD_TRUE,
			/*GPOI CHNL*/
			GPIO_CHANNEL_PB11,
			/*Enable Line*/
			SPI_ACTIVE_LOW
		}
	},
	{
		/* ID */
		SPI_JOB_4,
		/* Hw Unit ID*/
		SPI_SPI2,
		/* External Device ID*/
		SPI_EXDEV_1,
		/*Transfer Type */
		SPI_TRANSFER_INTERRUPT,
		/* Channel Lists */
		ChannelList4,
		/* Channel Number */
		SPI_JOB4_CHANNEL_MAX,
		{
			/*CS is used */
			STD_TRUE,
			/*GPOI CHNL*/
			GPIO_CHANNEL_PB11,
			/*Enable Line*/
			SPI_ACTIVE_LOW
		}
	}
};

const Spi_JobIdType joblist1 [SPI_JOB_LIST_1_MAX] =
{
		SPI_JOB_1,
};

const Spi_JobIdType joblist2 [SPI_JOB_LIST_2_MAX] =
{
		SPI_JOB_2
};

const Spi_JobIdType joblist3 [SPI_JOB_LIST_3_MAX] =
{
		SPI_JOB_3,
		SPI_JOB_4
};

const Spi_JobIdType jobIdMap[SPI_JOB_MAX] =
{
		SPI_JOB_1,
		SPI_JOB_2,
		SPI_JOB_3,
		SPI_JOB_4
};

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


