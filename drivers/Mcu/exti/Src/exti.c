/*
 * exti.c
 *
 *  Created on: Jan 3, 2026
 *      Author: smlby
 */

/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */


#include <exti.h>
#include <exti_cfg.h>
#include <exti_dev.h>
#include <exti_irq.h>
#include <exti_private_types.h>
/* ========================================================================================================= */
/* -------------------------------------- Macro Definition  ------------------------------------------------ */

/* ========================================================================================================= */
/* -------------------------------------- Global Variable Definition  -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Local Variable Definition  --------------------------------------- */

static EXTI_ChannelRuntimeType Exti_RunTime [EXTI_CHANNEL_COUNT];
uint8_t Exti_LineToChannel[EXTI_HW_LINE_COUNT];

/* ========================================================================================================= */
/* -------------------------------------- Static Function Definitions -------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Inline Definition  ----------------------------------------------- */

/* ========================================================================================================= */
/* -------------------------------------- Static Function Implementation ----------------------------------- */
static void EXTI_InitLineMap(void)
{
    for (uint8_t i = 0 ; i < EXTI_HW_LINE_COUNT ; i++)
    {
        Exti_LineToChannel[i] = EXTI_INVALID_CHANNEL;
    }
}
/* ========================================================================================================= */
/* -------------------------------------- API Implementation ----------------------------------------------- */


Std_ReturnType EXTI_Init(EXTI_HandleType *hexti)
{
	 int i;

	 Std_ReturnType retVal = E_NOT_OK;

	 EXTI_LineType line;

	 if ((NULL == hexti) | (NULL == hexti->config) )
	 {
		 retVal = E_NOT_OK;
	 }
	 else
	 {
		 EXTI_ChannelConfigType *cfg = hexti->config;

		 if(STD_NOTINITIATED == hexti->isInitiated)
		 {
			 EXTI_InitLineMap();

			 for(i = 0 ; i < EXTI_CHANNEL_COUNT ; i++)
			 {
				 line = EXTI_DEV_MapSourceToLine(&cfg[i].source);
				 Exti_RunTime[i].line 		= line;
				 Exti_RunTime[i].edge 		= cfg[i].edge;
				 Exti_RunTime[i].callback 	= cfg[i].callback;
				 Exti_RunTime[i].enabled 	= STD_FALSE;

				 Exti_LineToChannel[line] = i;

				 EXTI_DEV_ConfigureRouting(&cfg[i].source, line);

				 Exti_LL_SetEDGE(line, cfg[i].edge);
				 Exti_LL_ClearFlag(line);
			 }

			hexti->isInitiated = STD_INITIATED;
			retVal =  E_OK;
		 }
		 else
		 {
			 /*Already Initiated*/
		 }
	 }
	 return retVal;
}


Std_ReturnType EXTI_Enable(EXTI_ChannelIDType channel)
{
	Std_ReturnType retVal = E_NOT_OK;

    EXTI_LineType line = Exti_RunTime[channel].line;

    Exti_LL_ConfIMR(line, STD_ENABLE);

	retVal = E_OK;

	Exti_RunTime[channel].enabled = STD_ENABLE;

	return retVal;
}

Std_ReturnType EXTI_Disable(EXTI_ChannelIDType channel)
{
	Std_ReturnType retVal = E_NOT_OK;

    EXTI_LineType line = Exti_RunTime[channel].line;

    Exti_LL_ConfIMR(line, STD_DISABLE);

    Exti_RunTime[channel].enabled = STD_DISABLE;

	retVal = E_OK;

	return retVal;
}

Std_ReturnType EXTI_SetEdge(EXTI_LineType line, EXTI_EdgeType edge)
{
	Std_ReturnType retVal = E_NOT_OK;


	return retVal;
}


void EXTI_IrqDispatchLine(EXTI_LineType line)
{
    uint8_t ch = Exti_LineToChannel[line];

    if (ch != EXTI_INVALID_CHANNEL)
    {
        if (Exti_RunTime[ch].enabled)
        {
            if (Exti_RunTime[ch].callback != NULL)
            {
                Exti_RunTime[ch].callback();
            }
        }
    }

    Exti_LL_ClearFlag(line);
}
