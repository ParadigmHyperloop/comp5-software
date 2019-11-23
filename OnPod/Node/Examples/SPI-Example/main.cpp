#include "main.h"
#include "gpio.h"
#include "spi.h"
#include "SPIInterface.h"
#include "stm32f3xx_hal.h"

extern "C" 
{
    void SystemClock_Config(void);
}

int main(void) 
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    HAL_SPI_Init(&hspi3);

    SPIInterface spi(&hspi3);
    uint8_t data = 0x99;

    while(1)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
        spi.Transmit((uint8_t *) data, sizeof(data), HAL_MAX_DELAY);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);
        HAL_Delay(1000);
    }

    
    




}