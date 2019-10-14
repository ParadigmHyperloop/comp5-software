#include "main.h"
#include "I2Cmanager.h"

extern "C" 
{
    void SystemClock_Config(void);
}

int main(void) 
{
    HAL_Init();
    SystemClock_Config();
}