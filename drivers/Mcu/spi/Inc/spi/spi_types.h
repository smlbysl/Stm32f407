/*
 * spi_types.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_TYPES_H_
#define MCU_SPI_INC_SPI_SPI_TYPES_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */


#include <std_types.h>


/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */


/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

/**
 * @link 	[SWS_Spi_00376]
 * @brief 	Type of application data buffer elements
 */
typedef uint8_t		Spi_DataBufferType;
/**
 * @link 	[SWS_Spi_00377]
 * @brief 	Type for defining the number of data elements to send and / or receive by Channel
 */
typedef uint16_t	Spi_NumberOfDataType;
/**
 * @link 	[SWS_Spi_00378]
 * @brief 	Specifies the identification (ID) for a Channel.
 */
typedef uint8_t		Spi_ChannelType;
/**
 * @link 	[SWS_Spi_00379]
 * @brief 	Specifies the identification (ID) for a Job.
 */
typedef uint16_t	Spi_JobType;
/**
 * @link 	[SWS_Spi_00380]
 * @brief 	Specifies the identification (ID) for a sequence of jobs.
 */
typedef uint8_t		Spi_SequenceType;
/**
 * @link 	[SWS_Spi_00381]
 * @brief 	Specifies the identification (ID) for a SPI Hardware microcontroller peripheral (unit).
 */
typedef uint8_t 	Spi_HWUnitType;

/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Enumeration Definitions  ----------------------------------------- */
/**
 * @enum
 * @link 	[SWS_Spi_00373]⌈
 * @brief 	This type defines a range of specific status for SPI Handler/Driver.
 *
 *			[SWS_Spi_00259] The type Spi_StatusType can be obtained calling the API ser-vice Spi_GetStatus
 *			[SWS_Spi_00260] The type Spi_StatusType can be obtained calling the API ser-vice Spi_GetHWUnitStatus.
 *			[SWS_Spi_00011] After reset, the type Spi_StatusType shall have the default value SPI_UNINIT.
 *			[SWS_Spi_00345] API service Spi_GetStatus shall return SPI_UNINIT when the SPI Handler/Driver is not initialized or not usable.
 */
typedef enum
{
	SPI_UNINIT = 0,		/*!< The SPI Handler/Driver is not initialized or not usable. *//**< SPI_UNINIT */
	SPI_IDLE,			/*!< The SPI Handler/Driver is not currently transmitting any Job. *//**< SPI_IDLE */
	SPI_BUSY			/*!< The SPI Handler/Driver is performing a SPI Job (transmit). */    /**< SPI_BUSY */
}Spi_StatusType;

/**
 * @enum
 * @link 	[SWS_Spi_00374]
 * @brief	This type defines a range of specific Jobs status for SPI Handler/Driver.
 *
 * 			[SWS_Spi_00012] After reset, the type Spi_JobResultType shall have the de-fault value SPI_JOB_OK.
 * 			[SWS_Spi_00261] The type Spi_JobResultType it informs about a SPI Han-dler/Driver Job status and
 * 			can be obtained calling the API service Spi_GetJobResult with the Job ID.
 *
 */
typedef enum
{
	SPI_JOB_OK = 0,		/*!< The last transmission of the Job has been finished successfully. */
	SPI_JOB_PENDING,	/*!< The SPI Handler/Driver is performing a SPI Job. The meaning of this status is equal to SPI_BUSY. */
	SPI_JOB_FAILED,		/*!< The last transmission of the Job has failed */
	SPI_JOB_QUEUED		/*!< An asynchronous transmit Job has been accepted, while actual transmission for this Job has not started yet.*/
}Spi_JobResultType;


/**
 * @enum
 * @link 	[SWS_Spi_00375]
 * @brief	This type defines a range of specific Sequences status for SPI Handler/Driver
 *
 *			[SWS_Spi_00017] After reset, the type Spi_SeqResultType shall have the de-fault value SPI_SEQ_OK.
 * 			[SWS_Spi_00351] The type Spi_SeqResultType defines a range of specific Se-quences status for SPI Handler/Driver and can be obtained
 * 			calling the API service Spi_GetSequenceResult, it shall be provided for external use.
 * 			[SWS_Spi_00251] The type Spi_SeqResultType defines about SPI Handler/Driver Sequence status and can be obtained calling the API service
 * 			Spi_GetSequenceResult with the Sequence ID.
 *
 */
typedef enum
{
	SPI_SEQ_OK = 0,		/*!< The last transmission of the Sequence has been finished successfully. */
	SPI_SEQ_PENDING,	/*!< The SPI Handler/Driver is performing a SPI Sequence. The meaning of this status is equal to SPI_BUSY. */
	SPI_SEQ_FAILED,		/*!< The last transmission of the Sequence has failed. */
	SPI_SEQ_CANCELED	/*!< The last transmission of the Sequence has been canceled by user.*/
}Spi_SeqResultType;

/**
 * @enum
 * @link  	[SWS_Spi_00382]
 * @brief 	Specifies the asynchronous mechanism mode for SPI busses handled asynchronously.
 *
 */
typedef enum
{
	SPI_POLLING_MODE = 0,	/*!< The asynchronous mechanism is ensured by polling, so interrupts related to SPI busses handled asynchronously are disabled. */
	SPI_INTERRUPT_MODE		/*!< The asynchronous mechanism is ensured by interrupt, so interrupts related to SPI busses handled asynchronously are enabled. */
}Spi_AsyncModeType;
/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Struct Definitions  ---------------------------------------------- */


#endif /* MCU_SPI_INC_SPI_SPI_TYPES_H_ */
