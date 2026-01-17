/*
 * spi_reg.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef DRIVER_MCU_SPI_INC_SPI_SPI_REG_H_
#define DRIVER_MCU_SPI_INC_SPI_SPI_REG_H_

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Configuration Macros --------------------------------------------- */

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- CR1 BITS ---------------------------------------------------- */
/* Link : @SPI_CR1*/
/* ----------------------------------------------- */
/* ------------------ CPHA ----------------------- */
/**
 * @def 	SPI_CR1_CPHA
 * @brief 	Clock phase
 * @link 	@SPI_CR1_CPHA
 * @note	This bit should not be changed when communication is ongoing.
 */
#define SPI_CR1_CPHA_Pos  				(0u)
#define SPI_CR1_CPHA_Msk		   		(0x01UL << SPI_CR1_CPHA_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_CPHA_Val(v) 			(((v) & 0x1UL) << SPI_CR1_CPHA_Pos)

#define SPI_CR1_CPHA_CAPTFIRST			(0UL)	/*!< The first clock transition is the first data capture edge. */
#define SPI_CR1_CPHA_CAPTSECOND			(1UL)	/*!< The second clock transition is the first data capture edge. */

/* ----------------------------------------------- */
/* ------------------ CPOL ----------------------- */
/**
 * @def 	SPI_CR1_CPOL
 * @brief 	Clock polarity
 * @link 	@SPI_CR1_CPOL
 * @note	This bit should not be changed when communication is ongoing.
 */
#define SPI_CR1_CPOL_Pos  				(1u)
#define SPI_CR1_CPOL_Msk		   		(0x01UL << SPI_CR1_CPOL_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_CPOL_Val(v) 			(((v) & 0x1UL) << SPI_CR1_CPOL_Pos)

#define SPI_CR1_CPOL_CK0				(0UL)	/*!< CK to 0 when idle. */
#define SPI_CR1_CPOL_CK1				(1UL)	/*!< CK to 1 when idle. */

/* ----------------------------------------------- */
/* ------------------ MSTR ----------------------- */
/**
 * @def 	SPI_CR1_MSTR
 * @brief 	Master selection
 * @link 	@SPI_CR1_MSTR
 * @note	This bit should not be changed when communication is ongoing.
 */
#define SPI_CR1_MSTR_Pos  				(2u)
#define SPI_CR1_MSTR_Msk		   		(0x01UL << SPI_CR1_MSTR_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_MSTR_Val(v) 			(((v) & 0x1UL) << SPI_CR1_MSTR_Pos)

#define SPI_CR1_MSTR_SLAVE				(0UL)	/*!< Slave configuration. */
#define SPI_CR1_MSTR_MASTER				(1UL)	/*!< Master configuration. */

/* ----------------------------------------------- */
/* ------------------ BR ------------------------- */
/**
 * @def 	SPI_CR1_BR
 * @brief 	Baud rate control
 * @link 	@SPI_CR1_BR
 * @note 	These bits should not be changed when communication is ongoing.
 */
#define SPI_CR1_BR_Pos  				(3u)
#define SPI_CR1_BR_Msk		   			(0x07UL << SPI_CR1_BR_Pos)	/*!< Length : 3 Bit */
#define SPI_CR1_BR_Val(v) 				(((v) & 0x7UL) << SPI_CR1_BR_Pos)

#define SPI_CR1_BR_DIV2					(0UL)	/*!< fPCLK/2 */
#define SPI_CR1_BR_DIV4					(1UL)	/*!< fPCLK/4. */
#define SPI_CR1_BR_DIV8					(2UL)	/*!< fPCLK/8. */
#define SPI_CR1_BR_DIV16				(3UL)	/*!< fPCLK/16. */
#define SPI_CR1_BR_DIV32				(4UL)	/*!< fPCLK/32. */
#define SPI_CR1_BR_DIV64				(5UL)	/*!< fPCLK/64. */
#define SPI_CR1_BR_DIV128				(6UL)	/*!< fPCLK/128. */
#define SPI_CR1_BR_DIV256				(7UL)	/*!< fPCLK/256. */

/* ----------------------------------------------- */
/* ------------------ SPE ----------------------- */
/**
 * @def 	SPI_CR1_SPE
 * @brief 	SPI enable
 * @link 	@SPI_CR1_SPE
 * @note
 */
#define SPI_CR1_SPE_Pos  				(6u)
#define SPI_CR1_SPE_Msk		   			(0x01UL << SPI_CR1_SPE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_SPE_Val(v) 				(((v) & 0x1UL) << SPI_CR1_SPE_Pos)

#define SPI_CR1_SPE_DIS					(0UL)	/*!< Peripheral disabled. */
#define SPI_CR1_SPE_EN					(1UL)	/*!< Peripheral enabled. */

/* ----------------------------------------------- */
/* ------------------ LSBFIRST ------------------- */
/**
 * @def 	SPI_CR1_LSBFIRST
 * @brief 	Receive only
 * @link 	@SPI_CR1_LSBFIRST
 * @note 	This bit should not be changed when communication is ongoing.
 */
#define SPI_CR1_LSBFIRST_Pos  			(7u)
#define SPI_CR1_LSBFIRST_Msk		   	(0x01UL << SPI_CR1_LSBFIRST_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_LSBFIRST_Val(v) 		(((v) & 0x1UL) << SPI_CR1_LSBFIRST_Pos)

#define SPI_CR1_LSBFIRST_FIRSTMSB		(0UL)	/*!< MSB transmitted first. */
#define SPI_CR1_LSBFIRST_FIRSTLSB		(1UL)	/*!< LSB transmitted first */

/* ----------------------------------------------- */
/* ------------------ SSI ------------------------ */
/**
 * @def 	SPI_CR1_SSI
 * @brief 	Internal slave select
 * @link 	@SPI_CR1_SSI
 * @note 	This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
 *  		NSS pin and the IO value of the NSS pin is ignored.
 */
#define SPI_CR1_SSI_Pos  				(8u)
#define SPI_CR1_SSI_Msk		   			(0x01UL << SPI_CR1_SSI_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_SSI_Val(v) 				(((v) & 0x1UL) << SPI_CR1_SSI_Pos)

#define SPI_CR1_SSI_LOW				0u
#define SPI_CR1_SSI_HIGH				1u
/* ----------------------------------------------- */
/* ------------------ SSM ------------------------ */
/**
 * @def 	SPI_CR1_SSM
 * @brief 	Software slave management
 * @link 	@SPI_CR1_SSM
 * @note 	This bit combined with the BIDImode bit selects the direction of transfer in 2-line
 * 			unidirectional mode. This bit is also useful in a multislave system in which this particular
 * 			slave is not accessed, the output from the accessed slave is not corrupted.
 */
#define SPI_CR1_SSM_Pos  				(9u)
#define SPI_CR1_SSM_Msk		   			(0x01UL << SPI_CR1_SSM_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_SSM_Val(v) 				(((v) & 0x1UL) << SPI_CR1_SSM_Pos)

#define SPI_CR1_SSM_DIS					(0UL)	/*!< Software slave management disabled. */
#define SPI_CR1_SSM_EN					(1UL)	/*!< Software slave management enabled */

/* ----------------------------------------------- */
/* ------------------ RXONLY --------------------- */
/**
 * @def 	SPI_CR1_RXONLY
 * @brief 	Receive only
 * @link 	@SPI_CR1_RXONLY
 * @note 	This bit combined with the BIDImode bit selects the direction of transfer in 2-line
 * 			unidirectional mode. This bit is also useful in a multislave system in which this particular
 * 			slave is not accessed, the output from the accessed slave is not corrupted.
 */
#define SPI_CR1_RXONLY_Pos  			(10u)
#define SPI_CR1_RXONLY_Msk		   		(0x01UL << SPI_CR1_RXONLY_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_RXONLY_Val(v) 			(((v) & 0x1UL) << SPI_CR1_RXONLY_Pos)

#define SPI_CR1_RXONLY_FullDub			(0UL)	/*!< Full duplex (Transmit and receive). */
#define SPI_CR1_RXONLY_OUTDIS			(1UL)	/*!< Output disabled (Receive-only mode) */

/* ----------------------------------------------- */
/* ------------------ DFF ------------------------ */
/**
 * @def 	SPI_CR1_DFF
 * @brief 	Data frame format
 * @link 	@SPI_CR1_DFF
 * @note 	This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
 */
#define SPI_CR1_DFF_Pos  				(11u)
#define SPI_CR1_DFF_Msk		   			(0x01UL << SPI_CR1_DFF_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_DFF_Val(v) 				(((v) & 0x1UL) << SPI_CR1_DFF_Pos)

#define SPI_CR1_DFF_8Bit				(0UL)	/*!< 8-bit data frame format is selected for transmission/reception. */
#define SPI_CR1_DFF_16Bit				(1UL)	/*!< 16-bit data frame format is selected for transmission/reception */

/* ----------------------------------------------- */
/* ------------------ CRCNEXT -------------------- */
/**
 * @def 	SPI_CR1_CRCNEXT
 * @brief 	CRC transfer next
 * @link 	@SPI_CR1_CRCNEXT
 * @note 	When the SPI is configured in full duplex or transmitter only modes,
 * 			CRCNEXT must be	written as soon as the last data is written to the SPI_DR register.
 *			When the SPI is configured in receiver only mode, CRCNEXT must be set after the
 * 			second last data reception.
 * 			This bit should be kept cleared when the transfers are managed by DMA.
 */
#define SPI_CR1_CRCNEXT_Pos  			(12u)
#define SPI_CR1_CRCNEXT_Msk		   		(0x01UL << SPI_CR1_CRCNEXT_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_CRCNEXT_Val(v) 			(((v) & 0x1UL) << SPI_CR1_CRCNEXT_Pos)

#define SPI_CR1_CRCNEXT_DATAP			(0UL)	/*!< Data phase (no CRC phase). */
#define SPI_CR1_CRCNEXT_CRCP			(1UL)	/*!< Next transfer is CRC (CRC phase) */

/* ----------------------------------------------- */
/* ------------------ CRCEN ---------------------- */
/**
 * @def 	SPI_CR1_CRCEN
 * @brief 	Hardware CRC calculation enable
 * @link 	@SPI_CR1_CRCEN
 * @note	This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
 */
#define SPI_CR1_CRCEN_Pos  				(13u)
#define SPI_CR1_CRCEN_Msk		   		(0x01UL << SPI_CR1_CRCEN_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_CRCEN_Val(v) 			(((v) & 0x1UL) << SPI_CR1_CRCEN_Pos)

#define SPI_CR1_CRCEN_DIS				(0UL)	/*!< CRC calculation disabled. */
#define SPI_CR1_CRCEN_EN				(1UL)	/*!< CRC calculation enabled. */

/* ----------------------------------------------- */
/* ------------------ BIDIOE --------------------- */
/**
 * @def 	SPI_CR1_BIDIOE
 * @brief 	Output enable in bidirectional mode
 * @link 	@SPI_CR1_BIDIOE
 * @note	In master mode, the MOSI pin is used while the MISO pin is used in slave mode.
 *
 */
#define SPI_CR1_BIDIOE_Pos  			(14u)
#define SPI_CR1_BIDIOE_Msk		   		(0x01UL << SPI_CR1_BIDIOE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_BIDIOE_Val(v) 			(((v) & 0x1UL) << SPI_CR1_BIDIOE_Pos)

#define SPI_CR1_BIDIOE_DIS				(0UL)	/*!< Output disabled (receive-only mode). */
#define SPI_CR1_BIDIOE_EN				(1UL)	/*!< Output enabled (transmit-only mode). */

/* ----------------------------------------------- */
/* ------------------ BIDIMODE ------------------- */
/**
 * @def		SPI_CR1_BIDIMODE
 * @brief	Bidirectional data mode enable
 * @link	@SPI_CR1_BIDIMOD
 *
 */
#define SPI_CR1_BIDIMODE_Pos  			(15u)
#define SPI_CR1_BIDIMODE_Msk		   	(0x01UL << SPI_CR1_BIDIMODE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR1_BIDIMODE_Val(v) 		(((v) & 0x1UL) << SPI_CR1_BIDIMODE_Pos)

#define SPI_CR1_BIDIMODE_UNDI			(0UL)	/* 2-line unidirectional data mode selected. */
#define SPI_CR1_BIDIMODE_BIDI			(1UL)	/* 1-line bidirectional data mode selected. */

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- CR2 BITS ---------------------------------------------------- */
/* Link : @SPI_CR2*/

/* ----------------------------------------------- */
/* ------------------ RXDMAEN -------------------- */
/**
 * @def 	SPI_CR2_RXDMAEN
 * @brief 	Tx buffer DMA enable
 * @link 	@SPI_CR2_RXDMAEN
 * @note	When this bit is set, the DMA request is made whenever the RXNE flag is set.
 */
#define SPI_CR2_RXDMAEN_Pos  			(0u)
#define SPI_CR2_RXDMAEN_Msk		   		(0x01UL << SPI_CR2_RXDMAEN_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_RXDMAEN_Val(v) 			(((v) & 0x1UL) << SPI_CR2_RXDMAEN_Pos)

#define SPI_CR2_RXDMAEN_DIS				(0UL)	/*!< Rx buffer DMA disabled. */
#define SPI_CR2_RXDMAEN_EN				(1UL)	/*!< Rx buffer DMA enabled   */

/* ----------------------------------------------- */
/* ------------------ TXDMAEN -------------------- */
/**
 * @def 	SPI_CR2_TXDMAEN
 * @brief 	Tx buffer DMA enable
 * @link 	@SPI_CR2_TXDMAEN
 * @note	When this bit is set, the DMA request is made whenever the TXE flag is set.
 */
#define SPI_CR2_TXDMAEN_Pos  			(1u)
#define SPI_CR2_TXDMAEN_Msk		   		(0x01UL << SPI_CR2_TXDMAEN_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_TXDMAEN_Val(v) 			(((v) & 0x1UL) << SPI_CR2_TXDMAEN_Pos)

#define SPI_CR1_TXDMAEN_DIS				(0UL)	/*!< Tx buffer DMA disabled. */
#define SPI_CR1_TXDMAEN_EN				(1UL)	/*!< Tx buffer DMA enabled   */

/* ----------------------------------------------- */
/* ------------------ SSOE ----------------------- */
/**
 * @def 	SPI_CR2_SSOE
 * @brief 	SS output enable
 * @link 	@SPI_CR2_SSOE
 * @note	This bit is not used in I2S mode and SPI TI mode
 */
#define SPI_CR2_SSOE_Pos  				(2u)
#define SPI_CR2_SSOE_Msk		   		(0x01UL << SPI_CR2_SSOE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_SSOE_Val(v) 			(((v) & 0x1UL) << SPI_CR2_SSOE_Pos)

#define SPI_CR1_SSOE_DIS				(0UL)	/*!< SS output is disabled in master mode and the cell can work in multimaster configuration. */
#define SPI_CR1_SSOE_EN					(1UL)	/*!< SS output is enabled in master mode and when the cell is enabled. The cell cannot work   */
												/*   in a multimaster environment.. */

/* ----------------------------------------------- */
/* ------------------ FRF ------------------------ */
/**
 * @def 	SPI_CR2_FRF
 * @brief 	Frame format
 * @link 	@SPI_CR2_FRF
 * @note
 */
#define SPI_CR2_FRF_Pos  				(4u)
#define SPI_CR2_FRF_Msk		   			(0x01UL << SPI_CR2_FRF_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_FRF_Val(v) 				(((v) & 0x1UL) << SPI_CR2_FRF_Pos)

#define SPI_CR1_FRF_MOT					(0UL)	/*!< SPI Motorola mode. */
#define SPI_CR1_FRF_TI					(1UL)	/*!< SPI TI mode. */

/* ----------------------------------------------- */
/* ------------------ ERRIE ---------------------- */
/**
 * @def 	SPI_CR2_ERRIE
 * @brief 	Error interrupt enable
 * @link 	@SPI_CR2_ERRIE
 * @note	This bit controls the generation of an interrupt when an error condition occurs )(CRCERR,
 *			OVR, MODF in SPI mode, FRE in TI mode and UDR, OVR, and FRE in I2S mode).
 */
#define SPI_CR2_ERRIE_Pos  				(5u)
#define SPI_CR2_ERRIE_Msk		   		(0x01UL << SPI_CR2_ERRIE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_ERRIE_Val(v) 			(((v) & 0x1UL) << SPI_CR2_ERRIE_Pos)

#define SPI_CR1_ERRIE_INTDIS			(0UL)	/*!< Error interrupt is masked. */
#define SPI_CR1_ERRIE_INTEN				(1UL)	/*!< Error interrupt is enabled. */

/* ----------------------------------------------- */
/* ------------------ RXNEIE --------------------- */
/**
 * @def 	SPI_CR2_RXNEIE
 * @brief 	RX buffer not empty interrupt enable
 * @link 	@SPI_CR2_RXNEIE
 * @note
 */
#define SPI_CR2_RXNEIE_Pos  			(6u)
#define SPI_CR2_RXNEIE_Msk		   		(0x01UL << SPI_CR2_RXNEIE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_RXNEIE_Val(v) 			(((v) & 0x1UL) << SPI_CR2_RXNEIE_Pos)

#define SPI_CR1_RXNEIE_INTDIS			(0UL)	/*!< RXNE interrupt masked. */
#define SPI_CR1_RXNEIE_INTEN			(1UL)	/*!< RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set. */

/* ----------------------------------------------- */
/* ------------------ TXEIE ---------------------- */
/**
 * @def 	SPI_CR2_TXEIE
 * @brief 	Tx buffer empty interrupt enable
 * @link 	@SPI_CR2_TXEIE
 * @note
 */
#define SPI_CR2_TXEIE_Pos  				(7u)
#define SPI_CR2_TXEIE_Msk		   		(0x01UL << SPI_CR2_TXEIE_Pos)	/*!< Length : 1 Bit */
#define SPI_CR2_TXEIE_Val(v) 			(((v) & 0x1UL) << SPI_CR2_TXEIE_PSs)

#define SPI_CR1_TXEIE_INTDIS			(0UL)	/*!< TXE interrupt masked. */
#define SPI_CR1_TXEIE_INTEN				(1UL)	/*!< TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set. */

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- SR BITS ----------------------------------------------------- */
/**
 * @def 	SPI status register
 * @brief
 * @link  	@SPI_SR
 */

/* ----------------------------------------------- */
/* ------------------ RXNE ----------------------- */
/**
 * @def 	SPI_SR_RXNE
 * @brief 	Receive buffer not empty
 * @link 	@SPI_SR_RXNE
 * @note
 */
#define SPI_SR_RXNE_Pos  				(0u)
#define SPI_SR_RXNE_Msk		   			(0x01UL << SPI_SR_RXNE_Pos)	/*!< Length : 1 Bit */

#define SPI_SR_RXNE_EMTY				(0UL)	/*!< Rx buffer empty. */
#define SPI_SR_RXNE_NOTEMTY				(1UL)	/*!< Rx buffer not empty.   */

/* ----------------------------------------------- */
/* ------------------ TXE ------------------------ */
/**
 * @def 	SPI_SR_TXE
 * @brief 	Transmit buffer empty
 * @link 	@SPI_SR_TXE
 * @note
 */
#define SPI_SR_TXE_Pos  				(1u)
#define SPI_SR_TXE_Msk		   			(0x01UL << SPI_SR_TXE_Pos)	/*!< Length : 1 Bit */

#define SPI_SR_TXE_NOTEMTY				(0UL)	/*!< Tx buffer not empty. */
#define SPI_SR_TXE_EMTY					(1UL)	/*!< Tx buffer empty.   */

/* ----------------------------------------------- */
/* ------------------ CHSIDE --------------------- */
/**
 * @def 	SPI_SR_CHSIDE
 * @brief 	Channel side
 * @link 	@SPI_SR_CHSIDE
 * @note	This bit is not used for SPI mode and is meaningless in PCM mode.
 */
#define SPI_SR_CHSIDE_Pos  				(2u)
#define SPI_SR_CHSIDE_Msk		   		(0x01UL << SPI_SR_CHSIDE_Pos)	/*!< Length : 1 Bit */

#define SPI_SR_CHSIDE_LEFT				(0UL)	/*!< Channel Left has to be transmitted or has been received. */
#define SPI_SR_CHSIDE_RIGTH				(1UL)	/*!< Channel Right has to be transmitted or has been received.   */

/* ----------------------------------------------- */
/* ------------------ UDR ------------------------ */
/**
 * @def 	SPI_SR_UDR
 * @brief 	Underrun flag
 * @link 	@SPI_SR_UDR
 * @note	This flag is set by hardware and reset by a software sequence.
 * 			This bit is not used in SPI mode.
 */
#define SPI_SR_UDR_Pos  				(3u)
#define SPI_SR_UDR_Msk		   			(0x01UL << SPI_SR_UDR_Pos)	/*!< Length : 1 Bit */
#define SPI_SR_UDR_RESET 				(0x00UL << SPI_SR_UDR_Pos)

#define SPI_SR_UDR_NOUNDRUN				(0UL)	/*!< No underrun occurred. */
#define SPI_SR_UDR_UNDRUN				(1UL)	/*!< Underrun occurred.   */

/* ----------------------------------------------- */
/* ------------------ CRCERR --------------------- */
/**
 * @def 	SPI_SR_CHSIDE
 * @brief 	CRC error flag
 * @link 	@SPI_SR_CHSIDE
 * @note	This flag is set by hardware and cleared by software writing 0.
 */
#define SPI_SR_CRCERR_Pos  				(4u)
#define SPI_SR_CRCERR_Msk		   		(0x01UL << SPI_SR_CRCERR_Pos)	/*!< Length : 1 Bit */
#define SPI_SR_CRCERR_CLEAR 			(0x00UL << SPI_SR_CRCERR_Pos)

#define SPI_SR_CRCERR_MATCH				(0UL)	/*!< CRC value received matches the SPI_RXCRCR value. */
#define SPI_SR_CRCERR_NOTMATCH			(1UL)	/*!< CRC value received does not match the SPI_RXCRCR value.   */

/* ----------------------------------------------- */
/* ------------------ MODF ----------------------- */
/**
 * @def 	SPI_SR_MODF
 * @brief 	CRC error flag
 * @link 	@SPI_SR_MODF
 * @note	This flag is set by hardware and reset by a software sequence.
 */
#define SPI_SR_MODF_Pos  				(5u)
#define SPI_SR_MODF_Msk		   			(0x01UL << SPI_SR_MODF_Pos)	/*!< Length : 1 Bit */
#define SPI_SR_MODF_RESET 				(0x00UL << SPI_SR_MODF_Pos)

#define SPI_SR_MODF_NOFAULT				(0UL)	/*!< No mode fault occurred. */
#define SPI_SR_MODF_FAULT				(1UL)	/*!< Mode fault occurred.   */

/* ----------------------------------------------- */
/* ------------------ OVR ------------------------ */
/**
 * @def 	SPI_SR_OVR
 * @brief 	Overrun flag
 * @link 	@SPI_SR_OVR
 * @note	This flag is set by hardware and reset by a software sequence.
 */
#define SPI_SR_OVR_Pos  				(6u)
#define SPI_SR_OVR_Msk		   			(0x01UL << SPI_SR_OVR_Pos)	/*!< Length : 1 Bit */
#define SPI_SR_OVR_RESET 				(0x00L << SPI_SR_OVR_Pos)

#define SPI_SR_OVR_NOOVERR				(0UL)	/*!< No overrun occurred. */
#define SPI_SR_OVR_OVERR				(1UL)	/*!< Overrun occurred.   */

/* ----------------------------------------------- */
/* ------------------ BSY ------------------------ */
/**
 * @def 	SPI_SR_BSY
 * @brief 	Busy flag
 * @link 	@SPI_SR_BSY
 * @note	This flag is set and cleared by hardware.
 * 			BSY flag must be used with caution
 */
#define SPI_SR_BSY_Pos  				(7u)
#define SPI_SR_BSY_Msk		   			(0x01UL << SPI_SR_BSY_Pos)	/*!< Length : 1 Bit */

#define SPI_SR_BSY_NOTBUSY				(0UL)	/*!< SPI (or I2S) not busy. */
#define SPI_SR_BSY_BUSY					(1UL)	/*!< SPI (or I2S) is busy in communication or Tx buffer is not empty.   */

/* ----------------------------------------------- */
/* ------------------ FRE ------------------------ */
/**
 * @def 	SPI_SR_FRE
 * @brief 	Frame format error
 * @link 	@SPI_SR_FRE
 * @note	This flag is set by hardware and cleared by software when the SPIx_SR register is read.
 * 			This flag is used when the SPI operates in TI slave mode or I2S slave mode.
 */
#define SPI_SR_FRE_Pos  				(8u)
#define SPI_SR_FRE_Msk		   			(0x01UL << SPI_SR_FRE_Pos)	/*!< Length : 1 Bit */
#define SPI_SR_FRE_RESET 				(0x00UL << SPI_SR_FRE_Pos)

#define SPI_SR_FRE_NOFFE				(0UL)	/*!< No frame format error. */
#define SPI_SR_FRE_FFE					(1UL)	/*!< A frame format error occurred.   */


/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- DR BITS ----------------------------------------------------- */
/**
 * @def 	SPI data register
 * @brief
 * @link  	@SPI_DR
 */

/* ----------------------------------------------- */
/* ------------------ DR ------------------------- */
/**
 * @def 	SPI_DR_DR
 * @brief 	Data register
 * @link 	@SPI_DR_DR
 * @note	Data received or to be transmitted
 * 			The data register is split into 2 buffers - one for writing (Transmit Buffer) and another one for
 *			reading (Receive buffer). A write to the data register writes into the Tx buffer and a read
 * 			from the data register returns the value held in the Rx buffer.
 * 				Note: 	These notes apply to SPI mode:
 *						Depending on the data frame format selection bit (DFF in SPI_CR1 register), the data
 *						sent or received is either 8-bit or 16-bit. This selection has to be made before enabling
 *						the SPI to ensure correct operation.
 *						For an 8-bit data frame, the buffers are 8-bit and only the LSB of the register
 *						(SPI_DR[7:0]) is used for transmission/reception. When in reception mode, the MSB of
 *						the register (SPI_DR[15:8]) is forced to 0.
 *						For a 16-bit data frame, the buffers are 16-bit and the entire register, SPI_DR[15:0] is
 *						used for transmission/reception.
 */
#define SPI_DR_DR_Pos  					(0u)
#define SPI_DR_DR_Msk		   			(0xFFFFUL << SPI_DR_DR_Pos)	/*!< Length : 1 Bit */

#define SPI_DR_DR_WRITE_8B(v)  			(((v) & 0xFF) << SPI_DR_DR_Pos)
#define SPI_DR_DR_WRITE_16B(v) 			(((v) & 0xFFFF) << SPI_DR_DR_Pos)

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- CRCPR BITS -------------------------------------------------- */
/**
 * @def 	SPI CRC polynomial register
 * @brief
 * @link  	@SPI_CRCPR
 */
/* ----------------------------------------------- */
/* ------------------ CRCPOLY -------------------- */
/**
 * @def 	SPI_CRCPR_CRCPOLY
 * @brief 	CRC polynomial register
 * @link 	@SPI_CRCPR_CRCPOLY
 * @note	This register contains the polynomial for the CRC calculation.
 * 			The CRC polynomial (0007h) is the reset value of this register. Another polynomial can be
 *			configured as required.
 *			These bits are not used for the I2S mode
 */
#define SPI_CRCPR_CRCPOLY_Pos  			(0u)
#define SPI_CRCPR_CRCPOLY_Msk		   	(0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos)	/*!< Length : 1 Bit */

#define SPI_CRCPR_CRCPOLY_8B(v)  		(((v) & 0xFF) << SPI_SR_RXNE_Pos)
#define SPI_CRCPR_CRCPOLY_16B(v) 		(((v) & 0xFFFF) << SPI_SR_RXNE_Pos)

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- RXCRCR BITS -------------------------------------------------- */
/**
 * @def 	SPI RX CRC register
 * @brief
 * @link  	@SPI_RXCRCR
 */
/* ----------------------------------------------- */
/* ------------------ RXCRC ---------------------- */
/**
 * @def 	SPI_RXCRCR_RXCRC
 * @brief 	Rx CRC register
 * @link 	@SPI_RXCRCR_RXCRC
 * @note	When CRC calculation is enabled, the RxCRC[15:0] bits contain the computed CRC value of
 *			the subsequently received bytes. This register is reset when the CRCEN bit in SPI_CR1
 *			register is written to 1. The CRC is calculated serially using the polynomial programmed in
 *			the SPI_CRCPR register.
 *			Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF
 *			bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
 *			The entire 16-bits of this register are considered when a 16-bit data frame format is selected
 *			(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16
 *			standard
 *			A read to this register when the BSY Flag is set could return an incorrect value.
 *			These bits are not used for I2S mode.
 *
 *  */
#define SPI_RXCRCR_RXCRC_Pos  			(0u)
#define SPI_RXCRCR_RXCRC_Msk		   	(0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)	/*!< Length : 1 Bit */

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- TXCRCR BITS -------------------------------------------------- */
/**
 * @def 	SPI RX CRC register
 * @brief
 * @link  	@SPI_RXCRCR
 */
/* ----------------------------------------------- */
/* ------------------ TXCRC ---------------------- */
/**
 * @def 	SPI_TXCRCR_TXCRC
 * @brief 	Tx CRC register
 * @link 	@SPI_TXCRCR_TXCRC
 * @note	When CRC calculation is enabled, the TxCRC[7:0] bits contain the computed CRC value of
 *			the subsequently transmitted bytes. This register is reset when the CRCEN bit of SPI_CR1
 *			is written to 1. The CRC is calculated serially using the polynomial programmed in the
 *			SPI_CRCPR register.
 *			Only the 8 LSB bits are considered when the data frame format is set to be 8-bit data (DFF
 *			bit of SPI_CR1 is cleared). CRC calculation is done based on any CRC8 standard.
 *			The entire 16-bits of this register are considered when a 16-bit data frame format is selected
 *			(DFF bit of the SPI_CR1 register is set). CRC calculation is done based on any CRC16
 *			standard.
 *			A read to this register when the BSY flag is set could return an incorrect value.
 *			These bits are not used for I2S mode.
 *
 *  */
#define SPI_TXCRCR_TXCRC_Pos  			(0u)
#define SPI_TXCRCR_TXCRC_Msk		   	(0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)	/*!< Length : 1 Bit */

/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- I2SCFGR BITS ------------------------------------------------ */
/**
 * @def 	SPI RX CRC register
 * @brief
 * @link  	@SPI_RXCRCR
 */
/* ----------------------------------------------- */
/* ------------------ CHLEN ---------------------- */
/**
 * @def 	SPI_I2SCFGR_CHLEN
 * @brief 	Channel length (number of bits per audio channel)
 * @link 	@SPI_I2SCFGR_CHLEN
 * @note	The bit write operation has a meaning only if DATLEN = 00 otherwise the channel length is fixed to
 *			32-bit by hardware whatever the value filled in. Not used in SPI mode.
 *			For correct operation, this bit should be configured when the I2S is disabled.
 *  */
#define SPI_I2SCFGR_CHLEN_Pos  			(0u)
#define SPI_I2SCFGR_CHLEN_Msk		   	(0x01UL << SPI_I2SCFGR_CHLEN_Pos)	/*!< Length : 1 Bit */
#define SPI_I2SCFGR_CHLEN_Val(v) 		(((v) & 0x1UL) << SPI_I2SCFGR_CHLEN_Pos)

#define SPI_I2SCFGR_CHLEN_16B			(0UL)	/*!< 16-bit wide. */
#define SPI_I2SCFGR_CHLEN_32B			(1UL)	/*!< 32-bit wide. */

/* ----------------------------------------------- */
/* ------------------ DATLEN ---------------------- */
/**
 * @def 	SPI_I2SCFGR_DATLEN
 * @brief 	Data length to be transferred
 * @link 	@SPI_I2SCFGR_DATLEN
 * @note	For correct operation, these bits should be configured when the I2S is disabled.
 *			This bit is not used in SPI mode..
 *  */
#define SPI_I2SCFGR_DATLEN_Pos  		(1u)
#define SPI_I2SCFGR_DATLEN_Msk		   	(0x03UL << SPI_I2SCFGR_DATLEN_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_DATLEN_Val(v) 		(((v) & 0x3UL) << SPI_I2SCFGR_DATLEN_Pos)

#define SPI_I2SCFGR_DATLEN_16B			(0UL)	/*!< 16-bit data length. */
#define SPI_I2SCFGR_DATLEN_24B			(1UL)	/*!< 24-bit data length. */
#define SPI_I2SCFGR_DATLEN_32B			(2UL)	/*!< 32-bit data length. */

/* ----------------------------------------------- */
/* ------------------ CKPOL ---------------------- */
/**
 * @def 	SPI_I2SCFGR_CKPOL
 * @brief 	Steady state clock polarity
 * @link 	@SPI_I2SCFGR_CKPOL
 * @note	For correct operation, this bit should be configured when the I2S is disabled.
 *			This bit is not used in SPI mode.
 *  */
#define SPI_I2SCFGR_CKPOL_Pos  			(3u)
#define SPI_I2SCFGR_CKPOL_Msk		   	(0x03UL << SPI_I2SCFGR_CKPOL_Pos)	/*!< Length : 1 Bit */
#define SPI_I2SCFGR_CKPOL_Val(v) 		(((v) & 0x1UL) << SPI_I2SCFGR_CKPOL_Pos)

#define SPI_I2SCFGR_CKPOL_LOW			(0UL)	/*!< I2S clock steady state is low level. */
#define SPI_I2SCFGR_CKPOL_HIGH			(1UL)	/*!< I2S clock steady state is high level. */

/* ----------------------------------------------- */
/* ------------------ I2SSTD ---------------------- */
/**
 * @def 	SPI_I2SCFGR_I2SSTD
 * @brief 	I2S standard selection
 * @link 	@SPI_I2SCFGR_I2SSTD
 * @note	For more details on I2S standards
 *			For correct operation, these bits should be configured when the I2S is disabled
 *  */
#define SPI_I2SCFGR_I2SSTD_Pos  		(4u)
#define SPI_I2SCFGR_I2SSTD_Msk		   	(0x03UL << SPI_I2SCFGR_I2SSTD_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_I2SSTD_Val(v) 		(((v) & 0x3UL) << SPI_I2SCFGR_I2SSTD_Pos)

#define SPI_I2SCFGR_I2SSTD_PHILP		(0UL)	/*!< I2S Philips standard. */
#define SPI_I2SCFGR_I2SSTD_LEFT			(1UL)	/*!< MSB justified standard (left justified). */
#define SPI_I2SCFGR_I2SSTD_RIGTH		(2UL)	/*!< LSB justified standard (right justified). */
#define SPI_I2SCFGR_I2SSTD_PCM			(3UL)	/*!< PCM standard. */

/* ----------------------------------------------- */
/* ------------------ PCMSYNC ---------------------- */
/**
 * @def 	SPI_I2SCFGR_PCMSYNC
 * @brief 	PCM frame synchronization
 * @link 	@SPI_I2SCFGR_PCMSYNC
 * @note	This bit has a meaning only if I2SSTD = 11 (PCM standard is used)
 *			It is not used in SPI mode.
 *  */
#define SPI_I2SCFGR_PCMSYNC_Pos  		(7u)
#define SPI_I2SCFGR_PCMSYNC_Msk		   	(0x03UL << SPI_I2SCFGR_PCMSYNC_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_PCMSYNC_Val(v) 		(((v) & 0x1UL) << SPI_I2SCFGR_PCMSYNC_Pos)

#define SPI_I2SCFGR_PCMSYNC_PHILP		(0UL)	/*!< Short frame synchronization. */
#define SPI_I2SCFGR_PCMSYNC_LEFT		(1UL)	/*!< Short frame synchronization. */

/* ----------------------------------------------- */
/* ------------------ I2SCFG --------------------- */
/**
 * @def 	SPI_I2SCFGR_I2SCFG
 * @brief 	I2S configuration mode
 * @link 	@SPI_I2SCFGR_I2SCFG
 * @note	This bit should be configured when the I2S is disabled.
 *			It is not used in SPI mode.
 *  */
#define SPI_I2SCFGR_I2SCFG_Pos  		(8u)
#define SPI_I2SCFGR_I2SCFG_Msk		   	(0x03UL << SPI_I2SCFGR_I2SCFG_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_I2SCFG_Val(v) 		(((v) & 0x3UL) << SPI_I2SCFGR_I2SCFG_Pos)

#define SPI_I2SCFGR_I2SCFG_STX			(0UL)	/*!< Slave - transmit. */
#define SPI_I2SCFGR_I2SCFG_SRX			(1UL)	/*!< Slave - receive. */
#define SPI_I2SCFGR_I2SCFG_MTX			(2UL)	/*!< Master - transmit. */
#define SPI_I2SCFGR_I2SCFG_MRX			(3UL)	/*!< Master - receive. */

/* ----------------------------------------------- */
/* ------------------ I2SE ----------------------- */
/**
 * @def 	SPI_I2SCFGR_I2SE
 * @brief 	I2S Enable
 * @link 	@SPI_I2SCFGR_I2SE
 * @note	This bit is not used in SPI mode.
 *  */
#define SPI_I2SCFGR_I2SE_Pos  			(10u)
#define SPI_I2SCFGR_I2SE_Msk		   	(0x03UL << SPI_I2SCFGR_I2SE_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_I2SE_Val(v) 		(((v) & 0x1UL) << SPI_I2SCFGR_I2SE_Pos)

#define SPI_I2SCFGR_I2SE_DIS			(0UL)	/*!< I2S peripheral is disabled. */
#define SPI_I2SCFGR_I2SE_EN				(1UL)	/*!< I2S peripheral is enabled. */

/* ----------------------------------------------- */
/* ------------------ I2SMOD --------------------- */
/**
 * @def 	SPI_I2SCFGR_I2SMOD
 * @brief 	I2S mode selection
 * @link 	@SPI_I2SCFGR_I2SMOD
 * @note	This bit should be configured when the SPI or I2S is disabled.
 *  */
#define SPI_I2SCFGR_I2SMOD_Pos  		(11u)
#define SPI_I2SCFGR_I2SMOD_Msk		   	(0x03UL << SPI_I2SCFGR_I2SMOD_Pos)	/*!< Length : 2 Bit */
#define SPI_I2SCFGR_I2SMOD_Val(v) 		(((v) & 0x1UL) << SPI_I2SCFGR_I2SMOD_Pos)

#define SPI_I2SCFGR_I2SMOD_SPI			(0UL)	/*!< SPI mode is selected. */
#define SPI_I2SCFGR_I2SMOD_I2S			(1UL)	/*!< I2S mode is selected. */


/* --------------------------------------------------------------------------------------------------------- */
/* ------------------------------------------- I2SPR BITS -------------------------------------------------- */
/**
 * @def 	SPI_I2S prescaler register
 * @brief
 * @link  	@SPI_I2SPR
 */
/* ----------------------------------------------- */
/* ------------------ I2SDIV --------------------- */
/**
 * @def 	SPI_I2SPR_I2SDIV
 * @brief 	Odd factor for the prescaler
 * @link 	@SPI_I2SPR_I2SDIV
 * @note	These bits should be configured when the I2S is disabled. It is used only when the I2S is in master mode.
 *  */
#define SPI_I2SPR_I2SDIV_Pos  			(0u)
#define SPI_I2SPR_I2SDIV_Msk		   	(0xFFUL << SPI_I2SPR_I2SDIV_Pos)	/*!< Length : 8 Bit */
#define SPI_I2SPR_I2SDIV_Val(v) 		(((v) & 0xFFUL) << SPI_I2SPR_I2SDIV_Pos)

/* ----------------------------------------------- */
/* ------------------ ODD ------------------------ */
/**
 * @def 	SPI_I2SPR_ODD
 * @brief 	Odd factor for the prescaler
 * @link 	@SPI_I2SPR_ODD
 * @note	This bit should be configured when the I2S is disabled. It is used only when the I2S is in master mode.
 * 			Not used in SPI mode
 *
 * 			I2SDIV [7:0] = 0 or I2SDIV [7:0] = 1 are forbidden values.
 *  */
#define SPI_I2SPR_ODD_Pos  				(8u)
#define SPI_I2SPR_ODD_Msk		   		(0x01UL << SPI_I2SPR_ODD_Pos)	/*!< Length : 1 Bit */
#define SPI_I2SPR_ODD_Val(v) 			(((v) & 0x1UL) << SPI_I2SPR_ODD_Pos)

#define SPI_I2SPR_ODD_DIV2				(0UL)	/*!< real divider value is = I2SDIV *2. */
#define SPI_I2SPR_ODD_DIV2P1			(1UL)	/*!< real divider value is = (I2SDIV * 2)+1. */

/* ----------------------------------------------- */
/* ------------------ MCKOE ---------------------- */
/**
 * @def 	SPI_I2SPR_MCKOE
 * @brief 	Master clock output enable
 * @link 	@SPI_I2SPR_MCKOE
 * @note	This bit should be configured when the I2S is disabled. It is used only when the I2S is in master mode.
 *			This bit is not used in SPI mode.
 *  */
#define SPI_I2SPR_MCKOE_Pos  			(9u)
#define SPI_I2SPR_MCKOE_Msk		   		(0x01UL << SPI_I2SPR_MCKOE_Pos)	/*!< Length : 1 Bit */
#define SPI_I2SPR_MCKOE_Val(v) 			(((v) & 0x1UL) << SPI_I2SPR_MCKOE_Pos)

#define SPI_I2SPR_MCKOE_DIS				(0UL)	/*!< Master clock output is disabled. */
#define SPI_I2SPR_MCKOE_EN				(1UL)	/*!< Master clock output is enabled. */


#endif /* DRIVER_MCU_SPI_INC_SPI_SPI_REG_H_ */
