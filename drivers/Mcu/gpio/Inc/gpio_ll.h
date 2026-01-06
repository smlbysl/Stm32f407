/*
 * GPIO_LL.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DRIVER_GPIO_LL_H_
#define DRIVER_GPIO_LL_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <gpio_hw.h>
#include <gpio_private_types.h>
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */





/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */

/**
 * @fn void Gpio_LL_SetModer(GPIO_RegDef_t*, Gpio_PortShadowType)
 * @brief
 *
 * @param port
 * @param buffer
 */
static inline void Gpio_LL_SetModer(Gpio_Hw_PortType *port, const Gpio_PortShadowType *buffer)
{
	port->MODER = (port->MODER & ~buffer->moder_mask) | buffer->moder_val;
}
/**
 * @fn void Gpio_LL_SetOtyper(GPIO_RegDef_t*, const Gpio_PortShadowType*)
 * @brief
 *
 * @param port
 * @param buffer
 */
static inline void Gpio_LL_SetOtyper(Gpio_Hw_PortType *port, const Gpio_PortShadowType *buffer)
{
	port->OTYPER = (port->OTYPER & ~buffer->otyper_mask) | buffer->otyper_val;
}
/**
 * @fn void Gpio_LL_SetOspeedr(GPIO_RegDef_t*, const Gpio_PortShadowType*)
 * @brief
 *
 * @param port
 * @param buffer
 */
static inline void Gpio_LL_SetOspeedr(Gpio_Hw_PortType *port, const Gpio_PortShadowType *buffer)
{
	port->OSPEEDR = (port->OSPEEDR & ~buffer->ospeedr_mask) | buffer->ospeedr_val;
}
/**
 * @fn void Gpio_LL_SetPupudr(GPIO_RegDef_t*, const Gpio_PortShadowType*)
 * @brief
 *
 * @param port
 * @param buffer
 */
static inline void Gpio_LL_SetPupudr(Gpio_Hw_PortType *port, const Gpio_PortShadowType *buffer)
{
	port->PUPDR = (port->PUPDR & ~buffer->pupdr_mask) | buffer->pupdr_val;
}
/**
 * @fn void Gpio_LL_SetAfrl(GPIO_RegDef_t*, const Gpio_PortShadowType*)
 * @brief
 *
 * @param port
 * @param buffer
 */
static inline void Gpio_LL_SetAfr(Gpio_Hw_PortType *port, const Gpio_PortShadowType *buffer)
{
	port->AFR[0] = (port->AFR[0] & ~buffer->afrl_mask) | buffer->afrl_val;
	port->AFR[1] = (port->AFR[1] & ~buffer->afrh_mask) | buffer->afrh_val;
}

/**
 * @fn void Gpio_LL_SetPinLevel(Gpio_Hw_PortType*, const Gpio_PinNumberType, const Gpio_PinLevelType)
 * @brief
 *
 * @param port			[In - Out]
 * @param pin 			[In]
 * @param databuffer 	[In]
 */
static inline void Gpio_LL_SetPinLevel( Gpio_Hw_PortType *port, const Gpio_PinNumberType pin, const Gpio_PinLevelType databuffer )
{
	//port->BSRR = (port->BSRR & ~(GPIO_BSRR_SET_Msk(pin) | GPIO_BSRR_RESET_Msk(pin))) | GPIO_BSRR_SET_Val(pin,level) | GPIO_BSRR_RESET_Val(pin,level);

	port->BSRR = (GPIO_PIN_LEVEL_HIGH == databuffer) ? GPIO_BSRR_SET(pin) : GPIO_BSRR_RESET(pin);
}
/**
 * @fn void Gpio_LL_SetPortLevel(Gpio_Hw_PortType*, const Gpio_Hw_RegisterType)
 * @brief
 *
 * @param port			[in - out]
 * @param databuffer 	[in]
 */
static inline void Gpio_LL_SetPortLevel( Gpio_Hw_PortType *port,const Gpio_Hw_RegisterType databuffer )
{
	port->BSRR = databuffer;
}
/**
 * @fn void Gpio_LL_GetPinLevel(const Gpio_Hw_PortType*, const Gpio_PinNumberType, Gpio_PinLevelType*)
 * @brief
 *
 * @param port
 * @param pin
 * @param databuffer
 */
static inline void Gpio_LL_GetPinLevel(const Gpio_Hw_PortType *port, const Gpio_PinNumberType pin, Gpio_PinLevelType *databuffer)
{

	*databuffer = 0 != (port->IDR & GPIO_IDR_PIN_Msk(pin)) ? GPIO_PIN_LEVEL_HIGH : GPIO_PIN_LEVEL_LOW;
}

/**
 * @fn void Gpio_LL_GetPortLevel(const Gpio_Hw_PortType*, Gpio_PortLevetType*)
 * @brief
 *
 * @param port
 * @param databuffer
 */
static inline void Gpio_LL_GetPortLevel(const Gpio_Hw_PortType *port, Gpio_PortLevetType *databuffer)
{
	*databuffer = port->IDR;

}

/**
 * @fn void Gpio_LL_TooglePinLevel(Gpio_Hw_PortType*, const Gpio_PinNumberType, const Gpio_PinLevelType)
 * @brief
 *
 * @param port
 * @param pin
 * @param databuffer
 */
static inline void Gpio_LL_TogglePinLevel( Gpio_Hw_PortType *port, const Gpio_PinNumberType pin)
{
	port->ODR ^= (port->ODR & GPIO_ODR_PIN_Msk(pin)) | GPIO_ODR_PIN_Val(pin, 1) ;
}

#endif /* DRIVER_GPIO_LL_H_ */

