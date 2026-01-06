/*
 * exti_cfg.c
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <exti_cfg.h>
#include <exti_types.h>
#include "exti_dev.h"
#include <icu.h>
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */


/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */
#define EXTI_GPIO_PIN_0			0u
#define EXTI_GPIO_PIN_1			1u
#define EXTI_GPIO_PIN_2			2u
#define EXTI_GPIO_PIN_3			3u
#define EXTI_GPIO_PIN_4			4u
#define EXTI_GPIO_PIN_5			5u
#define EXTI_GPIO_PIN_6			6u
#define EXTI_GPIO_PIN_7			7u
#define EXTI_GPIO_PIN_8			8u
#define EXTI_GPIO_PIN_9			9u
#define EXTI_GPIO_PIN_10		10u
#define EXTI_GPIO_PIN_11		11u
#define EXTI_GPIO_PIN_12		12u
#define EXTI_GPIO_PIN_13		13u
#define EXTI_GPIO_PIN_14		14u
#define EXTI_GPIO_PIN_15		15u

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */



/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */


static EXTI_ChannelConfigType EXTI_ChannelConfigs[] =
{
	/* Channel : 0*/
	{
		.channelID 	= 0,
		.source =
		{
			.type 	= EXTI_SRC_GPIO,
			.id.gpioPin =
			{
				.portId 	= SYSCFG_HW_EXTICR_PA,
				.pinNumber  = EXTI_GPIO_PIN_0
			}
		},
		.edge 		= EXTI_EDGE_BOTH,
		.callback 	= &ICU_Ch0_Notification
	}
		/* Channel : 1*/
};



EXTI_HandleType EXTI_InitHandle =
{
	.config			= EXTI_ChannelConfigs,
	.configNum 		= 1,
	.isInitiated 	= STD_NOTINITIATED
};


/* ========================================================================================================= */
/* -------------------------------------- Implementation --------------------------------------------------- */


