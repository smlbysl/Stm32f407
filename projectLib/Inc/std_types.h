/*
 * Std_Types.h
 *
 *  Created on: Dec 29, 2025
 *      Author: smlby
 */

#ifndef PROJECT_INC_STD_TYPES_H_
#define PROJECT_INC_STD_TYPES_H_
/* ========================================================================================================= */
/* -------------------------------------- Include  --------------------------------------------------------- */
#include "stdint.h"
/* ========================================================================================================= */
/* -------------------------------------- Macro Definitions ------------------------------------------------ */
#define STD_DISABLE				0u
#define STD_ENABLE				1u


#define STD_RESET				STD_DISABLE
#define STD_SET					STD_ENABLE

#define STD_NOTINITIATED		0U
#define STD_INITIATED			1U

#define E_NOT_OK				0u
#define E_OK					1u

#define STD_FALSE				0u
#define STD_TRUE				1u


/* ========================================================================================================= */
/* -------------------------------------- Type Definitions ------------------------------------------------- */

typedef uint8_t Std_boolean;

typedef uint8_t Std_ReturnType;

#endif /* PROJECT_INC_STD_TYPES_H_ */
