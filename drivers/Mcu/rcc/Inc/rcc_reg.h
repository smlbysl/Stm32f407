/*
 * RCC_Reg.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef RCC_INC_RCC_REG_H_
#define RCC_INC_RCC_REG_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Configuration Macros --------------------------------------------- */

/* ==================== RCC CFGR Register ==================== */
/* -------------------- MCO1 bits ---------------------------- */
#define RCC_CFGR_MCO1_Pos			(21u)/*2 Bit*/
#define RCC_CFGR_MCO1_Msk			(3UL << RCC_CFGR_MCO1_Pos)/*0b11*/
#define RCC_CFGR_MCO1_SRC_HSI		(0UL) /*0b00*/
#define RCC_CFGR_MCO1_SRC_LSE		(1UL) /*0b01*/
#define RCC_CFGR_MCO1_SRC_HSE		(2UL) /*0b10*/
#define RCC_CFGR_MCO1_SRC_PLL		(3UL) /*0b11*/
#define RCC_CFGR_MCO1(val)			(((val) & 0x3UL) << RCC_CFGR_MCO1_Pos)

/* -------------------- MCOPRE bits -------------------------- */
#define RCC_CFGR_MCO1PRE_Pos  		(24U) /*3 bit*/
#define RCC_CFGR_MCO1PRE_Msk	  	(7UL << RCC_CFGR_MCO1PRE_Pos) /*0b111*/
#define RCC_CFGR_MCO1PRE_DIV1  		(0U)/* No Division 0b0xx*/
#define RCC_CFGR_MCO1PRE_DIV2  		(4U)/* Division by 2 : 0b100*/
#define RCC_CFGR_MCO1PRE_DIV3  		(5U)/* Division by 3 : 0b101*/
#define RCC_CFGR_MCO1PRE_DIV4  		(6U)/* Division by 4 : 0b110*/
#define RCC_CFGR_MCO1PRE_DIV5  		(7U)/* Division by 5 : 0b111*/
#define RCC_CFGR_MCO1PRE(val)		(((val) & 0x7UL) << RCC_CFGR_MCO1PRE_Pos)

/* -------------------- SWS bits ----------------------------- */
#define RCC_CFGR_SWS_Pos	  		(2U)
#define RCC_CFGR_SWS_Msk	  		(3UL << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSI	  		(0U)/*HSI : 0b00*/
#define RCC_CFGR_SWS_HSE	  		(1U)/*HSE : 0b01*/
#define RCC_CFGR_SWS_PLL	  		(2U)/*PLL : 0b10*/
/* Read-only status bits */

/* -------------------- SW bits ------------------------------ */
#define RCC_CFGR_SW_Pos	  			(0U)/*2 bit*/
#define RCC_CFGR_SW_Msk	  			(3UL << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSI	  			(0U)/*HSI : 0b00*/
#define RCC_CFGR_SW_HSE	  			(1U)/*HSE : 0b01*/
#define RCC_CFGR_SW_PLL	  			(2U)/*PLL : 0b10*/
#define RCC_CFGR_SW(val)	  		(((val) & 0x3UL) << RCC_CFGR_SW_Pos)

/* ==================== RCC AHB1ENR Register ================= */
/* -------------------- AHB1ENR bits ------------------------- */
#define RCC_AHB1ENR_GPIOAEN_Pos		(0U)/*1 bit*/
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN_EN		(1U)/*Enable : 0b1*/
#define RCC_AHB1ENR_GPIOAEN(val)	(((val) & 0x1UL) << RCC_AHB1ENR_GPIOAEN_Pos)

/* ==================== RCC CR Register ====================== */
/* -------------------- HSEON bits --------------------------- */
#define RCC_CR_HSEON_Pos			(16) /*1 Bit*/
#define RCC_CR_HSEON_Msk			(1UL << RCC_CR_HSEON_Pos)
#define RCC_CR_HSEON_ON				(1U)/*ON : 0b1*/
#define RCC_CR_HSEON(val)			(((val) & 0x1UL) << RCC_CR_HSEON_Pos)

/* -------------------- HSERDY bits -------------------------- */
#define RCC_CR_HSERDY_Pos			(17) /*1 Bit*/
#define RCC_CR_HSERDY_Msk			(1UL << RCC_CR_HSERDY_Pos)
#define RCC_CR_HSERDY_RDY			(1UL)

#endif /* RCC_INC_RCC_REG_H_ */
