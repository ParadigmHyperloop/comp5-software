#include "SPIInterface.h"

SPIInterface::SPIInterface(SPI_HandleTypeDef *hspi) : m_hspi(hspi){}

HAL_StatusTypeDef SPIInterface::Transmit(uint8_t* data, uint32_t timeout, 
                                            uint8_t size)
{
    return HAL_SPI_Transmit(m_hspi, data, size, timeout);
}

HAL_StatusTypeDef SPIInterface::Receive(uint32_t timeout, uint16_t size)
{
    return HAL_SPI_Receive(m_hspi, m_dataReceived, size, timeout);
}

HAL_StatusTypeDef SPIInterface::TransmitReceive(uint8_t* dataIn, 
                                                uint32_t timeout, uint8_t size)
{
    return HAL_SPI_TransmitReceive(m_hspi, dataIn, m_dataReceived, size, 
                                    timeout);
}