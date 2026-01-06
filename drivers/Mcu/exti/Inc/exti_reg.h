/*
 * exti_reg.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_REG_H_
#define EXTI_INC_EXTI_REG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Configuration Macros --------------------------------------------- */

/* -------------------- IMR BITS --------------------------- */
/* Link : @EXTI_INTERRUPT_MASK */
#define EXTI_IMR_Pos(pin)  			((pin)) /* Length 	:	1 Bit */
#define EXTI_IMR_Msk(pin)   		(1UL << EXTI_IMR_Pos(pin))
#define EXTI_IMR_Val(pin,v) 		(((v) & 0x1UL) << EXTI_IMR_Pos(pin))

#define EXTI_IMR_MASKED				(0UL)/* Interrupt request from line x is masked. */
#define EXTI_IMR_NOTMASKED			(1UL)/* Interrupt request from line x is not masked. */

/* -------------------- EMR BITS --------------------------- */
/* Link : @EXTI_EVENT_MASK */
#define EXTI_EMR_Pos(pin)  			((pin)) /* Length 	:	1 Bit */
#define EXTI_EMR_Msk(pin)   		(1UL << EXTI_EMR_Pos(pin))
#define EXTI_EMR_Val(pin,v) 		(((v) & 0x1UL) << EXTI_EMR_Pos(pin))

#define EXTI_EMR_MASKED				(0UL)/* Event request from line x is masked. */
#define EXTI_EMR_NOTMASKED			(1UL)/* Event request from line x is not masked. */

/* -------------------- RTSR BITS -------------------------- */
/* Link : @EXTI_RISINGTRIGGER */
#define EXTI_RTSR_Pos(pin)  		((pin)) /* Length 	:	1 Bit */
#define EXTI_RTSR_Msk(pin)   		(1UL << EXTI_RTSR_Pos(pin))
#define EXTI_RTSR_Val(pin,v) 		(((v) & 0x1UL) << EXTI_RTSR_Pos(pin))

#define EXTI_RTSR_DISABLED			(0UL)/* Rising trigger disabled (for Event and Interrupt) for input line. */
#define EXTI_RTSR_ENABLED			(1UL)/* Rising trigger enabled (for Event and Interrupt) for input line. */

/* -------------------- FTSR BITS -------------------------- */
/* Link : @EXTI_FALLINGTRIGGER */
#define EXTI_FTSR_Pos(pin)  		((pin)) /* Length 	:	1 Bit */
#define EXTI_FTSR_Msk(pin)   		(1UL << EXTI_FTSR_Pos(pin))
#define EXTI_FTSR_Val(pin,v) 		(((v) & 0x1UL) << EXTI_FTSR_Pos(pin))

#define EXTI_FTSR_DISABLED			(0UL)/* Falling trigger disabled (for Event and Interrupt) for input line. */
#define EXTI_FTSR_ENABLED			(1UL)/* Falling trigger enabled (for Event and Interrupt) for input line. */

/* -------------------- SWIER BITS ------------------------- */
/* Link : @EXTI_SWINTERRUPT */
/**
 * @def EXTI_SWIER_Pos
 * @brief If interrupt are enabled on line x in the EXTI_IMR register, writing '1' to SWIERx bit when it is
 * set at '0' sets the corresponding pending bit in the EXTI_PR register, thus resulting in an
 * interrupt request generation.
 * This bit is cleared by clearing the corresponding bit in EXTI_PR (by writing a 1 to the bit).*/

#define EXTI_SWIER_Pos(pin)  		((pin)) /* Length 	:	1 Bit */
#define EXTI_SWIER_Msk(pin)   		(1UL << EXTI_SWIER_Pos(pin))
#define EXTI_SWIER_Val(pin,v) 		(((v) & 0x1UL) << EXTI_SWIER_Pos(pin))

#define EXTI_SWIER_SET				(1UL)

/* -------------------- PR BITS ----------------------------- */
/* Link : @EXTI_PANDİNG */
/**
 * @def EXTI_PR_Pos
 * @brief	This bit is set when the selected edge event arrives on the external interrupt line.
 * This bit is cleared by programming it to ‘1’.
 *
 */
#define EXTI_PR_Pos(pin)  		((pin)) /* Length 	:	1 Bit */
#define EXTI_PR_Msk(pin)   		(1UL << EXTI_PR_Pos(pin))
#define EXTI_PR_Val(pin,v) 		(((v) & 0x1UL) << EXTI_PR_Pos(pin))

#define EXTI_PR_DISABLED		(0UL)/* No trigger request occurred. */
#define EXTI_PR_ENABLED			(1UL)/* selected trigger request occurred. */


#endif /* EXTI_INC_EXTI_REG_H_ */
