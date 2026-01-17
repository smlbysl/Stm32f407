/*
 * spi_hwUnit.c
 *
 *  Created on: Jan 14, 2026
 *      Author: smlby
 */





/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "spi_private.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */
Spi_HwUnitRuntimeType hwRnt[SPI_HWID_MAX];

Spi_HwUnitIdType HwIdMap[SPI_HWID_MAX] =
{
		SPI_SPI1
};

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */
static void Spi_HwUnit_SetExDev(Spi_HwUnitIdType hwId, Spi_ExDevIdType exDevId);
static Std_ReturnType Spi_HwConfigHandler(const Spi_ControllerConfigType * cfg);
static Std_ReturnType Spi_HwUnit_ExDev_Init(const Spi_ExternalDeviceConfigType* exDevCfg);
/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void Spi_HwUnit_SetExDev(Spi_HwUnitIdType hwId, Spi_ExDevIdType exDevId)
{
	const Spi_ExternalDeviceConfigType	*exDevCfg	= &CfgPtr->externalDeviceConfig[exDevId];
	Spi_Hw_RegType						*hwBase		= CfgPtr->controllerConfig[hwId].base;

	SPI_LL_SetDff(hwBase, exDevCfg->frame->dataWidth);
	SPI_LL_SetFrameFormat(hwBase, exDevCfg->frame->bitOrder);
	SPI_LL_SetCpha(hwBase, exDevCfg->frame->cpha);
	SPI_LL_SetCpol(hwBase, exDevCfg->frame->cpol);
	SPI_LL_SetProtocol(hwBase, exDevCfg->frame->protocol);
	SPI_LL_SetBoundRate(hwBase, exDevCfg->targetBaudrate);
}

static Std_ReturnType Spi_HwConfigHandler(const Spi_ControllerConfigType * cfg)
{
	Std_ReturnType retVal = E_NOT_OK;
	uint8_t i;
	const Spi_ControllerConfigType *pCfg;

	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{

		pCfg = &cfg[i];

		if(SPI_HW_UNINIT == hwRnt[i].hwStatus)
		{

			/* Disable Peripheral */
			SPI_LL_PeripDis(pCfg->base);
			/*2 Rol check*/
			switch(pCfg->role)
			{
			case SPI_MASTER:
				/*2.a Configure unidrectional as default for Master Role*/
				SPI_LL_MasterConf(pCfg->base);
				break;
			case SPI_SLAVE:
				break;
			default:
			}

			if(SPI_ENABLE == pCfg->crcCapable)
			{
				SPI_LL_CrcEn(pCfg->base);
			}
			else
			{
				SPI_LL_CrcDis(pCfg->base);
			}

			hwRnt[i].hwStatus = SPI_HW_IDLE;

			retVal = E_OK;
		}
		else
		{
			retVal = E_NOT_OK;
			break;
		}
	}
	return retVal;
}


static Std_ReturnType Spi_HwUnit_ExDev_Init(const Spi_ExternalDeviceConfigType* exDevCfg)
{
	uint8_t i;
	Std_ReturnType retVal = E_NOT_OK;

	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		hwRnt[i].exDevId = SPI_EXDEVID_UNDEFINED;
	}

	retVal = E_OK;

	return retVal;
}

static void Spi_HwUnit_Rnt_Init(const Spi_ControllerConfigType * cfg)
{
	uint8_t i;

	for(i = 0 ; i < SPI_HWID_MAX ; i++)
	{
		hwRnt[i].exDevId = SPI_EXDEVID_UNDEFINED;
		hwRnt[i].hwStatus = SPI_HW_UNINIT;
		hwRnt[i].hwUnitId = cfg[i].id;
	}
}
/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */

void Spi_HwUnit_Init(const Spi_ConfigType* ConfigPtr)
{
	Std_ReturnType retVal;

	Spi_HwUnit_Rnt_Init((const Spi_ControllerConfigType * )ConfigPtr->controllerConfig);

	retVal = Spi_HwConfigHandler((const Spi_ControllerConfigType * )ConfigPtr->controllerConfig);

	if(E_OK == retVal)
	{
		CfgPtr = ConfigPtr;
	}
	else
	{
		/* Controller Config Error */
	}

	retVal = Spi_HwUnit_ExDev_Init((const Spi_ExternalDeviceConfigType * )ConfigPtr->externalDeviceConfig);
}


Std_ReturnType Spi_HwUnit_SwitchExDev(Spi_HwUnitIdType hwId, Spi_ExDevIdType exDevId)
{
	Std_ReturnType 	retVal		= E_NOT_OK;
	Spi_Hw_RegType	*hwBase		= CfgPtr->controllerConfig[hwId].base;

	/*State for HwUnit*/
	if ((SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus ) &&
		(STD_FALSE == SPI_LL_IsBusy(hwBase)))
	{
		/* Disable External Device*/
		SPI_LL_PeripDis(hwBase);

		Rnt.controllerRnt[hwId].activeContStatus = SPI_BUSY;


		/*Try to Change Device */
		Spi_HwUnit_SetExDev(hwId, exDevId);

		Rnt.controllerRnt[hwId].activeContStatus = SPI_IDLE;
		/*Enable Device */
		SPI_LL_PeripEn(hwBase);
		retVal		= E_OK;
	}
	else if (SPI_UNINIT == Rnt.controllerRnt[hwId].activeContStatus)
	{
		/* Error Initiate First */
	}
	else
	{
		/* Do Nothing*/
	}

	return retVal;
}


Std_ReturnType Spi_JobHandler_ConfTransferMode(Spi_HwUnitIdType hwId, Spi_TransferModeType tmode)
{
	Std_ReturnType 	retVal		= E_NOT_OK;
	Spi_Hw_RegType	*hwBase		= CfgPtr->controllerConfig[hwId].base;

	/*State for HwUnit*/
	if ((SPI_IDLE == Rnt.controllerRnt[hwId].activeContStatus ) &&
		(STD_FALSE == SPI_LL_IsBusy(hwBase)))
	{
		Rnt.controllerRnt[hwId].activeContStatus = SPI_BUSY;
		/* Disable External Device*/
		SPI_LL_PeripDis(hwBase);

		if(SPI_TRANSFER_INTERRUPT == tmode)
		{
			SPI_LL_RxNotEmtyIntEn(hwBase);
			SPI_LL_TxEmtyIntEn(hwBase);
		}
		else
		{
			SPI_LL_RxNotEmtyIntDis(hwBase);
			SPI_LL_TxEmtyIntDis(hwBase);
		}

		/*Enable Device */
		SPI_LL_PeripEn(hwBase);

		Rnt.controllerRnt[hwId].activeContStatus = SPI_IDLE;

		retVal		= E_OK;
	}
	else if (SPI_UNINIT == Rnt.controllerRnt[hwId].activeContStatus)
	{
		/* Error Initiate First */
	}
	else
	{
		/* Do Nothing*/
	}

	return retVal;
}


