/*
 * cortexM4_nvic.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef CORTEXM4_INC_CORTEXM4_NVIC_H_
#define CORTEXM4_INC_CORTEXM4_NVIC_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>

#include "cortexm4_memmap.h"

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */


typedef struct
{
	volatile uint32_t		ISER[8]; 		/*!< Interrupt Set-enable Registers,           	offset: 0x0000 	length:	0x020  -   32 byte	*/
	uint32_t 				RESERVED1[24];	/*!< RESERVED,            						offset: 0x0020  length:	0x060  -   96 byte	*/
	volatile uint32_t 		ICER[8];	 	/*!< Interrupt Clear-enable Registers,			offset: 0x0080	length: 0x020  -   32 byte	*/
	uint32_t 				RESERVED2[24];	/*!< RESERVED,            						offset: 0x00A0 	length:	0x020  -   96 byte	*/
	volatile uint32_t 		ISPR[8];		/*!< Interrupt Set-pending Registers,			offset: 0x0100 	length:	0x020  -   32 byte	*/
	uint32_t 				RESERVED3[24];	/*!< RESERVED,            						offset: 0x0120 	length:	0x060  -   96 byte	*/
	volatile uint32_t 		ICPR[8]; 		/*!< Interrupt Clear-pending Registers,			offset: 0x0180 	length:	0x020  -   32 byte	*/
	uint32_t 				RESERVED4[24];	/*!< RESERVED,            						offset: 0x0120 	length:	0x060  -   96 byte	*/
	volatile uint32_t 		IABR[8]; 		/*!< Interrupt Active Bit Registers,       		offset: 0x0200 	length:	0x020  -   32 byte	*/
	uint32_t 				RESERVED5[56];	/*!< RESERVED,            						offset: 0x0120 	length:	0x0E0  -  224 byte	*/
	volatile uint32_t 		IPR[60]; 		/*!< Interrupt Priority Registers,				offset: 0x0300 	length:	0x0F0  -  240 byte 	*/
	uint32_t 				RESERVED6[644];	/*!< RESERVED,            						offset: 0x0120 	length:	0xA10  - 2576 byte 	*/
	volatile uint32_t 		STIR; 			/*!< Software Trigger Interrupt Register,   	offset: 0xE00 	length:	0x004  -    4 byte  */

}NVIC_RegType;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define NVIC			 ((NVIC_RegType*)NVIC_BASEADDR)

/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */
/* -------------------- MODER ---------------------------- */


/* -------------------- TYPE ----------------------------- */


#endif /* CORTEXM4_INC_CORTEXM4_NVIC_H_ */
