/*
 * exti_dev.c
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <exti_dev.h>
#include <exti_private_types.h>

/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
static EXTI_Gpio_PortRefType EXTI_Gpio_PortIndx[EXTI_HW_EXTCR_PORTNUM] = {
																			SYSCFG_EXTICR_PA,
																			SYSCFG_EXTICR_PB,
																			SYSCFG_EXTICR_PC,
																			SYSCFG_EXTICR_PD,
																			SYSCFG_EXTICR_PE,
																			SYSCFG_EXTICR_PF,
																			SYSCFG_EXTICR_PG,
																			SYSCFG_EXTICR_PH,
																			SYSCFG_EXTICR_PI
																		};

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */
static inline EXTI_Gpio_PortRefType Exti_Gpio_GetPortIndex(Gpio_PortIdType Port)
{
    return EXTI_Gpio_PortIndx[Port];
}
/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

EXTI_LineType EXTI_DEV_MapSourceToLine(const EXTI_SourceConfigType *src)
{
    switch (src->type)
    {
    case EXTI_SRC_GPIO:
        return src->id.gpioPin.pinNumber;

    case EXTI_SRC_TIMER:
        return 0;

    case EXTI_SRC_COMP:
        return 0;

    default:
        return 0;
    }
}

void EXTI_DEV_ConfigureRouting(const EXTI_SourceConfigType *src, EXTI_LineType line)
{
    if (EXTI_SRC_GPIO == src->type)
    {
    	if(SYSCFG_EXTCR_PORTNUM > src->id.gpioPin.portId)
    	{
        uint8_t port = Exti_Gpio_GetPortIndex(src->id.gpioPin.portId);
        SysCfg_LL_ConfEXTICR(port,line);
    	}
    }
}
