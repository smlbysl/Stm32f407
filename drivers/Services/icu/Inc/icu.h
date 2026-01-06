/*
 * icu.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_ICU_H_
#define EXTI_INC_ICU_H_



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <exti.h>
#include <icu_types.h>

/* ========================================================================================================= */
/* ---------------------------------------------------------------------------------------------------------
 * 									API Supported by this Driver
 * 					For more information about the APIs check the function definitions
 * --------------------------------------------------------------------------------------------------------- */


/* Control */
Std_ReturnType ICU_EnableNotification(uint8_t channel);
Std_ReturnType ICU_DisableNotification(uint8_t channel);


/*Notification */
void ICU_Ch0_Notification(void);


extern uint8_t ICU_Ch0_notification;

#endif /* EXTI_INC_ICU_H_ */
