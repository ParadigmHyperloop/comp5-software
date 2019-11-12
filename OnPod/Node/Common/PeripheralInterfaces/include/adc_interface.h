#include "stm32f3xx_hal.h"
#include "stdint.h"

class ADCInterface
{
public:
    ADCInterface(ADC_HandleTypeDef* hadc) : m_hadc(hadc);
   
    // Activate ADC
    HAL_StatusTypeDef adcStart();

    // Deactivate ADC
    HAL_StatusTypeDef adcStop();

    // Poll for conversion, will return HAL_OK if conversion is performed
    HAL_StatusTypeDef pollForConversion(uint32_t timeout);

    // Returns the value of the conversion. To be called after polling returns.
    uint32_t getValue();

    // Returns the current ADC error state
    uint32_t getError();

    // Set the channel to be read 
    HAL_StatusTypeDef configChannel(ADC_ChannelConfTypeDef* config);

private:
    // Adc handle, possible values hadc1 - hadc3
    ADC_HandleTypeDef* m_hadc;
};