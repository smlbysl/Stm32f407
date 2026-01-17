/*
 * nvic_ll.h
 *
 *  Created on: Jan 6, 2026
 *      Author: smlby
 */

#ifndef NVIC_INC_NVIC_LL_H_
#define NVIC_INC_NVIC_LL_H_



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "nvic_hw.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */
#define NVIC_SET_HIGH	1u
/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */





/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */

/**
 * @fn void Nvic_LL_EnableInterrutpt(Nvic_Bit_PosType)
 * @brief
 *
 * @param pos
 */
static inline void Nvic_LL_EnableIRQ(Nvic_IrqType irq)
{
	NVIC_SYS->ISER[irq/32] = (NVIC_SYS->ISER[irq/32] & ~NVIC_ISER_Msk(irq % 32)) | (NVIC_ISER_Val(irq % 32,NVIC_SET_HIGH));
}
/**
 * @fn void Nvic_LL_DisableInterrutpt(Nvic_Bit_PosType)
 * @brief
 *
 * @param pos
 */
static inline void Nvic_LL_DisableIRQ(Nvic_IrqType irq)
{
	NVIC_SYS->ICER[irq/32] = (NVIC_SYS->ICER[irq/32] & ~NVIC_ICER_Msk(irq % 32)) | (NVIC_ICER_Val(irq % 32,NVIC_SET_HIGH));
}
/**
 * @fn void Nvic_LL_ForceToPendingState(Nvic_Bit_PosType)
 * @brief
 *
 * @param pos
 */
static inline void Nvic_LL_ForceToPendingState(Nvic_IrqType irq)
{
	NVIC_SYS->ISPR[irq/32] = (NVIC_SYS->ISPR[irq/32] & ~NVIC_ISPR_Msk(irq % 32)) | (NVIC_ISPR_Val(irq % 32,NVIC_SET_HIGH));
}
/**
 * @fn void Nvic_LL_ClearPendingState(Nvic_Bit_PosType)
 * @brief
 *
 * @param pos
 */
static inline void Nvic_LL_ClearPendingState(Nvic_IrqType irq)
{
	NVIC_SYS->ICPR[irq/32] = (NVIC_SYS->ICPR[irq/32] & ~NVIC_ICPR_Msk(irq % 32)) | (NVIC_ICPR_Val(irq % 32 ,NVIC_SET_HIGH));
}
/**
 * @fn void Nvic_LL_TriggerFromSw(Nvic_Bit_PosType)
 * @brief
 *
 * @param pos
 */
static inline void Nvic_LL_TriggerFromSw(Nvic_IrqType irq)
{
	NVIC_SYS->STIR = (NVIC_SYS->STIR & ~NVIC_STIR_Msk) | (NVIC_STIR_Val(NVIC_SET_HIGH));
}

static inline void Nvic_LL_SetPriority(Nvic_IrqType irq)
{

}

#endif /* NVIC_INC_NVIC_LL_H_ */
