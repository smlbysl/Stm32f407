/*
 * coretexm4_intrinsics.h
 *
 *  Created on: Jan 6, 2026
 *      Author: smlby
 */

#ifndef CORTEXM4_INC_CORTEXM4_INTRINSICS_H_
#define CORTEXM4_INC_CORTEXM4_INTRINSICS_H_

static inline void __enable_irq(void)
{
    __asm volatile ("cpsie i" ::: "memory");
}

static inline void __disable_irq(void)
{
    __asm volatile ("cpsid i" ::: "memory");
}

#endif /* CORTEXM4_INC_CORTEXM4_INTRINSICS_H_ */
