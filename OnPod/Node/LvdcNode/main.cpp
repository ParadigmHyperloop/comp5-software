#include "main.h"

extern "C"
{
    void SystemClock_Config(void);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
}