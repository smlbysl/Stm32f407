/*
 * cortexM4_nvic.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef CORTEXM4_INC_CORTEXM4_NVIC_H_
#define CORTEXM4_INC_CORTEXM4_NVIC_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>
#include <stm32f407xx_memmap.h>

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */


typedef struct
{
	volatile uint32_t		ISER; 		/*!< GPIO port mode register,           	offset: 0x00 */
	volatile uint32_t 		ICER; 	/*!< GPIO port output type register,		offset: 0x04 */
	volatile uint32_t 		ISPR; 	/*!< GPIO port output speed register,		offset: 0x08 */
	volatile uint32_t 		ICPR; 		/*!< GPIO port pull-up/pull-down register,	offset: 0x0C */
	volatile uint32_t 		IABR; 		/*!< GPIO port input data register,       	offset: 0x10 */
	volatile uint32_t 		IPR; 		/*!< GPIO port output data register,		offset: 0x14 */
	volatile uint32_t 		STIR; 		/*!< GPIO port bit set/reset register,   	offset: 0x18 */
	volatile uint32_t 		LCKR; 		/*!< GPIO port configuration lock register, offset: 0x1C */
	volatile uint32_t		AFR[2]; 	/*!< GPIO alternate function low  and high register,  offset: 0x20 */
}GPIO_RegDef_t;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */



/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */
/* -------------------- MODER ---------------------------- */


/* -------------------- TYPE ----------------------------- */


#endif /* CORTEXM4_INC_CORTEXM4_NVIC_H_ */
