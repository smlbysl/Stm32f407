/*
 * spi_ll.h
 *
 *  Created on: Jan 7, 2026
 *      Author: smlby
 */

#ifndef MCU_SPI_INC_SPI_SPI_LL_H_
#define MCU_SPI_INC_SPI_SPI_LL_H_



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include <spi_hw.h>
#include <spi_private_types.h>

/* ========================================================================================================= */
/* -------------------------------------- Macro Definition ------------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Variable Definition ---------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Functions -------------------------------------------------------- */
static inline void SPI_LL_MasterConf(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~(		SPI_CR1_BIDIMODE_Msk |
								SPI_CR1_RXONLY_Msk   |
								SPI_CR1_MSTR_Msk     |
								SPI_CR1_SSI_Msk      |
								SPI_CR1_SSM_Msk)) |
								SPI_CR1_BIDIMODE_Val(SPI_CR1_BIDIMODE_UNDI) |
								SPI_CR1_RXONLY_Val(SPI_CR1_RXONLY_FullDub)   |
								SPI_CR1_MSTR_Val(SPI_CR1_MSTR_MASTER)        |
								SPI_CR1_SSI_Val(SPI_CR1_SSI_HIGH)           |
								SPI_CR1_SSM_Val(SPI_CR1_SSM_EN);

	p->CR2 = (p->CR2 & ~SPI_CR2_SSOE_Msk) | SPI_CR2_SSOE_Val(SPI_CR1_SSOE_DIS) ;
}

/**
 * @brief BIDIMODE Selection
 *
 */

static inline void SPI_LL_DirModeUNI(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_BIDIMODE_Msk) | SPI_CR1_BIDIMODE_Val(SPI_CR1_BIDIMODE_UNDI);
}
static inline void SPI_LL_DirModeBI(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_BIDIMODE_Msk) | SPI_CR1_BIDIMODE_Val(SPI_CR1_BIDIMODE_BIDI);
}

/**
 * @brief CRC Enable and Disable
 *
 */
static inline void SPI_LL_CrcEn(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_CRCEN_Msk) | SPI_CR1_CRCEN_Val(SPI_CR1_CRCEN_EN);
}
static inline void SPI_LL_CrcDis(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_CRCEN_Msk) | SPI_CR1_CRCEN_Val(SPI_CR1_CRCEN_DIS);
}

/**
 * @brief Disable or Enable output(Full Dublex or Rx Only)
 *
 * @param p
 */
static inline void SPI_LL_FullDub(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_RXONLY_Msk) | SPI_CR1_RXONLY_Val(SPI_CR1_RXONLY_FullDub);
}
static inline void SPI_LL_DisOut(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_RXONLY_Msk) | SPI_CR1_RXONLY_Val(SPI_CR1_RXONLY_OUTDIS);
}

/**
 * @brief Enable Disable Peripheral
 *
 * @param p
 */
static inline void SPI_LL_PeripEn(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_SPE_Msk) | SPI_CR1_SPE_Val(SPI_CR1_SPE_EN);
}
static inline void SPI_LL_PeripDis(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_SPE_Msk) | SPI_CR1_SPE_Val(SPI_CR1_SPE_DIS);
}

/**
 * @brief Rol Selection
 *
 * @param p
 */
static inline void SPI_LL_ConfMaster(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_MSTR_Msk) | SPI_CR1_MSTR_Val(SPI_CR1_MSTR_MASTER);
}
static inline void SPI_LL_ConfSlave(Spi_Hw_RegType *p)
{
	p->CR1 = (p->CR1 & ~SPI_CR1_MSTR_Msk) | SPI_CR1_MSTR_Val(SPI_CR1_MSTR_SLAVE);
}

/**
 * @fn void SPI_LL_WriteTx(Spi_Hw_RegType*)
 * @brief
 *
 * @param p
 */

static inline void SPI_LL_WriteDR_8Bit(Spi_Hw_RegType *p,uint8_t DataBuffer)
{
	p->DR = SPI_DR_DR_WRITE_8B(DataBuffer);
}

static inline void SPI_LL_WriteDR_16Bit(Spi_Hw_RegType *p,uint16_t DataBuffer)
{
	p->DR = SPI_DR_DR_WRITE_16B(DataBuffer);
}

static inline void SPI_LL_ReadDR_8Bit(Spi_Hw_RegType *p,uint16_t *DataBuffer)
{
	*DataBuffer = (uint8_t)(p->DR & SPI_DR_DR_Msk);
}

static inline void SPI_LL_ReadDR_16Bit(Spi_Hw_RegType *p,uint16_t *DataBuffer)
{
	*DataBuffer = p->DR & SPI_DR_DR_Msk;
}
/**
 * @brief Check the RXNE flag
 *
 * @param p
 * @return TRUE if buffer not empty
 */
static inline void SPI_LL_RxBufferCheck(Spi_Hw_RegType *p, Std_boolean *DataBuffer)
{
	*DataBuffer = ((p->SR & SPI_SR_RXNE_Msk) != SPI_SR_RXNE_EMTY) ? STD_TRUE: STD_FALSE;
}

/**
 * @fn Std_boolean SPI_LL_RxBufferCheck(Spi_Hw_RegType*)
 * @brief
 *
 * @param p
 * @return
 */
static inline void SPI_LL_TxBufEmty(Spi_Hw_RegType *p,Std_boolean *DataBuffer)
{
	*DataBuffer = ((p->SR & SPI_SR_TXE_Msk) != SPI_SR_TXE_NOTEMTY) ? STD_FALSE: STD_TRUE;
}


static inline Std_boolean SPI_LL_IsBusy(Spi_Hw_RegType *p)
{
	return ((p->SR & SPI_SR_BSY_Msk) != SPI_SR_BSY_NOTBUSY) ? STD_TRUE: STD_FALSE;
}

/* --------------------------------------------------------------------------------------------------------- */
/* -------------------------------------- External Device -------------------------------------------------- */

static inline void SPI_LL_SetDff(Spi_Hw_RegType *p, Spi_DataFFType val)
{
	if (SPI_DATAFF_8BIT != val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_DFF_Msk) | SPI_CR1_DFF_Val(SPI_CR1_DFF_16Bit);
	}
	else
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_DFF_Msk) | SPI_CR1_DFF_Val(SPI_CR1_DFF_8Bit);
	}
}
static inline void SPI_LL_SetFrameFormat(Spi_Hw_RegType *p, Spi_FrameFormatType val)
{
	if (SPI_FF_MSB != val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_LSBFIRST_Msk) | SPI_CR1_LSBFIRST_Val(SPI_CR1_LSBFIRST_FIRSTLSB);
	}
	else
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_LSBFIRST_Msk) | SPI_CR1_LSBFIRST_Val(SPI_CR1_LSBFIRST_FIRSTMSB);
	}
}

static inline void SPI_LL_SetCpha(Spi_Hw_RegType *p, Spi_ClockPhaseType val)
{
	if (SPI_FIRSTDATA != val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_CPHA_Msk) | SPI_CR1_CPHA_Val(SPI_CR1_CPHA_CAPTSECOND);
	}
	else
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_CPHA_Msk) | SPI_CR1_CPHA_Val(SPI_CR1_CPHA_CAPTFIRST);
	}
}
static inline void SPI_LL_SetCpol(Spi_Hw_RegType *p, Spi_ClockPolType val)
{
	if (SPI_CLK_0 != val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_CPOL_Msk) | SPI_CR1_CPOL_Val(SPI_CR1_CPOL_CK1);
	}
	else
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_CPOL_Msk) | SPI_CR1_CPOL_Val(SPI_CR1_CPOL_CK0);
	}
}

static inline void SPI_LL_SetProtocol(Spi_Hw_RegType *p, Spi_ProtocolType val)
{
	if (SPI_MOTOROLA != val)
	{
		p->CR2 = (p->CR2 & ~SPI_CR2_FRF_Msk) | SPI_CR2_FRF_Val(SPI_CR1_FRF_TI);
	}
	else
	{
		p->CR2 = (p->CR2 & ~SPI_CR2_FRF_Msk) | SPI_CR2_FRF_Val(SPI_CR1_FRF_MOT);
	}
}

static inline void SPI_LL_SetBoundRate(Spi_Hw_RegType *p, Spi_BoundRateType val)
{
	if (SPI_BOUNDRATE_2 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV2);
	}
	else if(SPI_BOUNDRATE_4 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV4);
	}
	else if(SPI_BOUNDRATE_8 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV8);
	}
	else if(SPI_BOUNDRATE_16 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV16);
	}
	else if(SPI_BOUNDRATE_32 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV32);
	}
	else if(SPI_BOUNDRATE_64 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV64);
	}
	else if(SPI_BOUNDRATE_128 == val)
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV128);
	}
	else
	{
		p->CR1 = (p->CR1 & ~SPI_CR1_BR_Msk) | SPI_CR1_BR_Val(SPI_CR1_BR_DIV256);
	}
}

#endif /* MCU_SPI_INC_SPI_SPI_LL_H_ */
