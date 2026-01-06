/*
 * exti_private_types.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_PRIVATE_TYPES_H_
#define EXTI_INC_EXTI_PRIVATE_TYPES_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <exti_types.h>
#include <string.h>

/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

#define EXTI_INVALID_CHANNEL   ((uint8_t)0xFF)

/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

typedef uint8_t EXTI_Gpio_PortRefType;

typedef struct
{
    EXTI_LineType 			line;
	EXTI_EdgeType 			edge;
	EXTI_CallbackType 		callback;
	Std_boolean				enabled;
} EXTI_ChannelRuntimeType;

#endif /* EXTI_INC_EXTI_PRIVATE_TYPES_H_ */
