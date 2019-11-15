#include "main.h"
#include "stm32f3xx_hal.h"

extern "C" 
{
    void SystemClock_Config(void);
}

int main(void) 
{
    HAL_Init();
    SystemClock_Config();



}