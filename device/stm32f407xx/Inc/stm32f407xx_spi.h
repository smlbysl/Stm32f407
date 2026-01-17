/*
 * stm32f407xx_spi.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef STM32F407XX_INC_STM32F407XX_SPI_H_
#define STM32F407XX_INC_STM32F407XX_SPI_H_


/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

#include <stdint.h>
#include <stm32f407xx_memmap.h>

/* ========================================================================================================= */
/* -------------------------------------- REGISTER DEFINITION ---------------------------------------------- */
/**
 * @struct
 * @brief
 * It is possible to switch the interface from SPI to I2S by software.
 *
 */

typedef struct
{
	volatile uint32_t		CR1; 		/*!< SPI control register,           		offset: 0x00 */
	volatile uint32_t 		CR2; 		/*!< SPI control register 2,				offset: 0x04 */
	volatile uint32_t 		SR; 		/*!< SPI status register,					offset: 0x08 */
	volatile uint32_t 		DR; 		/*!< SPI data register,						offset: 0x0C */
	volatile uint32_t 		CRCPR; 		/*!< SPI CRC polynomial register,       	offset: 0x10 */
	volatile uint32_t 		RXCRCR; 	/*!< SPI RX CRC register,					offset: 0x14 */
	volatile uint32_t 		TXCRCR; 	/*!< SPI TX CRC register,   				offset: 0x18 */
	volatile uint32_t 		I2SCFGR; 	/*!< SPI_I2S configuration register, 		offset: 0x1C */
	volatile uint32_t		I2SPR; 		/*!< SPI_I2S prescaler register,  			offset: 0x20 */
}Spi_Spi_RegType;

typedef struct
{
			 uint32_t		Reserved1;	/*!< Not used in I2S mode,          	 	offset: 0x00 */
	volatile uint32_t 		CR2; 		/*!< SPI control register 2,				offset: 0x04 */
	volatile uint32_t 		SR; 		/*!< SPI status register			,		offset: 0x08 */
	volatile uint32_t 		DR; 		/*!< SPI data register,						offset: 0x0C */
			 uint32_t 		Reserved2;	/*!< Not used in I2S mode,			       	offset: 0x10 */
			 uint32_t 		Reserved3;	/*!< Not used in I2S mode,			       	offset: 0x14 */
			 uint32_t 		Reserved4;	/*!< Not used in I2S mode,			       	offset: 0x18 */
	volatile uint32_t 		I2SCFGR; 	/*!< SPI_I2S configuration register, 		offset: 0x1C */
	volatile uint32_t		I2SPR; 		/*!< SPI_I2S prescaler register, 			offset: 0x20 */
}Spi_I2s_RegType;


/* ========================================================================================================= */
/* -------------------------------------- Peripheral Definitions ------------------------------------------- */

#define SPI1   		((Spi_Spi_RegType *)(SPI1_BASEADDR))
#define SPI2   		((Spi_Spi_RegType *)(SPI2_BASEADDR))
#define SPI3   		((Spi_Spi_RegType *)(SPI3_BASEADDR))

#define I2S1   		((Spi_I2s_RegType *)(SPI1_BASEADDR))
#define I2S2   		((Spi_I2s_RegType *)(SPI2_BASEADDR))
#define I2S3   		((Spi_I2s_RegType *)(SPI3_BASEADDR))


/* ========================================================================================================= */
/* -------------------------------------- Reset Values ----------------------------------------------------- */


#endif /* STM32F407XX_INC_STM32F407XX_SPI_H_ */
