#ifndef NODE_CONVERT_HAL_STATUS_H
#define NODE_CONVERT_HAL_STATUS_H

#include "stm32f3xx_hal.h"

/*

typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03
} HAL_StatusTypeDef;

*/

// Helper to convert from HAL_StatusTypeDef retval to bool
// true = success/all good and false = error
bool halStatusToBool(HAL_StatusTypeDef status);

#endif