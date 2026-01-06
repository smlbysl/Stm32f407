/*
 * gpio_types.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef DRIVER_GPIO_TYPES_H_
#define DRIVER_GPIO_TYPES_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */


#include <std_types.h>


/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */

/*----------- Pin Numbers ------------*/
#define GPIO_PIN_NO_0	(0u)
#define GPIO_PIN_NO_1	(1u)
#define GPIO_PIN_NO_2	(2u)
#define GPIO_PIN_NO_3	(3u)
#define GPIO_PIN_NO_4	(4u)
#define GPIO_PIN_NO_5	(5u)
#define GPIO_PIN_NO_6	(6u)
#define GPIO_PIN_NO_7	(7u)
#define GPIO_PIN_NO_8	(8u)
#define GPIO_PIN_NO_9	(9u)
#define GPIO_PIN_NO_10	(10u)
#define GPIO_PIN_NO_11	(11u)
#define GPIO_PIN_NO_12	(12u)
#define GPIO_PIN_NO_13	(13u)
#define GPIO_PIN_NO_14	(14u)
#define GPIO_PIN_NO_15	(15u)

/*----------- Port IDs ----------------*/
#define GPIO_PA_ID		(0u)
#define GPIO_PB_ID		(1u)
#define GPIO_PC_ID		(2u)
#define GPIO_PD_ID		(3u)
#define GPIO_PE_ID		(4u)
#define GPIO_PF_ID		(5u)
#define GPIO_PG_ID		(6u)
#define GPIO_PH_ID		(7u)
#define GPIO_PI_ID		(8u)


/*----------- Pin Level ----------------*/

#define GPIO_PIN_LEVEL_LOW	0U
#define GPIO_PIN_LEVEL_HIGH	1U


/* ========================================================================================================= */
/* -------------------------------------- Type Definitions  ------------------------------------------------ */
typedef uint8_t Gpio_ChannelRefType;

typedef uint8_t	Gpio_PinLevelType;
typedef uint16_t Gpio_PortLevetType;

typedef uint8_t Gpio_U8CounterType;



typedef uint8_t Gpio_PortIdType;
typedef uint8_t Gpio_PinNumberType;

typedef uint8_t Gpio_PinModeType;
typedef uint8_t Gpio_PinOutputType;
typedef uint8_t Gpio_PinSpeedType;
typedef uint8_t Gpio_PinPullType;
typedef uint8_t Gpio_PinAltFuncType;

/*------------------- Pin Config Type ---------------*/
typedef struct
{
    Gpio_PortIdType      portId;
    Gpio_PinNumberType   pinNumber;

    Gpio_PinModeType     mode;			/*!< Possible values : @GPIO_PIN_MODES */
    Gpio_PinOutputType   outputType;	/*!< Possible values : @GPIO_PIN_OTYPES */
    Gpio_PinSpeedType    speed;			/*!< Possible values : @GPIO_PIN_OSPEEDS */
    Gpio_PinPullType     pull;			/*!< Possible values : @GPIO_PIN_PUPDS */
    Gpio_PinAltFuncType  alternate;		/*!< Possible values : @GPIO_PIN_AFRS */
} Gpio_PinConfig_t;

/*------------------- Handle Type -------------------*/
typedef struct
{
	const Gpio_PinConfig_t		*GPIO_PinConfig;
	const Gpio_U8CounterType	PinCounter;
	Std_boolean					isInitialized;
} GPIO_Handle_t;

typedef struct
{
    Gpio_PortIdType      portId;
    Gpio_PinNumberType   pinNumber;
} Gpio_ChannelConfigType;

/*typedef struct
{
	const Gpio_PinConfig_t			*GPIO_PinConfig;
	const Gpio_U8CounterType		PinCounter;
	const Gpio_ChannelConfigType 	*GPI_Channels;
	const Gpio_U8CounterType		ChannelCounter;
	boolean 						isInitialized;
} GPIO_Handle_t;

typedef struct
{
    Gpio_PortIdType      	portId;
    Gpio_PinNumberType   	pinNumber;
    Gpio_U8CounterType		configReference;
} Gpio_ChannelConfigType;
 *
 *
 */

#endif /* DRIVER_GPIO_TYPES_H_ */
