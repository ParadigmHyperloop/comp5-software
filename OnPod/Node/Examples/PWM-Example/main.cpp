#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "PWMManager.h"

extern "C" 
{
    void SystemClock_Config(void);
}

int main(void) 
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_TIM2_Init();
    MX_TIM3_Init();
    PWMManager output(8000000, 8000, 200, 50, htim3, TIM_CHANNEL_2);
    output.PWMStart();
    while(1)
    {
        HAL_Delay(5000);
        output.setPeriodMs(100);
        HAL_Delay(5000);
        output.setPeriodMs(200);
        output.setDutyCyclePercent(50);
    }
}