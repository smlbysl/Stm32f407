/*
 * syscfg_hw.h
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_SYSCFG_HW_H_
#define EXTI_INC_SYSCFG_HW_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>
#include <stm32f407xx_syscfg.h>
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/* =================================================== */
/*------------------- Port Definition ---------------- */

typedef SYSCFG_RegDef_t SYSCFG_Hw_SysCfgType;

/* =================================================== */
/*------------------- Port Definition ---------------- */


/* =================================================== */
/*------------------- Register Type Definition ------- */


/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

#define SYSCFG_HW_SYSCFG   ((SYSCFG_Hw_SysCfgType*)SYSCFG)

#define SYSCFG_EXTCR_PORTNUM	((Gpio_PortIdType)9)
#define SYSCFG_EXTICR_PA		0u
#define SYSCFG_EXTICR_PB		1u
#define SYSCFG_EXTICR_PC		2u
#define SYSCFG_EXTICR_PD		3u
#define SYSCFG_EXTICR_PE		4u
#define SYSCFG_EXTICR_PF		5u
#define SYSCFG_EXTICR_PG		6u
#define SYSCFG_EXTICR_PH		7u
#define SYSCFG_EXTICR_PI		8u


/* -------------------- Generic ------------------------------ */



#endif /* EXTI_INC_SYSCFG_HW_H_ */
