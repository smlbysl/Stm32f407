/*
 * RCC.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef RCC_INC_RCC_H_
#define RCC_INC_RCC_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <rcc_types.h>


/* ========================================================================================================= */
/* -------------------------------------- MACRO ------------------------------------------------------------ */

#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |= 1 << 0)
#define GPIOB_PCLK_EN()			(RCC->AHB1ENR |= 1 << 1)
#define GPIOC_PCLK_EN()			(RCC->AHB1ENR |= 1 << 2)
#define GPIOD_PCLK_EN()			(RCC->AHB1ENR |= 1 << 3)
#define GPIOE_PCLK_EN()			(RCC->AHB1ENR |= 1 << 4)
#define GPIOF_PCLK_EN()			(RCC->AHB1ENR |= 1 << 5)
#define GPIOG_PCLK_EN()			(RCC->AHB1ENR |= 1 << 6)
#define GPIOH_PCLK_EN()			(RCC->AHB1ENR |= 1 << 7)
#define GPIOI_PCLK_EN()			(RCC->AHB1ENR |= 1 << 8)

#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 8))

/* ========================================================================================================= */
/* -------------------------------------- API -------------------------------------------------------------- */

void Rcc_EnablePeripheral(Rcc_PeripheralType Periph);

#endif /* RCC_INC_RCC_H_ */
