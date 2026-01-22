/*
 * gpio_cfg.c
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <gpio_cfg.h>
#include <gpio_reg.h>
#include "../../../projectLib/Inc/std_types.h"

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */


/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */


/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */



/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */


static const Gpio_PinConfig_t Gpio_PinConfigs[] =
{
	/*Pin Config : 0*/
	{
		/*GPIO PortID*/
		GPIO_PD_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_12,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPType*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_PU,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*Pin Config : 1*/
	{
		/*GPIO PortID*/
		GPIO_PD_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_13,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_PU,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*Pin Config : 2*/
	{
		/*GPIO PortID*/
		GPIO_PD_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_14,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_PD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*Pin Config : 3*/
	{
		/*GPIO PortID*/
		GPIO_PD_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_15,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_PU,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*Pin Config : 4*/
	{
		/*GPIO PortID*/
		GPIO_PA_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_0,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_INPUT,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*SPI_1*/
	/*Pin Config : 5*/
	{
		/*GPIO PortID*/
		GPIO_PA_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_7,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_AF,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		GPIO_AF5
	},
	/*Pin Config : 6*/
	{
		/*GPIO PortID*/
		GPIO_PA_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_5,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_AF,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		GPIO_AF5
	},
	/*Pin Config : 7*/
	{
		/*GPIO PortID*/
		GPIO_PA_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_3,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	},
	/*SPI_2*/
	/*Pin Config : 8*/
	{
		/*GPIO PortID*/
		GPIO_PB_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_15,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_AF,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		GPIO_AF5
	},
	/*Pin Config : 9*/
	{
		/*GPIO PortID*/
		GPIO_PB_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_13,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_AF,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		GPIO_AF5
	},
	/*Pin Config : 10*/
	{
		/*GPIO PortID*/
		GPIO_PB_ID,
		/*Gpio_PinNumber*/
		GPIO_PIN_NO_11,
		/*Gpio_Pin_Mode*/
		GPIO_MODER_GPO,
		/*GPOI_Pin_OPtype*/
		GPIO_OTYPER_PP,
		/*Gpio_Pin_PUPD*/
		GPIO_PUPDR_NOPUPD,
		/*Gpio_Pin_OSPEED*/
		GPIO_OSPEEDR_FAST,
		/*Gpio_Pin_AFR*/
		0
	}

};

GPIO_Handle_t Gpio_ConfigHandle =
{
		.GPIO_PinConfig 	= Gpio_PinConfigs,
		.PinCounter			= (uint8_t)(sizeof(Gpio_PinConfigs) / sizeof(Gpio_PinConfigs[0])),
		.isInitialized		= STD_NOTINITIATED
};


const Gpio_ChannelConfigType Gpio_ChannelConfig[] =
{
    /* Channel 0 */
    { GPIO_PD_ID, GPIO_PIN_NO_12 },
	 /* Channel 1 */
	{ GPIO_PD_ID, GPIO_PIN_NO_13 },
	 /* Channel 2 */
	{ GPIO_PD_ID, GPIO_PIN_NO_14 },
	 /* Channel 3 */
	{ GPIO_PD_ID, GPIO_PIN_NO_15 },
    /* Channel 4 */
    { GPIO_PA_ID, GPIO_PIN_NO_0 },
    /* Channel 5 */
    { GPIO_PA_ID, GPIO_PIN_NO_3 },
    /* Channel 6 */
    { GPIO_PB_ID, GPIO_PIN_NO_11 }
};


/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


