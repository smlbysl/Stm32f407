/*
 * spi_channel.c
 *
 *  Created on: Jan 14, 2026
 *      Author: smlby
 */



/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */
#define SPI_DUMMY_BUFFER_16			((uint16_t)0xFFFF)
#define SPI_DUMMY_BUFFER_8			((uint8_t)0xFF)
/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_ChannelRuntimeType		channelRnt[SPI_CHANNEL_MAX];
/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */
static uint16_t Spi_IB_Tx[SPI_CHANNEL_MAX][SPI_CHANNELLENGTH_MAX];
static uint16_t Spi_IB_Rx[SPI_CHANNEL_MAX][SPI_CHANNELLENGTH_MAX];
/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void Spi_Channel_RntInit(void)
{
	uint8_t i,j;
	for(i = 0 ; i < SPI_CHANNEL_MAX ; i++)
	{
		channelRnt[i].status 	= SPI_CHANNEL_OK;
		channelRnt[i].rxIndex	= 0;
		channelRnt[i].txIndex	= 0;
		channelRnt[i].rxPtr		= &Spi_IB_Rx[i][0];
		channelRnt[i].txPtr		= &Spi_IB_Tx[i][0];

		for (j = 0 ; j < SPI_CHANNELLENGTH_MAX ; j++)
		{
			Spi_IB_Rx[i][j] = 0;
			Spi_IB_Tx[i][j] = 0;
		}
	}
}

/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_Channel_Init(void)
{
	Spi_Channel_RntInit();
}

Std_ReturnType Spi_ChannelHandler_StartAsynch(Spi_HwUnitIdType hwId, Spi_ChannelIdType chId)
{
	Std_ReturnType 			retVal	= E_NOT_OK;
	Spi_Hw_RegType			*hwBase	= CfgPtr->controllerConfig[hwId].base;
	Spi_ChannelRuntimeType	*chRt	= &channelRnt[chId];

	if ((SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus) &&
		(STD_FALSE == SPI_LL_IsBusy(hwBase)))
	{
		Rnt.controllerRnt[hwId].activeContStatus 	= SPI_BUSY;
		Rnt.controllerRnt[hwId].activeChannelId 	= chId;

		chRt->txIndex = 0;
		chRt->rxIndex = 0;

		chRt->txPtr = &Spi_IB_Tx[chId][0];
		chRt->rxPtr = &Spi_IB_Rx[chId][0];

		SPI_LL_PeripDis(hwBase);

		switch (CfgPtr->channelConfig[chId].dir)
		{

		case SPI_CH_TX:

			SPI_LL_TxEmtyIntEn(hwBase);
			SPI_LL_PeripEn(hwBase);
			break;

		case SPI_CH_RX:

			SPI_LL_RxNotEmtyIntEn(hwBase);
			SPI_LL_PeripEn(hwBase);
	    	break;

		case SPI_CH_TXRX:

			SPI_LL_TxEmtyIntEn(hwBase);
			SPI_LL_RxNotEmtyIntEn(hwBase);
			SPI_LL_PeripEn(hwBase);
			break;

		default:
		}
		retVal = E_OK;
	}
	return retVal;
}


Std_ReturnType Spi_Channel_WriteTxIBBuffer(Spi_ChannelIdType chId, const uint16_t *DataBuffer)
{
	Std_ReturnType 	retVal	= E_NOT_OK;
	const Spi_ChannelConfigType	*chCfg = &CfgPtr->channelConfig[chId];
	uint8_t i;

	if(SPI_CHANNEL_OK == channelRnt[chId].status)
	{
		if((NULL != channelRnt[chId].txPtr) ||
			(NULL != channelRnt[chId].rxPtr))
		{

		}
		else
		{
			channelRnt[chId].txPtr = &Spi_IB_Tx[chId][0];
			channelRnt[chId].rxPtr = &Spi_IB_Rx[chId][0];
		}

		for (i = 0 ; i < chCfg->length ; i++)
		{
			Spi_IB_Tx[chId][i] = DataBuffer[i];
		}
		retVal = E_OK;
	}
	else
	{
		/* Not Possible to Access */
		/* Return E_NOT_OK */
	}
	return retVal;
}


Std_ReturnType Spi_Channel_ReadRxIBBuffer(Spi_ChannelIdType chId, uint16_t *DataBuffer)
{
	Std_ReturnType 	retVal	= E_NOT_OK;
	const Spi_ChannelConfigType	*chCfg = &CfgPtr->channelConfig[chId];

	uint8_t i;
	if(SPI_CHANNEL_OK == channelRnt[chId].status)
	{
		if((NULL != channelRnt[chId].txPtr) ||
			(NULL != channelRnt[chId].rxPtr))
		{

		}
		else
		{
			channelRnt[chId].txPtr = &Spi_IB_Tx[chId][0];
			channelRnt[chId].rxPtr = &Spi_IB_Rx[chId][0];
		}

		for (i = 0 ; i < chCfg->length ; i++)
		{
			DataBuffer[i] = Spi_IB_Rx[chId][i];
		}
		retVal = E_OK;
	}
	else
	{
		/* Not Possible to Access */
		/* Return E_NOT_OK */
	}

	retVal = E_OK;
	return retVal;
}



void Spi_Channel_Callback(Spi_HwUnitIdType hwID)
{
	Spi_ChannelIdType 		acChId 	= Rnt.controllerRnt[hwID].activeChannelId;
	Spi_ChannelRuntimeType	*chRt	= &channelRnt[acChId];
	Spi_Hw_RegType			*hwBase	= CfgPtr->controllerConfig[hwID].base;
	const Spi_ChannelConfigType 	*chCfg 	= &CfgPtr->channelConfig[acChId];
	Spi_FrameConfigType		*frame	= CfgPtr->externalDeviceConfig[CfgPtr->jobConfig[Rnt.controllerRnt[hwID].activeJobId].exDeviceID].frame;

	Std_boolean DataBufferRXNE;
	Std_boolean DataBufferTXE;

	Std_boolean txDone;
	Std_boolean rxDone;

	SPI_LL_RxBufferCheck(hwBase, &DataBufferRXNE);
	SPI_LL_TxBufEmty(hwBase,&DataBufferTXE);

	switch (chCfg->dir)
	{
	case SPI_CH_TX:
	    if (DataBufferRXNE)
	    {
	    	uint16_t dummy;
	    	if(SPI_DATAFF_8BIT == frame->dataWidth)
	    	{
		    	SPI_LL_ReadDR_8Bit(hwBase, &dummy);
	    	}
	    	else
	    	{
		    	SPI_LL_ReadDR_16Bit(hwBase, &dummy);
	    	}
	    }

	    if ((DataBufferTXE) && (chRt->txIndex < chCfg->length))
		{
	    	if (SPI_DATAFF_8BIT == frame->dataWidth)
	    	{
	    		SPI_LL_WriteDR_8Bit(hwBase, ((uint8_t*)chRt->txPtr)[chRt->txIndex]);
	    	}
	    	else
	    	{
	    		SPI_LL_WriteDR_16Bit(hwBase, ((uint16_t*)chRt->txPtr)[chRt->txIndex]);
	    	}
	    	chRt->txIndex ++;
		}
	    break;

	case SPI_CH_RX:
	    if (DataBufferRXNE && chRt->rxIndex < chCfg->length)
	    {
	    	if(SPI_DATAFF_8BIT == frame->dataWidth)
	    	{
		    	SPI_LL_ReadDR_8Bit(hwBase, &chRt->rxPtr[chRt->rxIndex]);
	    	}
	    	else
	    	{
		    	SPI_LL_ReadDR_16Bit(hwBase, &chRt->rxPtr[chRt->rxIndex]);
	    	}
	    	chRt->rxIndex ++;

	    }
	    if ((DataBufferTXE) && (chRt->txIndex < chCfg->length))
	    {
	    	if(SPI_DATAFF_8BIT == frame->dataWidth)
	    	{
	    		SPI_LL_WriteDR_8Bit(hwBase, SPI_DUMMY_BUFFER_8);
	    	}
	    	else
	    	{
	    		SPI_LL_WriteDR_16Bit(hwBase, SPI_DUMMY_BUFFER_16);
	    	}

	    	chRt->txIndex ++;
	    }
	    break;

	case SPI_CH_TXRX:
	    if (DataBufferRXNE && chRt->rxIndex < chCfg->length)
	    {
	    	if(SPI_DATAFF_8BIT == frame->dataWidth)
	    	{
		    	SPI_LL_ReadDR_8Bit(hwBase, &chRt->rxPtr[chRt->rxIndex]);
	    	}
	    	else
	    	{
		    	SPI_LL_ReadDR_16Bit(hwBase, &chRt->rxPtr[chRt->rxIndex]);
	    	}
	    	chRt->rxIndex ++;
	    }

	    if ((DataBufferTXE) && (chRt->txIndex < chCfg->length))
	    {
	    	if (SPI_DATAFF_8BIT == frame->dataWidth)
			{
				SPI_LL_WriteDR_8Bit(hwBase, ((uint8_t*)chRt->txPtr)[chRt->txIndex]);
			}
			else
			{
				SPI_LL_WriteDR_16Bit(hwBase, ((uint16_t*)chRt->txPtr)[chRt->txIndex]);
			}
			chRt->txIndex ++;
	    }
	    break;
	};

	txDone = (chRt->txIndex >= chCfg->length) ? STD_TRUE : STD_FALSE;
	rxDone = (chCfg->dir == SPI_CH_TX) ? STD_TRUE : ((chRt->rxIndex >= chCfg->length) ? STD_TRUE : STD_FALSE);

	if ((txDone) &&
		(rxDone) &&
	    (STD_FALSE == SPI_LL_IsBusy(hwBase)))   // BSY == 0
	{
		SPI_LL_PeripDis(hwBase);
		SPI_LL_TxEmtyIntDis(hwBase);
		SPI_LL_RxNotEmtyIntDis(hwBase);
	    Rnt.channelRnt[hwID].status = SPI_CHANNEL_OK;
	    Rnt.controllerRnt[hwID].activeContStatus = SPI_IDLE;
	}

}
