#ifndef NODE_SPIINTERFACE_H
#define NODE_SPIINTERFACE_H

#include "stm32f3xx_hal.h"

class SPIInterface
{
private:

    SPI_HandleTypeDef *m_hspi;
    uint8_t m_dataReceived[8];

public:

    // Constructor
    SPIInterface(SPI_HandleTypeDef *hspi);

    // Returns a pointer to the data recieved buffer
    uint8_t* getReceivedData() { return m_dataReceived; }

    // Get state, and error methods
    HAL_SPI_StateTypeDef getState() { return HAL_SPI_GetState(m_hspi); }
    uint32_t getError() { return HAL_SPI_GetError(m_hspi); }

    // Master transmit and receive functions
    HAL_StatusTypeDef Transmit(uint8_t* data, uint32_t timeout, uint8_t size);
    HAL_StatusTypeDef Receive(uint32_t timeout, uint8_t size);


    HAL_StatusTypeDef isDeviceReady(uint16_t devAddress, uint32_t trials, uint32_t timeout);

};
#endif