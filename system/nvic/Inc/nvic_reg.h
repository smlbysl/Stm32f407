/*
 * nvic_reg.h
 *
 *  Created on: Jan 6, 2026
 *      Author: smlby
 */

#ifndef SYS_NVIC_INC_NVIC_REG_H_
#define SYS_NVIC_INC_NVIC_REG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Configuration Macros --------------------------------------------- */

/* -------------------- ISER BITS --------------------------- */
/* Link : @NVIC_INT_ENABLE */
#define NVIC_ISER_Pos(SETENA)  			(SETENA) /* Length 	:	1 Bit */
#define NVIC_ISER_Msk(SETENA)  			(1UL << NVIC_ISER_Pos(SETENA))
#define NVIC_ISER_Val(SETENA,v) 		(((v) & 0x1UL) << NVIC_ISER_Pos(SETENA))

#define NVIC_ISER_WRITE_ENABLE			(1UL)/* Write : enable interrupt. */
#define NVIC_ISER_READ_DISABLED			(0UL)/* Read : Interrupt disabled. */
#define NVIC_ISER_READ_ENABLED			(1UL)/* Read : Interrupt enabled. */

/* -------------------- ICER BITS --------------------------- */
/* Link : @NVIC_INT_CLEAR */
#define NVIC_ICER_Pos(CLRENA)  			(CLRENA) /* Length 	:	1 Bit */
#define NVIC_ICER_Msk(CLRENA)   		(1UL << NVIC_ICER_Pos(CLRENA))
#define NVIC_ICER_Val(CLRENA,v) 		(((v) & 0x1UL) << NVIC_ICER_Pos(CLRENA))

#define NVIC_ICER_WRITE_ENABLE			(1UL)/* Write : Disable interrupt. */
#define NVIC_ICER_READ_DISABLED			(0UL)/* Read : Interrupt disabled. */
#define NVIC_ICER_READ_ENABLED			(1UL)/* Read : Interrupt enabled. */

/* -------------------- ISPR BITS --------------------------- */
/* Link : @NVIC_INT_CLEAR */
#define NVIC_ISPR_Pos(SETPEND)  		(SETPEND) /* Length 	:	1 Bit */
#define NVIC_ISPR_Msk(SETPEND)   		(1UL << NVIC_ISPR_Pos(SETPEND))
#define NVIC_ISPR_Val(SETPEND,v) 		(((v) & 0x1UL) << NVIC_ISPR_Pos(SETPEND))

#define NVIC_ISPR_WRITE_ENABLE			(1UL)/* Write : Changes interrupt state to pending. */
#define NVIC_ISPR_READ_DISABLED			(0UL)/* Read : Interrupt is not pending. */
#define NVIC_ISPR_READ_ENABLED			(1UL)/* Read : Interrupt is pending. */

/* -------------------- ICPR BITS --------------------------- */
/* Link : @NVIC_INT_CLEAR */
#define NVIC_ICPR_Pos(CLRPEND)  		(CLRPEND) /* Length 	:	1 Bit */
#define NVIC_ICPR_Msk(CLRPEND)   		(1UL << NVIC_ICPR_Pos(CLRPEND))
#define NVIC_ICPR_Val(CLRPEND,v) 		(((v) & 0x1UL) << NVIC_ICPR_Pos(CLRPEND))

#define NVIC_ICPR_WRITE_ENABLE			(1UL)/* Write : Removes pending state an interrupt. */
#define NVIC_ICPR_READ_DISABLED			(0UL)/* Read : Interrupt is not pending. */
#define NVIC_ICPR_READ_ENABLED			(1UL)/* Read : Interrupt is pending. */

/* -------------------- IABR BITS --------------------------- */
/* Link : @NVIC_INT_CLEAR */
#define NVIC_IABR_Pos(ACTIVE)  			(ACTIVE) /* Length 	:	1 Bit */
#define NVIC_IABR_Msk(ACTIVE)   		(1UL << NVIC_IABR_Pos(ACTIVE))
#define NVIC_IABR_Val(ACTIVE,v) 		(((v) & 0x1UL) << NVIC_IABR_Pos(ACTIVE))

#define NVIC_IABR_READ_DISABLED			(0UL)/* Read : Interrupt not active. */
#define NVIC_IABR_READ_ENABLED			(1UL)/* Read : Interrupt active. */

/* -------------------- IPR BITS ---------------------------- */
/* Link : @NVIC_INT_CLEAR */
#define NVIC_IPR_Pos(BYTEOFFSET)  		((BYTEOFFSET & 0x3UL)*8) /* Length 	:	1 Bit */
#define NVIC_IPR_Msk(BYTEOFFSET)   		(0x0FUL << NVIC_IPR_Pos(BYTEOFFSET))
#define NVIC_IPR_Val(BYTEOFFSET,v) 		(((v) & 0xF0UL) << NVIC_IPR_Pos(BYTEOFFSET))

/* -------------------- STIR BITS --------------------------- */
/* Link : @NVIC_INT_CLEAR */
/**
 * @def NVIC_STIR
 * @brief
 * Write to the STIR to generate an interrupt from software. See the register summary in Table 4-2
 * on page 4-3 for the STIR attributes.
 * When the USERSETMPEND bit in the SCR is set to 1, unprivileged software can access the
 * STIR
 *Interrupt ID of the interrupt to trigger, in the range 0-239. For example, a value of
 * 0x03 specifies interrupt IRQ3.
 */
#define NVIC_STIR_Pos  			(0) 								/* Length 	:	8 Bit */
#define NVIC_STIR_Msk   		(0x0F1UL << NVIC_STIR_Pos)
#define NVIC_STIR_Val(v) 		(((v) & 0x0FUL) << NVIC_STIR_Pos)



#endif /* SYS_NVIC_INC_NVIC_REG_H_ */
