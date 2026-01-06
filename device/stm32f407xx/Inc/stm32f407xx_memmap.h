/*
 * stm32f407xx_memmap.h
 *
 *  Created on: Dec 27, 2025
 *      Author: smlby
 */

#ifndef STM32F407XX_MEMMAP_H_
#define STM32F407XX_MEMMAP_H_

/* ====================================================================================================== */
/* --------------------------------------Base Addresses-------------------------------------------------- */

/*
 * Define the base addresses of the Flash and SRAM memories
 */

#define FLASH_BASEADDR			0x8000000U 			/*!< */
#define SRAM1_BASEADDR			0x2000000U 			/*!< 112 KB*/
#define SRAM2_BASEADDR			0x20001C0U 			/*!< 1C00*/
#define ROM_BASEADDR			0x1FFF000U 			/*!< */
#define SRAM					SRAM1_BASEADDR 		/*!< */

/*
 * AHBx and APBx Bus Peripheral Base Addresses
 */
#define PERIPH_BASE				0x40000000U			/*!< */
#define APB1PERIPH_BASEADDR		PERIPH_BASE			/*!< */
#define APB2PERIPH_BASEADDR		0x40010000U			/*!< */
#define AHB1PERIPH_BASEADDR		0x40020000U			/*!< */
#define AHB2PERIPH_BASEADDR		0x50000000U			/*!< */


/*
 * Peripheral Base Addresses of AHB1 Bus
 * TODO : Complete for all other peripherals
 *
 */

#define GPIOA_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x0000)		/*!< */
#define GPIOB_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x0400)		/*!< */
#define GPIOC_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x0800)		/*!< */
#define GPIOD_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x0C00)		/*!< */
#define GPIOE_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x1000)		/*!< */
#define GPIOF_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x1400)		/*!< */
#define GPIOG_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x1800)		/*!< */
#define GPIOH_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x1C00)		/*!< */
#define GPIOI_BASEADDR		 	(AHB1PERIPH_BASEADDR + 0x2000)		/*!< */

#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)		/*!< */
/*
 * Peripheral Base Addresses of APB1 Bus
 * TODO : Complete for all other peripherals
 *
 */

#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)		/*!< */
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)		/*!< */

#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)		/*!< */
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)		/*!< */
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)		/*!< */
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)		/*!< */
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)		/*!< */
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)		/*!< */
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)		/*!< */


/*
 * Peripheral Base Addresses of APB2 Bus
 * TODO : Complete for all other peripherals
 *
 */

#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)		/*!< */
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)		/*!< */

#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)		/*!< */

#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)		/*!< */
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)		/*!< */


/*
 * Base Addresses of EXTI
 * TODO : Complete for all other peripherals
 *
 */



/*----------- Interrupt Flash Addresses -------------------*/
#define PVD_BASEADDR			(FLASH_BASEADDR + 0x0044)
#define TAMP_STAMP_BASEADDR		(FLASH_BASEADDR + 0x0048)
#define RTC_WKUP_BASEADDR		(FLASH_BASEADDR + 0x004C)
#define EXTI0_BASEADDR			(FLASH_BASEADDR + 0x0058)
#define EXTI1_BASEADDR			(FLASH_BASEADDR + 0x005C)
#define EXTI2_BASEADDR			(FLASH_BASEADDR + 0x0060)
#define EXTI3_BASEADDR			(FLASH_BASEADDR + 0x0064)
#define EXTI4_BASEADDR			(FLASH_BASEADDR + 0x0068)
#define EXTIEXTI9_5_BASEADDR	(FLASH_BASEADDR + 0x009C) /*EXTI Line [9:5]*/
#define EXTIEXTI15_10_BASEADDR	(FLASH_BASEADDR + 0x00E0) /*EXTI Line [15:10]*/
#define RTC_Alarm_BASEADDR		(FLASH_BASEADDR + 0x00E4)
#define OTG_FS_WKUP_BASEADDR	(FLASH_BASEADDR + 0x00E8)
#define ETH_WKUP_BASEADDR		(FLASH_BASEADDR + 0x0138)
#define OTG_HS_WKUP_BASEADDR	(FLASH_BASEADDR + 0x0170)

/*
 * Base Addresses of SYSCFG
 * TODO : Complete for all other peripherals
 *
 */



#endif /* STM32F407XX_MEMMAP_H_ */
