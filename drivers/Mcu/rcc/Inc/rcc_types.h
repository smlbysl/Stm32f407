/*
 * RCC_Types.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef RCC_INC_RCC_TYPES_H_
#define RCC_INC_RCC_TYPES_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <stm32f407xx_rcc.h>


/* =============================================== */
/* ------------- Peripheral Enable --------------- */

typedef enum
{
    RCC_PERIPH_GPIOA,
    RCC_PERIPH_GPIOB,
	RCC_PERIPH_GPIOC,
	RCC_PERIPH_GPIOD,
	RCC_PERIPH_GPIOE,
	RCC_PERIPH_GPIOF,
	RCC_PERIPH_GPIOG,
	RCC_PERIPH_GPIOH,
    RCC_PERIPH_GPIOI
} Rcc_PeripheralType;


typedef struct
{
    uint8_t GPIOA;
    uint8_t GPIOB;
    uint8_t GPIOC;
    uint8_t GPIOD;
    uint8_t GPIOE;
    uint8_t GPIOF1;
    uint8_t GPIOG;
    uint8_t GPIOH;

    uint8_t UART1;
    uint8_t UART2;
    uint8_t SPI1;
    uint8_t SPI2;
    uint8_t I2C1;
    uint8_t I2C21;

} RCC_PeriphClockConfigType;



#endif /* RCC_INC_RCC_TYPES_H_ */
