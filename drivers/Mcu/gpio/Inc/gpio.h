/*
 * gpio.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DRIVER_GPIO_H_
#define DRIVER_GPIO_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <gpio_types.h>


/* ========================================================================================================= */
/* ---------------------------------------------------------------------------------------------------------
 * 									API Supported by this Driver
 * 					For more information about the APIs check the function definitions
 * --------------------------------------------------------------------------------------------------------- */


void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

void GPIO_WriteToOutputPin(Gpio_ChannelRefType channelRef, uint8_t val);
void GPIO_WriteToOutputPort(Gpio_PortIdType gpio_port, Gpio_PortLevetType val);

void GPIO_DeInit(Gpio_PortIdType gpio_port);

void GPIO_ReadFromInputPin(Gpio_ChannelRefType channelRef, uint8_t *buffer);
void GPIO_ReadFromInputPort(Gpio_PortIdType gpio_port, uint16_t *buffer);

void GPIO_ToggleOutputPin(Gpio_ChannelRefType channelRef);

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(void);

#endif /* DRIVER_GPIO_H_ */
