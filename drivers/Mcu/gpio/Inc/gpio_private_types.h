/*
 * gpio_private_types.h
 *
 *  Created on: Dec 30, 2025
 *      Author: smlby
 */

#ifndef GPIO_INC_GPIO_PRIVATE_TYPES_H_
#define GPIO_INC_GPIO_PRIVATE_TYPES_H_

/* ========================================================================================================= */
/* -------------------------------------- Include ---------------------------------------------------------- */
#include <gpio_types.h>
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/* =================================================== */
/*------------------- Shadow Buffer Definition ------- */

typedef struct
{
    uint32_t moder_mask;
    uint32_t moder_val;
    uint32_t otyper_mask;
    uint32_t otyper_val;
    uint32_t ospeedr_mask;
    uint32_t ospeedr_val;
    uint32_t pupdr_mask;
    uint32_t pupdr_val;
    uint32_t afrl_mask;
    uint32_t afrl_val;
    uint32_t afrh_mask;
    uint32_t afrh_val;
} Gpio_PortShadowType;

/* =================================================== */
/* ----------------- Status Handler ------------------ */
typedef struct
{
	uint8_t					isInitialized;
	const GPIO_Handle_t		*GpioInitHandle;
}Gpio_InitStatusType;

#endif /* GPIO_INC_GPIO_PRIVATE_TYPES_H_ */
