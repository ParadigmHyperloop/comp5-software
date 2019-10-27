#include "I2CInterface.h"

// Constructor 
I2CInterface::I2CInterface(I2C_HandleTypeDef *hi2c)
{
    HAL_I2C_StateTypeDef state = HAL_I2C_GetState(hi2c);

    if(state==HAL_I2C_STATE_READY )
    {
        m_hi2c = hi2c;
    }
    else
    {
        getError();
    }
}

HAL_StatusTypeDef I2CInterface::masterTransmit(uint16_t devAddress, uint8_t *data, uint32_t timeout, uint8_t size)     
{ 
    return HAL_I2C_Master_Transmit(m_hi2c, devAddress<<1, data, size, timeout);  
} 

HAL_StatusTypeDef I2CInterface::masterRecieve(uint16_t devAddress, uint32_t timeout)
{
    return HAL_I2C_Master_Receive(m_hi2c, devAddress<<1, m_dataRecieved, m_dataBufferLength, timeout);
}

HAL_StatusTypeDef I2CInterface::memWrite(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize, uint8_t size, uint32_t timeout)
{
    return HAL_I2C_Mem_Write(m_hi2c, devAddress, memAddress, memAddressSize, data, size, timeout);
}

HAL_StatusTypeDef I2CInterface::memRead(uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize, uint32_t timeout)
{
    return HAL_I2C_Mem_Write(m_hi2c, devAddress, memAddress, memAddressSize, m_dataRecieved, m_dataBufferLength, timeout);
}

//Checks if target device is ready for communication
HAL_StatusTypeDef I2CInterface::isDeviceReady(uint16_t devAddress, uint32_t trials)
{
    return HAL_I2C_IsDeviceReady(m_hi2c, devAddress, trials, m_timeout );
}

//CONFIGURATION FUNCTIONS
/*  Configures analog noise filter - FilterState is the new state of 
    analog noise filter.

    #defines:
    I2C_ANALOGFILTER_ENABLE
    I2C_ANALOGFILTER_DISABLE
*/
HAL_StatusTypeDef I2CInterface::configAnalogFilter(uint32_t FilterState)
{
    return HAL_I2CEx_ConfigAnalogFilter(m_hi2c, FilterState);
}

/*  Configures digital noise filter - FilterState is the coefficient of 
    digital noise filter between 0x00 and 0x0F
*/
HAL_StatusTypeDef I2CInterface::configDigitalFilter(uint32_t FilterState)
{
    return HAL_I2CEx_ConfigDigitalFilter(m_hi2c, FilterState);
}