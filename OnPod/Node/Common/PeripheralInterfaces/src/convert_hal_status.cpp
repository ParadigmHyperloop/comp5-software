#include "convert_hal_status.h"

bool halStatusToBool(HAL_StatusTypeDef status)
{
    if (status == 0x00U) {
        return true;
    }
    return false;
}