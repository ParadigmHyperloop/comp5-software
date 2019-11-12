#include "adc_interface.h"

HAL_StatusTypeDef ADCInterface::adcStart()
{
   return  HAL_ADC_Start(m_hadc);
}

HAL_StatusTypeDef ADCInterface::adcStop()
{
    return HAL_ADC_Stop(m_hadc);
}

HAL_StatusTypeDef ADCInterface::pollForConversion(uint32_t timeout)
{
    return HAL_ADC_PollForConversion(m_hadc, timeout);
}

uint32_t ADCInterface::getValue()
{
    return HAL_ADC_GetValue(m_hadc);
}

uint32_t ADCInterface::getError()
{
    return HAL_ADC_GetError(m_hadc);
}

HAL_StatusTypeDef ADCInterface::configChannel(ADC_ChannelConfTypeDef* config)
{
    return HAL_ADC_ConfigChannel(m_hadc, config);
}
