/*
 * exti_dev.h
 *
 *  Created on: Jan 4, 2026
 *      Author: smlby
 */

#ifndef EXTI_INC_EXTI_DEV_H_
#define EXTI_INC_EXTI_DEV_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <exti_hw.h>
#include <exti_ll.h>
#include <exti_types.h>
#include <syscfg_hw.h>
#include <syscfg_ll.h>
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */
/*------------------- Port Config of EXTICR ----------------*/
#define SYSCFG_HW_EXTICR_PA		SYSCFG_EXTICR_PA
#define SYSCFG_HW_EXTICR_PB		SYSCFG_EXTICR_PB
#define SYSCFG_HW_EXTICR_PC		SYSCFG_EXTICR_PC
#define SYSCFG_HW_EXTICR_PD		SYSCFG_EXTICR_PD
#define SYSCFG_HW_EXTICR_PE		SYSCFG_EXTICR_PE
#define SYSCFG_HW_EXTICR_PF		SYSCFG_EXTICR_PF
#define SYSCFG_HW_EXTICR_PG		SYSCFG_EXTICR_PG
#define SYSCFG_HW_EXTICR_PH		SYSCFG_EXTICR_PH
#define SYSCFG_HW_EXTICR_PI		SYSCFG_EXTICR_PI
/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */

EXTI_LineType EXTI_DEV_MapSourceToLine(const EXTI_SourceConfigType *src);
void EXTI_DEV_ConfigureRouting(const EXTI_SourceConfigType *src, EXTI_LineType line);

#endif /* EXTI_INC_EXTI_DEV_H_ */
