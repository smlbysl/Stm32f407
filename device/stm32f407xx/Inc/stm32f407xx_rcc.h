/*
 * stm32f407xx_rcc.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DEVICE_STM32F407XX_RCC_H_
#define DEVICE_STM32F407XX_RCC_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>
#include <stm32f407xx_memmap.h>

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */
typedef struct
{
	volatile uint32_t CR;		 	/*!< RCC clock control register,            						offset: 0x00 */
	volatile uint32_t PLLCFGR;	 	/*!< RCC PLL configuration register,            					offset: 0x04 */
	volatile uint32_t CFGR;		 	/*!< RCC clock configuration register,            					offset: 0x08 */
	volatile uint32_t CIR;		 	/*!< RCC clock interrupt register,            						offset: 0x0C */
	volatile uint32_t AHB1RSTR;	 	/*!< RCC AHB1 peripheral reset register,            				offset: 0x10 */
	volatile uint32_t AHB2RSTR;	 	/*!< RCC AHB2 peripheral reset register,            				offset: 0x14 */
	volatile uint32_t AHB3RSTR;	 	/*!< RCC AHB3 peripheral reset register,            				offset: 0x18 */
	uint32_t RESERVED0;			 	/*!< RESERVED,					            						offset: 0x1C */
	volatile uint32_t APB1RSTR;		/*!< RCC APB1 peripheral reset register,           					offset: 0x20 */
	volatile uint32_t APB2RSTR;	 	/*!< RCC APB2 peripheral reset register,            				offset: 0x24 */
	uint32_t RESERVED1;			 	/*!< RESERVED,            											offset: 0x28 */
	uint32_t RESERVED2;			 	/*!< RESERVED,            											offset: 0x2C */
	volatile uint32_t AHB1ENR;	 	/*!< RCC AHB1 peripheral clock enable register,           			offset: 0x30 */
	volatile uint32_t AHB2ENR;	 	/*!< RCC AHB2 peripheral clock enable register,            			offset: 0x34 */
	volatile uint32_t AHB3ENR;	 	/*!< RCC AHB3 peripheral clock enable register,            			offset: 0x38 */
	uint32_t RESERVED3;			 	/*!< RESERVED,            											offset: 0x3C */
	volatile uint32_t APB1ENR;	 	/*!< RCC APB1 peripheral clock enable register,            			offset: 0x40 */
	volatile uint32_t APB2ENR;	 	/*!< RCC APB2 peripheral clock enable register,            			offset: 0x44 */
	uint32_t RESERVED4;			 	/*!< RESERVED,            											offset: 0x48 */
	uint32_t RESERVED5;				/*!< RESERVED,            											offset: 0x4C */
	volatile uint32_t AHB1LPENR;	/*!< RCC AHB1 peripheral clock enable in low power mode register,	offset: 0x50 */
	volatile uint32_t AHB2LPENR;	/*!< RCC AHB2 peripheral clock enable in low power mode register,	offset: 0x54 */
	volatile uint32_t AHB3LPENR;	/*!< RCC AHB3 peripheral clock enable in low power mode register,	offset: 0x58 */
	uint32_t RESERVED6;				/*!< RESERVED,            											offset: 0x5C */
	volatile uint32_t APB1LPENR;	/*!< RCC APB1 peripheral clock enable in low power mode register,	offset: 0x60 */
	volatile uint32_t APB2LPENR;	/*!< RCC APB2 peripheral clock enable in low power mode register,	offset: 0x64 */
	uint32_t RESERVED7;				/*!< RESERVED,            											offset: 0x68 */
	uint32_t RESERVED8;				/*!< RESERVED,            											offset: 0x6C */
	volatile uint32_t BDCR;			/*!< RCC Backup domain control register,							offset: 0x70 */
	volatile uint32_t CSR;			/*!< RCC clock control & status register,            				offset: 0x74 */
	uint32_t RESERVED9;				/*!< RESERVED,            											offset: 0x78 */
	uint32_t RESERVED10;			/*!< RESERVED,            											offset: 0x7C */
	volatile uint32_t SSCGR;		/*!< RCC spread spectrum clock generation register,            		offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;	/*!< RCC PLLI2S configuration register,            					offset: 0x84 */
}RCC_RegDef_t;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define RCC							((RCC_RegDef_t *) RCC_BASEADDR)
#endif /* DEVICE_STM32F407XX_RCC_H_ */
