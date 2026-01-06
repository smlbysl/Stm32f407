/*
 * Cortex_M4.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef CORTEXM4_INC_CORTEXM4_MEMMAP_H_
#define CORTEXM4_INC_CORTEXM4_MEMMAP_H_
/*!< Interrupt mask register,           	offset: 0x00 */

/* ====================================================================================================== */
/* --------------------------------------Base Addresses-------------------------------------------------- */


#define PPB_BASEADDR			0xE0000000 /*!< Private Peripheral Bus (PPB) */

#define NVIC_BASEADDR			(PPB_BASEADDR + 0xE100)


#endif /* CORTEXM4_INC_CORTEXM4_MEMMAP_H_ */
