/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef STM32F407XX_GPIO_H_
#define STM32F407XX_GPIO_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>
#include <stm32f407xx_memmap.h>

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */


typedef struct
{
	volatile uint32_t		MODER; 		/*!< GPIO port mode register,           	offset: 0x00 */
	volatile uint32_t 		OTYPER; 	/*!< GPIO port output type register,		offset: 0x04 */
	volatile uint32_t 		OSPEEDR; 	/*!< GPIO port output speed register,		offset: 0x08 */
	volatile uint32_t 		PUPDR; 		/*!< GPIO port pull-up/pull-down register,	offset: 0x0C */
	volatile uint32_t 		IDR; 		/*!< GPIO port input data register,       	offset: 0x10 */
	volatile uint32_t 		ODR; 		/*!< GPIO port output data register,		offset: 0x14 */
	volatile uint32_t 		BSRR; 		/*!< GPIO port bit set/reset register,   	offset: 0x18 */
	volatile uint32_t 		LCKR; 		/*!< GPIO port configuration lock register, offset: 0x1C */
	volatile uint32_t		AFR[2]; 	/*!< GPIO alternate function low  and high register,  offset: 0x20 */
}GPIO_RegDef_t;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define GPIOA 					((GPIO_RegDef_t *) (GPIOA_BASEADDR))
#define GPIOB 					((GPIO_RegDef_t *) (GPIOB_BASEADDR))
#define GPIOC 					((GPIO_RegDef_t *) (GPIOC_BASEADDR))
#define GPIOD 					((GPIO_RegDef_t *) (GPIOD_BASEADDR))
#define GPIOE 					((GPIO_RegDef_t *) (GPIOE_BASEADDR))
#define GPIOF 					((GPIO_RegDef_t *) (GPIOF_BASEADDR))
#define GPIOG 					((GPIO_RegDef_t *) (GPIOG_BASEADDR))
#define GPIOH 					((GPIO_RegDef_t *) (GPIOH_BASEADDR))
#define GPIOI 					((GPIO_RegDef_t *) (GPIOI_BASEADDR))


/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */
/* -------------------- MODER ---------------------------- */
#define GPIOA_MODER_RESET_VAL	(0xA8000000UL)
#define GPIOB_MODER_RESET_VAL	(0x00000280UL)
#define GPIOX_MODER_RESET_VAL	(0x00000000UL)

/* -------------------- OTYPER ---------------------------- */
#define GPIOX_OTYPER_RESET_VAL	(0x00000000UL)

/* -------------------- OSPEEDR --------------------------- */
#define GPIOA_OSPEEDR_RESET_VAL	(0x0C000000UL)
#define GPIOB_OSPEEDR_RESET_VAL	(0x000000C0UL)
#define GPIOX_OSPEEDR_RESET_VAL	(0x00000000UL)

/* -------------------- PUPDR ----------------------------- */
#define GPIOA_PUPDR_RESET_VAL	(0x64000000UL)
#define GPIOB_PUPDR_RESET_VAL	(0x00000100UL)
#define GPIOX_PUPDR_RESET_VAL	(0x00000000UL)

/* -------------------- TYPE ----------------------------- */


#endif /* STM32F407XX_GPIO_H_ */
