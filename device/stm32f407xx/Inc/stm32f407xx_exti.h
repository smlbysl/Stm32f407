/*
 * stm32f407xx_exti.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef STM32F407XX_STM32F407XX_EXTI_H_
#define STM32F407XX_STM32F407XX_EXTI_H_



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stm32f407xx_memmap.h>
#include "stdint.h"

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */


typedef struct
{
	volatile uint32_t		IMR; 		/*!< Interrupt mask register,           	offset: 0x00 */
	volatile uint32_t 		EMR; 		/*!< Event mask register,					offset: 0x04 */
	volatile uint32_t 		RTSR;	 	/*!< Rising trigger selection register,		offset: 0x08 */
	volatile uint32_t 		FTSR; 		/*!< Falling trigger selection register,	offset: 0x0C */
	volatile uint32_t 		SWIER; 		/*!< Software interrupt event register,   	offset: 0x10 */
	volatile uint32_t 		PR; 		/*!< Pending register,						offset: 0x14 */
}EXTI_RegDef_t;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define EXTI 					((EXTI_RegDef_t *) (EXTI_BASEADDR))


/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */
/* -------------------- IMR ------------------------------- */
#define EXTI_IMR_RESET_VAL	(0x00000000UL)

/* -------------------- EMR ------------------------------- */
#define EXTI_EMR_RESET_VAL	(0x00000000UL)

/* -------------------- RTSR ------------------------------ */
#define EXTI_RTSR_RESET_VAL	(0x00000000UL)

/* -------------------- FTSR ------------------------------ */
#define EXTI_IMR_RESET_VAL	(0x00000000UL)

/* -------------------- SWIER ----------------------------- */
#define EXTI_FTSR_RESET_VAL	(0x00000000UL)

/* -------------------- PR -------------------------------- */
#define EXTI_PR_RESET_VAL	(0x00000000UL)


/* -------------------- TYPE ----------------------------- */


#endif /* STM32F407XX_STM32F407XX_EXTI_H_ */
