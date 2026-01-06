/*
 * gpio_reg.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DRIVER_GPIO_INC_GPIO_REG_H_
#define DRIVER_GPIO_INC_GPIO_REG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Configuration Macros --------------------------------------------- */


/* -------------------- MODER BITS --------------------------- */
/* Link : @GPIO_PIN_MODES */
#define GPIO_MODER_Pos(pin)  		((pin) * 2U) /* Length 	:	2 Bit */
#define GPIO_MODER_Msk(pin)   		(3UL << GPIO_MODER_Pos(pin))
#define GPIO_MODER_Val(pin,v) 		(((v) & 0x3UL) << GPIO_MODER_Pos(pin))

#define GPIO_MODER_INPUT			(0UL)/*Input : Reset State*/
#define GPIO_MODER_GPO				(1UL)/*General Purpose Output*/
#define GPIO_MODER_AF				(2UL)/*Alternate Function MODE*/
#define GPIO_MODER_ANALOG			(3UL)/*Analog Mode*/

/* -------------------- OTYPER BITS -------------------------- */
/* Link : @GPIO_PIN_OTYPES */
#define GPIO_OTYPER_Pos(pin)  		((pin)) /* Length 	:	1 Bit */
#define GPIO_OTYPER_Msk(pin)   		(1UL << GPIO_OTYPER_Pos(pin))
#define GPIO_OTYPER_Val(pin,v) 		(((v) & 0x1UL) << GPIO_OTYPER_Pos(pin))

#define GPIO_OTYPER_PP				(0u) /*Push Pull*/
#define GPIO_OTYPER_OD				(1u) /*Open Drain*/

/* -------------------- OSPEEDR BITS ------------------------- */
/* Link : @GPIO_PIN_OSPEEDS */
#define GPIO_OSPEEDR_Pos(pin)  		((pin) * 2u) /* Length 	:	2 Bit */
#define GPIO_OSPEEDR_Msk(pin)   	(3UL << GPIO_OSPEEDR_Pos(pin))
#define GPIO_OSPEEDR_Val(pin,v) 	(((v) & 0x3UL) << GPIO_OSPEEDR_Pos(pin))

#define GPIO_OSPEEDR_lOW			(0u) /*Low Speed */
#define GPIO_OSPEEDR_MEDIUM			(1u) /*Medium Speed */
#define GPIO_OSPEEDR_FAST			(2u) /*High Speed */
#define GPIO_OSPEEDR_HIGH			(3u) /*Very High Speed */

/* -------------------- PUPD BITS ---------------------------- */
/* Link :  @GPIO_PIN_PUPDS */
#define GPIO_PUPDR_Pos(pin)  		((pin) * 2U) /* Length 	:	2 Bit */
#define GPIO_PUPDR_Msk(pin)   		(3UL << GPIO_PUPDR_Pos(pin))
#define GPIO_PUPDR_Val(pin,v) 		(((v) & 0x3UL) << GPIO_PUPDR_Pos(pin))

#define GPIO_PUPDR_NOPUPD			(0u)
#define GPIO_PUPDR_PU				(1u)
#define GPIO_PUPDR_PD				(2u)

/* -------------------- IDR BITS-- -------------------------- */
#define GPIO_IDR_PIN_Pos(pin)  			((pin)) /* Length 	:	1 Bit */
#define GPIO_IDR_PIN_Msk(pin)   		((1UL << GPIO_IDR_PIN_Pos(pin)))

/* -------------------- ODR BITS-- -------------------------- */
#define GPIO_ODR_PIN_Pos(pin)  			((pin)) /* Length 	:	1 Bit */
#define GPIO_ODR_PIN_Msk(pin)   		((1UL << GPIO_IDR_PIN_Pos(pin)))
#define GPIO_ODR_PIN_Val(pin,v) 		(((v) & 0x1UL) << GPIO_ODR_PIN_Pos(pin))

/* -------------------- BSRR BITS ---------------------------- */
#define GPIO_BSRR_SET_Pos(pin)		(pin)
#define GPIO_BSRR_SET(pin) 			( 0x1UL << GPIO_BSRR_SET_Pos(pin))

#define GPIO_BSRR_RESET_Pos(pin)	(pin + 16)
#define GPIO_BSRR_RESET(pin) 		( 0x1UL << GPIO_BSRR_RESET_Pos(pin))

#define GPIO_BSRR_SET_PORT_msk		(0x0000FFFFul)
#define GPIO_BSRR_RESET_PORT_msk	(0xFFFF0000ul)
/* -------------------- AFRL BITS ---------------------------- */
/* Link : @GPIO_PIN_AFRS */
#define GPIO_AFRL_Pos(pin)   ((pin) * 4U) /* Length 	:	4 Bit */
#define GPIO_AFRL_Msk(pin)   (0xFUL << GPIO_AFRL_Pos(pin))
#define GPIO_AFRL_Val(pin,v) (((v) & 0xFUL) << GPIO_AFRL_Pos(pin))

/* -------------------- AFRH BITS ---------------------------- */
/* Link : @GPIO_PIN_AFRS */
#define GPIO_AFRH_Pos(pin)   (((pin) - 8U) * 4U) /* Length 	:	4 Bit */
#define GPIO_AFRH_Msk(pin)   (0xFUL << GPIO_AFRH_Pos(pin))
#define GPIO_AFRH_Val(pin,v) (((v) & 0xFUL) << GPIO_AFRH_Pos(pin))

/* -------------------- AFR BITS ----------------------------- */
/* Link : @GPIO_PIN_AFRS */
#define GPIO_AF0   (0x0U)
#define GPIO_AF1   (0x1U)
#define GPIO_AF2   (0x2U)
#define GPIO_AF3   (0x3U)
#define GPIO_AF4   (0x4U)
#define GPIO_AF5   (0x5U)
#define GPIO_AF6   (0x6U)
#define GPIO_AF7   (0x7U)
#define GPIO_AF8   (0x8U)
#define GPIO_AF9   (0x9U)
#define GPIO_AF10  (0xAU)
#define GPIO_AF11  (0xBU)
#define GPIO_AF12  (0xCU)
#define GPIO_AF13  (0xDU)
#define GPIO_AF14  (0xEU)
#define GPIO_AF15  (0xFU)


#endif /* DRIVER_GPIO_INC_GPIO_REG_H_ */
