/*
 * spi_cfg.c
 *
 *  Created on: Jan 9, 2026
 *      Author: smlby
 */

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private_types.h"
#include "spi_cfg.h"
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */


/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */


/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */

/* ---------------------------------------------------------------- */
/* ----------------- Controller Configs --------------------------- */
const Spi_ControllerConfigType ControllerConfigs[SPI_HWID_MAX] =
{
	{
		/*ID*/
		SPI_SPI1,
		/* Register */
		SPI_HW_SPI1,
		/*Role*/
		SPI_MASTER,
		/* Arbitration */
		SPI_ARBITRATION_NONE,
		/* DMA Capable */
		SPI_DISABLE,
		/* SPI_DISABLE */
		SPI_DISABLE,
		/* Crc Capable */
		SPI_DISABLE
	}
};

/* ---------------------------------------------------------------- */
/* ----------------- Frame Configs -------------------------------- */
static Spi_FrameConfigType frameConfigs[SPI_FRAME_MAX] =
{
	{
		/* dataWidth */
		SPI_DATAFF_8BIT,
		/* bitOrder */
		SPI_FF_MSB,
		/* cpol */
		SPI_CLK_0,
		/* cpha */
		SPI_FIRSTDATA,
		/* protocol */
		SPI_MOTOROLA
	}

};

/* ---------------------------------------------------------------- */
/* ----------------- Channel Configs ------------------------------ */
const Spi_ChannelConfigType ChannelConfigs[SPI_CHANNEL_MAX] =
{
	{
		/* Dir Type */
		SPI_CH_TX,
		/* Length*/
		1
	}
};

const Spi_ChannelIdType ChannelList [SPI_CHANNEL_MAX] =
{
		SPI_CHANNEL_1
};


/* ---------------------------------------------------------------- */
/* ----------------- ExDev Configs -------------------------------- */
const Spi_ExternalDeviceConfigType ExDevConfigs[SPI_EXDEVID_MAX] =
{
	{
		/* ID */
		SPI_SENSOR,
		/* Controller */
		&ControllerConfigs[SPI_SPI1],
		/* Frame */
		&frameConfigs[SPI_FRAME_1],
		/* Bound Rate*/
		1 /* MHz*/,
	}
};

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
		SPI_TRANSFER_INTERRUPT,
		/* Channel Lists */
		ChannelList,
		/* Channel Number */
		SPI_EXDEVID_MAX
	}
};

const Spi_JobIdType joblist [SPI_JOB_MAX] =
{
		SPI_JOB_1
};

/* ---------------------------------------------------------------- */
/* ----------------- Seq Configs ---------------------------------- */
Spi_SequenceConfigType seqConfigs [SPI_SEQUENCE_MAX] =
{
	{
		.hwUnitID 	= SPI_SPI1,
		.jobCount 	= 1,
		.priority 	= 0,
		.sequenceId = SPI_SEQUENCE_1,
		.jobList    = joblist
	}
};
/* ---------------------------------------------------------------- */
/* ----------------- Spi Configs ---------------------------------- */
const Spi_ConfigType SpiConfig =
{
    .controllerConfig     = ControllerConfigs,
    .externalDeviceConfig = ExDevConfigs,
    .jobConfig            = JobConfigs,
    .channelConfig        = ChannelConfigs,
	.seqConfig			  = seqConfigs

};

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */


/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


