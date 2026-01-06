/*
 * exti_cfg.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_CFG_H_
#define EXTI_INC_EXTI_CFG_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "exti_types.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */
/* ------------- Channel Macro ------------- */
#define EXTI_CHANNEL_COUNT 		1u

#define EXTI_CHANNEL_BUTTON 	EXTI_CHANNEL_GPIO_PA0
#define EXTI_CHANNEL_SENSOR 	1

/* ------------------------- */

#define EXTI_CHANNEL_GPIO_PA0		0u
#define EXTI_CHANNEL_GPIO_PA1		1u
#define EXTI_CHANNEL_GPIO_PA2		2u
#define EXTI_CHANNEL_GPIO_PA3		3u
#define EXTI_CHANNEL_GPIO_PA4		4u
#define EXTI_CHANNEL_GPIO_PA5		5u
#define EXTI_CHANNEL_GPIO_PA6		6u
#define EXTI_CHANNEL_GPIO_PA7		7u
#define EXTI_CHANNEL_GPIO_PA8		8u
#define EXTI_CHANNEL_GPIO_PA9		9u
#define EXTI_CHANNEL_GPIO_PA10		10u
#define EXTI_CHANNEL_GPIO_PA11		11u
#define EXTI_CHANNEL_GPIO_PA12		12u
#define EXTI_CHANNEL_GPIO_PA13		13u
#define EXTI_CHANNEL_GPIO_PA14		14u
#define EXTI_CHANNEL_GPIO_PA15		15u


/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */
extern EXTI_HandleType EXTI_InitHandle;

/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */


#endif /* EXTI_INC_EXTI_CFG_H_ */
