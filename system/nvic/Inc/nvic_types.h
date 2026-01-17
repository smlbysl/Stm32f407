/*
 * nvic_types.h
 *
 *  Created on: Jan 6, 2026
 *      Author: smlby
 */

#ifndef NVIC_INC_NVIC_TYPES_H_
#define NVIC_INC_NVIC_TYPES_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "stdint.h"
#include "std_types.h"

/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
typedef uint8_t Nvic_Bit_PosType;
typedef uint8_t Nvic_Bit_ValType;

typedef uint16_t Nvic_IrqType;
typedef uint8_t NvicIrqPrioType;

typedef struct
{
	Nvic_IrqType		hwIrq;
	NvicIrqPrioType 	priority;
} Nvic_IrqConfigType;

#endif /* NVIC_INC_NVIC_TYPES_H_ */
