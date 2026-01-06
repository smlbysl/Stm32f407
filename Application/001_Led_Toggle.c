/*
 * 002led_button.c
 *
 *  Created on: Jan 2, 2026
 *      Author: smlby
 */
/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <stdint.h>
#include "gpio.h"
#include "gpio_cfg.h"
#include "gpio_reg.h"
#include "rcc.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
void funcInit(Gpio_PinConfig_t *p);
void delayFunc (void);
/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
void delayFunc (void)
{
	for(uint32_t i = 0 ; i<500000; i++);
}
void funcInit(Gpio_PinConfig_t *p)
{
	p[0].portId 	= GPIO_PD_ID;
	p[0].pinNumber 	= GPIO_PIN_NO_15;
	p[0].mode 		= GPIO_MODER_GPO;
	p[0].outputType = GPIO_OTYPER_PP;
    p[0].pull 		= GPIO_PUPDR_PU;
    p[0].speed 		= GPIO_OSPEEDR_FAST;

}

/* ========================================================================================================= */
/* -------------------------------------- Main Function Implementation ------------------------------------- */
int main(void)
{
	Gpio_PinConfig_t pinConfigsLocal[1];

	funcInit(pinConfigsLocal);
	GPIO_Handle_t Gpio_ConfigHandlelocal =
	{
			.GPIO_PinConfig 	= pinConfigsLocal,
			.PinCounter			= (uint8_t)(sizeof(pinConfigsLocal) / sizeof(pinConfigsLocal[0])),
			.isInitialized		= STD_NOTINITIATED
	};

	GPIOD_PCLK_EN();

	GPIO_Init(&Gpio_ConfigHandlelocal);

	while(1)
	{
		delayFunc();
		GPIO_ToggleOutputPin(GPIO_CHANNEL_PD15);

	}
}


