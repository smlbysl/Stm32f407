/*
 * spi_private_types.h
 *
 *  Created on: Jan 8, 2026
 *      Author: smlby
 */

#ifndef DRIVER_MCU_SPI_INC_SPI_SPI_PRIVATE_TYPES_H_
#define DRIVER_MCU_SPI_INC_SPI_SPI_PRIVATE_TYPES_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */


#include <std_types.h>
#include "spi_hw.h"
#include "spi_types.h"


/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */


/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */

//typedef uint8_t Spi_BitType;

/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Enumeration Definitions  ----------------------------------------- */
/* ---------------------------------------------------------------- */
/* ----------------- Generic Definitions -------------------------- */
typedef enum
{
	SPI_DISABLE = 0,
	SPI_ENABLE
}Spi_EnableType;

typedef enum
{
	SPI_LOW = 0,
	SPI_HIGH
}Spi_BitType;

/* ---------------------------------------------------------------- */
/* ----------------- HwUnit Definitions --------------------------- */
typedef enum
{
	SPI_SPI1 = 0,
	SPI_HWID_MAX,
	SPI_HWID_UNDEFINED
}Spi_HwUnitIdType;

typedef enum
{
    SPI_ARBITRATION_NONE,
    SPI_ARBITRATION_HW,     // NSS + MODF
    SPI_ARBITRATION_SW      // GPIO + timing
} Spi_ArbitrationType;


typedef enum
{
	SPI_HW_UNINIT = 0,
	SPI_HW_IDLE,
	SPI_HW_STATUS_MAX,
	SPI_HW_STATUS_UNDEFINED
}Spi_HwUnitStatusType;

/* ---------------------------------------------------------------- */
/* ----------------- ExDevice Definitions ------------------------- */
typedef enum
{
	SPI_SENSOR = 0,
	SPI_EXDEVID_MAX,
	SPI_EXDEVID_UNDEFINED
}Spi_ExDevIdType;

typedef enum
{
	SPI_BOUNDRATE_2 = 0,
	SPI_BOUNDRATE_4,
	SPI_BOUNDRATE_8,
	SPI_BOUNDRATE_16,
	SPI_BOUNDRATE_32,
	SPI_BOUNDRATE_64,
	SPI_BOUNDRATE_128,
	SPI_BOUNDRATE_256,
	SPI_BOUNDRATE_MAX
}Spi_BoundRateType;

/* ---------------------------------------------------------------- */
/* ----------------- Frame Definitions ---------------------------- */
typedef enum
{
	SPI_SLAVE = 0,
	SPI_MASTER,
	SPI_ROLE_MAX
}Spi_HwUnitRoleType;

typedef enum
{
	SPI_DATAFF_8BIT = 0,
	SPI_DATAFF_16BIT,
}Spi_DataFFType;

typedef enum
{
	SPI_FF_MSB = 0,
	SPI_FF_LSB,
}Spi_FrameFormatType;

typedef enum
{
	SPI_CLK_0  = 0,
	SPI_CLK_1
}Spi_ClockPolType;
typedef enum
{
	SPI_FIRSTDATA	= 0,
	SPI_SECONDDATA
}Spi_ClockPhaseType;

typedef enum
{
	SPI_MOTOROLA = 0,
	SPI_TI
}Spi_ProtocolType;

typedef enum
{
	SPI_FRAME_1 = 0,
	SPI_FRAME_MAX
}Spi_FrameType;


/* ---------------------------------------------------------------- */
/* ----------------- Channel Definitions -------------------------- */
typedef enum {
	SPI_CH_TX,
	SPI_CH_RX,
	SPI_CH_TXRX
} Spi_ChannelDirType;

typedef enum
{
	SPI_CHANNEL_1 = 0,
	SPI_CHANNEL_2,
	SPI_CHANNEL_3,
	SPI_CHANNEL_MAX
}Spi_ChannelIdType;

typedef enum
{
	SPI_CHANNEL_OK = 0,
	SPI_CHANNEL_PENDING,
	SPI_CHANNEL_FAILED,
}Spi_ChannelResultType;



/* ---------------------------------------------------------------- */
/* ----------------- Transfer Definitions ------------------------- */

typedef enum
{
    SPI_TRANSFER_POLLING,
    SPI_TRANSFER_INTERRUPT,
} Spi_TransferModeType;

/* ---------------------------------------------------------------- */
/* ----------------- Job Definitions ------------------------------ */
typedef enum
{
	SPI_JOB_1 = 0,
	SPI_JOB_2,
	SPI_JOB_MAX,
	SPI_JOB_UNDEFINED
}Spi_JobIdType;

typedef enum
{
	SPI_Job_INIT = 0,
	SPI_Job_PROCEDING,
	SPI_Job_IDLE
}Spi_JobStateMachType;

/* ---------------------------------------------------------------- */
/* ----------------- Sequence Definitions ------------------------- */

typedef enum
{
	SPI_SEQUENCE_1 = 0,
	SPI_SEQUENCE_MAX,
	SPI_SEQUENCE_UNDEFINED
}Spi_SequenceIdType;

typedef enum
{
	SPI_SEQUENCE_PRIO_0 = 0,
	SPI_SEQUENCE_PRIO,
	SPI_SEQUENCE_PRIO_UNDEFINED
}Spi_SeqPrioType;


typedef enum
{
	SPI_SEQUENCE_INIT = 0,
	SPI_SEQUENCE_PROCEDING,
	SPI_SEQUENCE_IDLE
}Spi_SeqStateMachType;


/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Struct Definitions  ---------------------------------------------- */
/* ---------------------------------------------------------------- */
/* ----------------- Frame Definitions ---------------------------- */
typedef struct
{
	Spi_DataFFType      	dataWidth;
	Spi_FrameFormatType 	bitOrder;
	Spi_ClockPolType    	cpol;
	Spi_ClockPhaseType  	cpha;
	Spi_ProtocolType    	protocol;
} Spi_FrameConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- HwUnit Definitions --------------------------- */
typedef struct
{
	Spi_HwUnitIdType   		id;
	Spi_Hw_RegType			*base;
	Spi_HwUnitRoleType		role;
	Spi_ArbitrationType		arbitration;
	Spi_EnableType    		dmaCapable;
	Spi_EnableType    		slaveCapable;
	Spi_EnableType			crcCapable;
}Spi_ControllerConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- ExDevice Definitions ------------------------- */
typedef struct
{
	Spi_ExDevIdType      			id;
	const Spi_ControllerConfigType 	*controller;
	Spi_FrameConfigType        		*frame;
	Spi_BoundRateType      			targetBaudrate;
	/*uint32_t               		csSetupTime;
	uint32_t               		csHoldTime;
	uint32_t               		csIdleTime;*/
} Spi_ExternalDeviceConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- Channel Definitions -------------------------- */
typedef struct
{
	Spi_ChannelDirType 	dir;
	uint16_t 			length;
} Spi_ChannelConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- Transfer Definitions ------------------------- */


/* ---------------------------------------------------------------- */
/* ----------------- Job Definitions ------------------------------ */

typedef struct
{
	Spi_JobIdType           		jobId;
    Spi_HwUnitIdType        		hwUnitID;
    Spi_ExDevIdType					exDeviceID;
    Spi_TransferModeType   			transferMode;
    const Spi_ChannelIdType* 		channelList;
    uint8_t            				channelCount;
} Spi_JobConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- Sequence Definitions ------------------------- */

typedef struct
{
	Spi_SequenceIdType           	sequenceId;
	Spi_HwUnitIdType        		hwUnitID;
	Spi_SeqPrioType					priority;
    const Spi_JobIdType				*jobList;
    uint8_t            				jobCount;
} Spi_SequenceConfigType;

/* ---------------------------------------------------------------- */
/* ----------------- Spi Definitions ------------------------------ */

typedef struct
{
    const Spi_ControllerConfigType*      controllerConfig;
    const Spi_ExternalDeviceConfigType*  externalDeviceConfig;
    const Spi_JobConfigType*             jobConfig;
    const Spi_ChannelConfigType*         channelConfig;
    const Spi_SequenceConfigType		*seqConfig;
} Spi_ConfigType;

typedef struct
{
    const Spi_ControllerConfigType*      controllerConfig;
    const Spi_ExternalDeviceConfigType*  externalDeviceConfig;
    const Spi_JobConfigType*             jobConfig;
    const Spi_ChannelConfigType*         channelConfig;
    const Spi_SequenceConfigType		*seqConfig;
} Spi_RunTimeConfigType;

/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- Runtime Definitions  --------------------------------------------- */

typedef struct
{
	Spi_JobResultType 	status;
}Spi_JobRuntimeType;

typedef struct
{
	Spi_ChannelResultType		status;
    uint16_t 					txIndex;
    uint16_t 					rxIndex;
    const uint16_t* 			txPtr;   // EB
    uint16_t*       			rxPtr;   // EB
} Spi_ChannelRuntimeType;

typedef struct
{
	Spi_HwUnitIdType			hwUnitId;
	Spi_HwUnitStatusType		hwStatus;
	Spi_ExDevIdType				exDevId;
} Spi_HwUnitRuntimeType;

typedef struct
{
	Spi_SequenceIdType			activeSequence;
	Spi_StatusType 				activeContStatus;
	Spi_JobIdType     			activeJobId;
	uint8_t						channelIndex;
	Spi_ChannelIdType			activeChannelId;
}Spi_ControllerRuntimeType;

typedef struct
{
	Spi_SequenceIdType           	sequenceId;
	Spi_SeqResultType        		status;
	Spi_SeqPrioType					priority;
	uint8_t							jobIndex;
}Spi_SequenceRuntimeType;

typedef struct
{
	Spi_StatusType 				activeContStatus;
	Std_boolean					hwDone;
	Spi_SequenceRuntimeType		*sequenceRnt;
	Spi_ControllerRuntimeType	*controllerRnt;
	Spi_HwUnitRuntimeType		*hwRnt;
	Spi_JobRuntimeType      	*jobRnt;
	Spi_ChannelRuntimeType		*channelRnt;
}Spi_DrvierRuntimeType;



#endif /* DRIVER_MCU_SPI_INC_SPI_SPI_PRIVATE_TYPES_H_ */
