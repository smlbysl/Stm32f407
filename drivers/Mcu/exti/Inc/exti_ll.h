/*
 * exti_ll.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_LL_H_
#define EXTI_INC_EXTI_LL_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <exti_hw.h>
#include <exti_types.h>

/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */
/**
 * @fn void Exti_LL_ConfRTSR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_SetEDGE(const EXTI_LineType line, const EXTI_EdgeType edge)
{
	if (edge == EXTI_EDGE_RISING || edge == EXTI_EDGE_BOTH)
    {
    	EXTI_HW_EXTI->RTSR = (EXTI_HW_EXTI->RTSR & ~EXTI_RTSR_Msk(line)) | EXTI_RTSR_Val(line,1);
    }

    if (edge == EXTI_EDGE_FALLING || edge == EXTI_EDGE_BOTH)
    {
    	EXTI_HW_EXTI->FTSR = (EXTI_HW_EXTI->RTSR & ~EXTI_RTSR_Msk(line)) | EXTI_RTSR_Val(line,1);
    }
}
/**
 * @fn void EXTI_LL_ClearFlag(uint8_t)
 * @brief
 *
 * @param line
 */
static inline void Exti_LL_ClearFlag(uint8_t line)
{
	//EXTI_HW_EXTI->PR = (EXTI_HW_EXTI->PR & ~EXTI_PR_Msk(line)) | EXTI_PR_Val(line,1);   /* Write 1 to clear */
	EXTI_HW_EXTI->PR = EXTI_PR_Msk(line);
}


/**
 * @fn void Exti_LL_ConfIMR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConfIMR(const EXTI_LineType line, const uint8_t val)
{
	EXTI_HW_EXTI->IMR = (EXTI_HW_EXTI->IMR & ~EXTI_IMR_Msk(line)) | EXTI_IMR_Val(line,val);
}

/**
 * @fn void Exti_LL_ConfEMR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConfEMR(const uint8_t val,const EXTI_LineType line)
{
	EXTI_HW_EXTI->EMR = (EXTI_HW_EXTI->EMR & ~EXTI_EMR_Msk(line)) | EXTI_EMR_Val(line,val);
}

/**
 * @fn void Exti_LL_ConfRTSR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConfRTSR(const uint8_t val,const EXTI_LineType line)
{
	EXTI_HW_EXTI->RTSR = (EXTI_HW_EXTI->RTSR & ~EXTI_RTSR_Msk(line)) | EXTI_RTSR_Val(line,val);
}
/**
 * @fn void Exti_LL_ConfFTSR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConfFTSR(const uint8_t val,const EXTI_LineType line)
{
	EXTI_HW_EXTI->FTSR = (EXTI_HW_EXTI->FTSR & ~EXTI_FTSR_Msk(line)) | EXTI_FTSR_Val(line,val);
}
/**
 * @fn void Exti_LL_ConfSWER(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConfSWIER(const uint8_t val,const EXTI_LineType line)
{
	EXTI_HW_EXTI->SWIER = (EXTI_HW_EXTI->SWIER & ~EXTI_SWIER_Msk(line)) | EXTI_SWIER_Val(line,val);
}
/**
 * @fn void Exti_LL_ConPR(const uint8_t, const EXTI_LineType)
 * @brief
 *
 * @param val
 * @param line
 */
static inline void Exti_LL_ConPR(const uint8_t val,const EXTI_LineType line)
{
	EXTI_HW_EXTI->PR = (EXTI_HW_EXTI->PR & ~EXTI_PR_Msk(line)) | EXTI_PR_Val(line,val);
}




#endif /* EXTI_INC_EXTI_LL_H_ */
