/*
 * nvic.h
 *
 *  Created on: Jan 6, 2026
 *      Author: smlby
 */

#ifndef NVIC_INC_NVIC_H_
#define NVIC_INC_NVIC_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "nvic_types.h"
/* ========================================================================================================= */
/* ---------------------------------------------------------------------------------------------------------
 * 									API Supported by this Driver
 * 					For more information about the APIs check the function definitions
 * --------------------------------------------------------------------------------------------------------- */

Std_ReturnType Nvic_EnableIRQ(Nvic_IrqType irq);
Std_ReturnType Nvic_SetIRQPriority(Nvic_IrqType irq);

#endif /* NVIC_INC_NVIC_H_ */
