/*
 * gpio_hw.h
 *
 *  Created on: Dec 30, 2025
 *      Author: smlby
 */

#ifndef GPIO_INC_GPIO_HW_H_
#define GPIO_INC_GPIO_HW_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <gpio_reg.h>
#include <stdint.h>
#include <stm32f407xx_gpio.h>

/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/* =================================================== */
/*------------------- Port Definition ---------------- */

typedef GPIO_RegDef_t Gpio_Hw_PortType;

/* =================================================== */
/*------------------- Port Definition ---------------- */
typedef uint32_t Gpio_RegMsk;
typedef uint32_t Gpio_RegVal;

/* =================================================== */
/*------------------- Register Type Definition ------- */

typedef uint32_t Gpio_Hw_RegisterType;


/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

#define GPIO_HW_PORT_A   ((Gpio_Hw_PortType*)GPIOA)
#define GPIO_HW_PORT_B   ((Gpio_Hw_PortType*)GPIOB)
#define GPIO_HW_PORT_C   ((Gpio_Hw_PortType*)GPIOC)
#define GPIO_HW_PORT_D   ((Gpio_Hw_PortType*)GPIOD)
#define GPIO_HW_PORT_E   ((Gpio_Hw_PortType*)GPIOE)
#define GPIO_HW_PORT_F   ((Gpio_Hw_PortType*)GPIOF)
#define GPIO_HW_PORT_G   ((Gpio_Hw_PortType*)GPIOG)
#define GPIO_HW_PORT_H   ((Gpio_Hw_PortType*)GPIOH)
#define GPIO_HW_PORT_I   ((Gpio_Hw_PortType*)GPIOI)

/* -------------------- Generic ------------------------------ */
#define GPOI_HW_PORT_COUNT 	9u /*#number of ports*/



#endif /* GPIO_INC_GPIO_HW_H_ */
