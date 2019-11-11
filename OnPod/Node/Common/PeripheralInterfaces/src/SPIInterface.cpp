#include "SPIInterface.h"

SPIInterface::SPIInterface(SPI_HandleTypeDef *hspi) : m_hspi(hspi){}

HAL_StatusTypeDef SPIInterface::Transmit(uint16_t address, uint8_t* data, uint32_t timeout, uint8_t size)
{
    return HAL_SPI_Transmit(m_hspi, data, size, timeout);
}

HAL_StatusTypeDef SPIInterface::Receive(uint16_t address, uint32_t timeout)
{
    return HAL_SPI_Receive(m_hspi, m_dataReceived, m_bufferlength, timeout);
}