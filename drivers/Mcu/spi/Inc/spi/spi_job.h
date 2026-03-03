/*
 * spi_job.h
 *
 *  Created on: Jan 20, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_JOB_H_
#define MCU_SPI_INC_SPI_SPI_JOB_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private_types.h"
#include "spi_channel.h"
#include "spi_hwunit.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

typedef enum
{
    SPI_JOB_STATE_IDLE,
    SPI_JOB_STATE_SCHEDULED,
    SPI_JOB_STATE_ACTIVE,
    SPI_JOB_STATE_WAIT_HW,
    SPI_JOB_STATE_COMPLETED,
    SPI_JOB_STATE_FAILED
}Spi_JobStateType;

/* ========================================================================================================= */
/* -------------------------------------- Extern Definitions  ---------------------------------------------- */
extern Spi_JobRuntimeType 			jobRnt[SPI_JOB_MAX];
/* ========================================================================================================= */
/* -------------------------------------- API Definitions  ------------------------------------------------- */
void Spi_JobHandler_Init(void);

void Spi_JobHandler(void);
Std_ReturnType Spi_JobHandler_StartJob(Spi_JobIdType requestJobId);


#endif /* MCU_SPI_INC_SPI_SPI_JOB_H_ */
