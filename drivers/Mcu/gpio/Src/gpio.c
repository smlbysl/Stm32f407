/*
 * gpio.c
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <gpio_cfg.h>
#include <gpio_hw.h>
#include <gpio_ll.h>
#include <gpio_private_types.h>
#include <gpio_types.h>
#include <string.h>

#include "std_types.h"


/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */

static Gpio_InitStatusType  Gpio_InitStatusHandler=
{
	.isInitialized 	= STD_NOTINITIATED,
	.GpioInitHandle = NULL
};

static Gpio_Hw_PortType* const Gpio_PortBase[GPOI_HW_PORT_COUNT] =
{
	GPIO_HW_PORT_A,
	GPIO_HW_PORT_B,
	GPIO_HW_PORT_C,
	GPIO_HW_PORT_D,
	GPIO_HW_PORT_E,
	GPIO_HW_PORT_F,
	GPIO_HW_PORT_G,
	GPIO_HW_PORT_H,
	GPIO_HW_PORT_I
};

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */

static void Gpio_SetShadowBufferReg(Gpio_PortShadowType * buffer);

/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

static inline Gpio_Hw_PortType *Gpio_GetPort(Gpio_PortIdType Port)
{
	if (GPOI_HW_PORT_COUNT <= Port)return NULL;
    return Gpio_PortBase[Port];
}

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */

static void Gpio_SetShadowBufferReg(Gpio_PortShadowType *buffer)
{
	int i = 0;
	Gpio_Hw_PortType *port;

	for(i = 0 ; i < GPOI_HW_PORT_COUNT; i++ )
	{
		if(0 != buffer[i].moder_mask)
		{
			port = Gpio_GetPort(i);
			Gpio_LL_SetModer(port, &buffer[i]);
			Gpio_LL_SetOtyper(port, &buffer[i]);
			Gpio_LL_SetOspeedr(port, &buffer[i]);
			Gpio_LL_SetPupudr(port, &buffer[i]);
			Gpio_LL_SetAfr(port, &buffer[i]);
		}
	}
}


/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

/**
 * @brief	The function initializes the GPIO
 * @param	Base address of the GPIO Handle
 * @return
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	const Gpio_PinConfig_t *pCfg = pGPIOHandle->GPIO_PinConfig;

	Gpio_PortShadowType PortShadow[GPOI_HW_PORT_COUNT];

	int i = 0;

	if ((STD_NOTINITIATED == pGPIOHandle->isInitialized) && (STD_NOTINITIATED == Gpio_InitStatusHandler.isInitialized))
	{

		(void)memset(PortShadow, 0, sizeof(PortShadow));

		for(i = 0 ; i < pGPIOHandle->PinCounter;i++ )
		{
			/* Mode Register Configuration */
			PortShadow [pCfg[i].portId].moder_mask 		|= GPIO_MODER_Msk(pCfg[i].pinNumber);
			PortShadow [pCfg[i].portId].moder_val 		|= GPIO_MODER_Val(pCfg[i].pinNumber,pCfg[i].mode);

			/* Output Type Register Configuration */
			PortShadow [pCfg[i].portId].otyper_mask		|= GPIO_OTYPER_Msk(pCfg[i].pinNumber);
			PortShadow [pCfg[i].portId].otyper_val		|= GPIO_OTYPER_Val(pCfg[i].pinNumber,pCfg[i].outputType);

			/* Speed Register Configuration */
			PortShadow [pCfg[i].portId].ospeedr_mask 	|= GPIO_OSPEEDR_Msk(pCfg[i].pinNumber);
			PortShadow [pCfg[i].portId].ospeedr_val 	|= GPIO_OSPEEDR_Val(pCfg[i].pinNumber,pCfg[i].speed);

			/* Pull - Down Register Configuration */
			PortShadow [pCfg[i].portId].pupdr_mask 		|= GPIO_PUPDR_Msk(pCfg[i].pinNumber);
			PortShadow [pCfg[i].portId].pupdr_val 		|= GPIO_PUPDR_Val(pCfg[i].pinNumber,pCfg[i].pull);

			/* Alternate Function Register Configuration */
			if (GPIO_MODER_AF == pCfg[i].mode)
			{
				if (pCfg[i].pinNumber <= 7)
				{
					PortShadow [pCfg[i].portId].afrl_mask	|= GPIO_AFRL_Msk(pCfg[i].pinNumber);
					PortShadow [pCfg[i].portId].afrl_val 	|= GPIO_AFRL_Val(pCfg[i].pinNumber,pCfg[i].alternate);
				}
				else
				{
					PortShadow [pCfg[i].portId].afrh_mask 	|= GPIO_AFRH_Msk(pCfg[i].pinNumber);
					PortShadow [pCfg[i].portId].afrh_val 	|= GPIO_AFRH_Val(pCfg[i].pinNumber,pCfg[i].alternate);
				}
			}
			else
			{
				/*Do Nothing*/
			}
		}

		Gpio_SetShadowBufferReg(PortShadow);

		pGPIOHandle->isInitialized = STD_INITIATED;
		Gpio_InitStatusHandler.isInitialized = STD_INITIATED;
		Gpio_InitStatusHandler.GpioInitHandle = pGPIOHandle;
	}
	else
	{
		/* GPIO is already initiated */
	}
}

/**
 * @brief	The function deinitialize the GPIO
 * @param	Base address of the GPIO
 * @return	none
 */
void GPIO_DeInit(Gpio_PortIdType gpio_port)
{

}

/**
 * @brief	The function reads pin form referenced GPIO and returns the value
 * @param	[in] 	GPIO Channel
 * @param	[out] 	Data Buffer
 * @return
 */
void GPIO_ReadFromInputPin(const Gpio_ChannelRefType channelRef,  Gpio_PinLevelType *databuffer)
{
    const Gpio_Hw_PortType *p;

	if (channelRef >= GPIO_CHANNEL_NUM)
	{
		return;
	}

    /*Get Port*/
    p = Gpio_GetPort(Gpio_ChannelConfig[channelRef].portId);

    if ((NULL == databuffer) || (NULL == p))
    {
        return;
    }

    Gpio_LL_GetPinLevel(p, Gpio_ChannelConfig[channelRef].pinNumber, databuffer);
}

/**
 * @brief	The function reads port  form referenced GPIO and returns the value
 * @param	[in] 	Port Id[in] GPIO Channel
 * @param	[out] 	Read Port Value
 * @return
 */
void GPIO_ReadFromInputPort(Gpio_PortIdType gpio_port, Gpio_PortLevetType *databuffer)
{
	const Gpio_Hw_PortType * p;


	/*Get Port*/
	p = Gpio_GetPort(gpio_port);

    if ((NULL == databuffer) || (NULL == p))
    {
        return;
    }

	Gpio_LL_GetPortLevel(p, databuffer);
}
/**
 * @brief	The function sets or resets the output pin
 * @param	[in] 	GPIO Channel
 * @param	[in] 	Set or Reset Value
 * @return
 */
void GPIO_WriteToOutputPin(Gpio_ChannelRefType channelRef, const Gpio_PinLevelType databuffer)
{
	Gpio_Hw_PortType * p;

	if (channelRef >= GPIO_CHANNEL_NUM)
	{
		return;
	}

	p = Gpio_GetPort(Gpio_ChannelConfig[channelRef].portId);

    if(NULL == p)
    {
        return;
    }

	Gpio_LL_SetPinLevel(p, Gpio_ChannelConfig[channelRef].pinNumber, databuffer);
}

/**
 * @brief	The function sets or resets the output port
 * @param	[in] Port Id
 * @param	[in] Set or Reset Value
 * @return
 */
void GPIO_WriteToOutputPort(Gpio_PortIdType gpio_port, const Gpio_PortLevetType databuffer)
{
	Gpio_Hw_RegisterType setPins,resetPins;
	Gpio_Hw_RegisterType tempVal;
	Gpio_Hw_PortType * p;

	p = Gpio_GetPort(gpio_port);

    if(NULL == p)
    {
        return;
    }

	setPins 	= ((Gpio_Hw_RegisterType) databuffer) & GPIO_BSRR_SET_PORT_msk ;
	resetPins 	= (~((Gpio_Hw_RegisterType) databuffer) << 16) & GPIO_BSRR_RESET_PORT_msk;

	tempVal = resetPins | setPins;

	Gpio_LL_SetPortLevel(p, tempVal);
}
/**
 * @fn		:	GPIO_WriteToOutputPort
 * @brief	:	The function toggles the output pin
 * @param	: 	[in] Base address of the GPIO
 * @param	: 	[in] Set or Reset Value
 * @return	: 	none
 * @note	: 	none
 */
void GPIO_ToggleOutputPin(Gpio_ChannelRefType channelRef)
{

	Gpio_Hw_PortType * p;

	if (channelRef >= GPIO_CHANNEL_NUM)
	{
		return;
	}

	p = Gpio_GetPort(Gpio_ChannelConfig[channelRef].portId);

    if(NULL == p)
    {
        return;
    }

	Gpio_LL_TogglePinLevel(p, Gpio_ChannelConfig[channelRef].pinNumber);
}

/**
 * @fn		:	GPIO_WriteToOutputPort
 * @brief	:	The function configures the IRQ
 * @param	: 	[in] IRQ Number
 * @param	: 	[in] IRQ Priority
 * @param	: 	[in] Enable Status
 * @return	: 	none
 * @note	: 	none
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/**
 * @fn		:	GPIO_WriteToOutputPort
 * @param	: 	[in] IRQ Number
 * @param	: 	[in] IRQ Priority
 * @param	: 	[in] Enable Status
 * @return	: 	none
 * @note	: 	none
 */
void GPIO_IRQHandling(void)
{

}
