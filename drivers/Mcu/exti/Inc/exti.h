/*
 * exti.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_H_
#define EXTI_INC_EXTI_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <exti_types.h>


/* ========================================================================================================= */
/* ---------------------------------------------------------------------------------------------------------
 * 									API Supported by this Driver
 * 					For more information about the APIs check the function definitions
 * --------------------------------------------------------------------------------------------------------- */


/* Initialization & configuration */
Std_ReturnType EXTI_Init(EXTI_HandleType *hexti);

/* Control */
Std_ReturnType EXTI_Enable(EXTI_ChannelIDType channel);
Std_ReturnType EXTI_Disable(EXTI_ChannelIDType channel);

/* Runtime */
//Std_ReturnType EXTI_SetEdge(uint8 pin, EXTI_Edge_t edge);
//Std_ReturnType EXTI_ClearFlag(uint8 pin);

/* Callback */
//Std_ReturnType EXTI_RegisterCallback(uint8 pin, EXTI_Callback_t cb);


#endif /* EXTI_INC_EXTI_H_ */
