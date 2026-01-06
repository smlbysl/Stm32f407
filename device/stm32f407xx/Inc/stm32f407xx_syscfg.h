/*
 * stm32f407xx_syscfg.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef STM32F407XX_INC_STM32F407XX_SYSCFG_H_
#define STM32F407XX_INC_STM32F407XX_SYSCFG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stm32f407xx_memmap.h>
#include "stdint.h"

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */


typedef struct
{
	volatile uint32_t		MEMRMP; 		/*!< SYSCFG memory remap register,           					offset: 0x00 */
	volatile uint32_t 		PMC; 			/*!< SYSCFG peripheral mode configuration register,				offset: 0x04 */
	volatile uint32_t 		EXTICR[4];	 	/*!< SYSCFG external interrupt configuration register 1,2,3,4,	offset: 0x08 */
	/*volatile uint32_t 	EXTICR2;*/ 		/*!< SYSCFG external interrupt configuration register 2,		offset: 0x0C */
	/*volatile uint32_t		EXTICR3;*/ 		/*!< SYSCFG external interrupt configuration register 3,   		offset: 0x10 */
	/*volatile uint32_t		EXTICR4;*/ 		/*!< SYSCFG external interrupt configuration register 4r,		offset: 0x14 */
	volatile uint32_t 		CMPCR; 			/*!< Compensation cell control register,						offset: 0x20 */
}SYSCFG_RegDef_t;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define SYSCFG 					((SYSCFG_RegDef_t *) (SYSCFG_BASEADDR))


/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */

/* -------------------- TYPE ----------------------------- */


#endif /* STM32F407XX_INC_STM32F407XX_SYSCFG_H_ */
