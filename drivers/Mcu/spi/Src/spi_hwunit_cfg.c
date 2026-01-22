/*
 * spi_hw_cfg.c
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */
/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <spi_hwunit_cfg.h>
#include "spi_private.h"
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
	},

	/*SPI2*/
	{
		/*ID*/
		SPI_SPI2,
		/* Register */
		SPI_HW_SPI2,
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
const Spi_FrameConfigType frameConfigs[SPI_FRAME_MAX] =
{
	{
		/* dataWidth */
		SPI_DATAFF_8BIT,
		/* bitOrder */
		SPI_FF_MSB,
		/* cpol */
		SPI_CLK_0,
		/* cpha */
		SPI_SECONDDATA,
		/* protocol */
		SPI_MOTOROLA
	}
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
	},
	/* SPI_EXDEV_1*/
	{
		/* ID */
		SPI_EXDEV_1,
		/* Controller */
		&ControllerConfigs[SPI_SPI2],
		/* Frame */
		&frameConfigs[SPI_FRAME_1],
		/* Bound Rate*/
		1 /* MHz*/,
	}
};


const Spi_HwUnitIdType HwIdMap[SPI_HWID_MAX] =
{
		SPI_SPI1,
		SPI_SPI2
};

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


