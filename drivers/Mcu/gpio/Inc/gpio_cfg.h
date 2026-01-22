/*
 * gpio_Cfg.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DRIVER_GPIO_CFG_H_
#define DRIVER_GPIO_CFG_H_




/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <gpio_types.h>

/* ========================================================================================================= */
/* -------------------------------------- Macro ------------------------------------------------------------ */
#define GPIO_CHANNEL_PD12	((Gpio_ChannelRefType)0)
#define GPIO_CHANNEL_PD13	((Gpio_ChannelRefType)1)
#define GPIO_CHANNEL_PD14	((Gpio_ChannelRefType)2)
#define GPIO_CHANNEL_PD15	((Gpio_ChannelRefType)3)
#define GPIO_CHANNEL_PA0	((Gpio_ChannelRefType)4)
#define GPIO_CHANNEL_PA3	((Gpio_ChannelRefType)5)
#define GPIO_CHANNEL_PB11	((Gpio_ChannelRefType)6)

#define GPIO_CHANNEL_NUM	(7U)


/* ========================================================================================================= */
/* -------------------------------------- Extern - --------------------------------------------------------- */
extern GPIO_Handle_t Gpio_ConfigHandle;
extern const Gpio_ChannelConfigType Gpio_ChannelConfig[];

#endif /* DRIVER_GPIO_CFG_H_ */
