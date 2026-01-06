/*
 * exti_types.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_TYPES_H_
#define EXTI_INC_EXTI_TYPES_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <gpio_types.h>
#include "std_types.h"

/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

#define EXTI_SRC_GPIO			0u
#define	EXTI_SRC_TIMER			1u
#define EXTI_SRC_COMP			2u

#define EXTI_EDGE_RISING 		0u
#define EXTI_EDGE_FALLING		1u
#define EXTI_EDGE_BOTH			2u
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
typedef uint8_t EXTI_ChannelIDType;
typedef uint8_t EXTI_LineType;
typedef uint8_t	EXTI_EdgeType;
typedef uint8_t	EXTI_SourceType;
typedef void(*EXTI_CallbackType)(void);





typedef struct
{
    EXTI_SourceType type;
    union
    {
    	Gpio_ChannelConfigType gpioPin;
        uint8_t timerId;
        uint8_t compId;
    } id;
} EXTI_SourceConfigType;

typedef struct
{
	EXTI_ChannelIDType		channelID;
	EXTI_SourceConfigType 	source;
	EXTI_EdgeType 			edge;
	EXTI_CallbackType 		callback;
}EXTI_ChannelConfigType;

typedef struct
{
	EXTI_ChannelConfigType *config;
	uint8_t 				configNum;
	Std_boolean 			isInitiated;
}EXTI_HandleType;




#endif /* EXTI_INC_EXTI_TYPES_H_ */
