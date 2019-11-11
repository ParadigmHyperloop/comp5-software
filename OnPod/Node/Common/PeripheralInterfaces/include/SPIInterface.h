#ifndef NODE_SPIINTERFACE_H
#define NODE_SPIINTERFACE_H

#include "stm32f3xx_hal.h"

class SPIInterface
{
private:

    SPI_HandleTypeDef *m_hspi;
    uint8_t m_dataReceived[8];
    uint8_t m_bufferlength = 8;

public:

    // Constructor
    SPIInterface(SPI_HandleTypeDef *hspi);

    // Returns a pointer to the data recieved buffer
    uint8_t* getReceivedData() { return m_dataReceived; }

    // Get state, and error methods
    HAL_SPI_StateTypeDef getState() { return HAL_SPI_GetState(m_hspi); }
    uint32_t getError() { return HAL_SPI_GetError(m_hspi); }

    // Master transmit and receive functions
    HAL_StatusTypeDef Transmit(uint16_t address, uint8_t* data, uint32_t timeout, uint8_t size);
    HAL_StatusTypeDef Receive(uint16_t address, uint32_t timeout);

    // Reading / Writing
    HAL_StatusTypeDef memWrite(uint8_t* data, uint16_t devAddress, uint16_t memAddress, 
                                uint16_t memAddressSize, uint8_t size, uint32_t timeout);

    HAL_StatusTypeDef memRead(uint16_t devAddress, uint16_t memAddress, 
                                uint16_t memAddressSize, uint32_t timeout);

    HAL_StatusTypeDef isDeviceReady(uint16_t devAddress, uint32_t trials = 100, uint32_t timeout);

};
#endif