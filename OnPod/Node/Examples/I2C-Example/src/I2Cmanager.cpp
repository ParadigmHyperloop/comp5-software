#include"main.h"
#include "I2CManager.h"

// Constructor
I2C::I2C(I2C_HandleTypeDef hi2c)
{
    setHandleTypeDef(hi2c);
}

//setter for I2C HandleTypeDef structure
void I2C::setHandleTypeDef(I2C_HandleTypeDef hi2c)
{
    m_hi2c = hi2c;
}

//getter for I2C HandleTypeDef
I2C_HandleTypeDef I2C::getHandleTypeDef()
{
    return m_hi2c;
}

// setter for I2C addressing mode 
void I2C::setAddressingMode(uint32_t mode)
{
    m_hi2c.Init.AddressingMode = mode;
}

//getter for I2C addressing mode
uint32_t I2C::getAddressingMode()
{
    return m_hi2c.Init.AddressingMode;
}

//getter for I2C state
HAL_I2C_StateTypeDef I2C::getState()
{
    return(HAL_I2C_GetState(&m_hi2c));
}

//getter for I2C mode
HAL_I2C_ModeTypeDef I2C::getMode()
{
    return(HAL_I2C_GetMode(&m_hi2c));
}

//getter for I2C error code
uint32_t I2C::getError()
{
    return(HAL_I2C_GetError(&m_hi2c));
}

uint8_t* I2C::getRecentData()
{
    return m_data;
}

//Transmits in master mode an amount of data in blocking mode
/*
    @params - address: Target device 7-bit address 
            - *data: pointer to data buffer - uint8_t
            - size: Amount of data to be sent
            - timeout: timeout duration
*/
HAL_StatusTypeDef I2C::masterTransmit(uint16_t address, uint8_t *data, uint32_t timeout)     
{

    uint32_t size = sizeof(*data);
    m_data = data;
    return HAL_I2C_Master_Transmit(&m_hi2c, address, data, size, timeout);  
}

//Receive in master mode an amount of data in blocking mode
HAL_StatusTypeDef I2C::masterRecieve(uint16_t address, uint8_t *data, uint32_t size, uint32_t timeout)
{
    return HAL_I2C_Master_Receive(&m_hi2c, address, data, size, timeout);
}

/*  Configures analog noise filter - FilterState is the new state of 
    analog noise filter.

    #defines:
    I2C_ANALOGFILTER_ENABLE
    I2C_ANALOGFILTER_DISABLE
*/
HAL_StatusTypeDef I2C::configAnalogFilter(uint32_t FilterState)
{
    return(HAL_I2CEx_ConfigAnalogFilter(&m_hi2c, FilterState ));
}

/*  Configures digital noise filter - FilterState is the coefficient of 
    digital noise filter between 0x00 and 0x0F (0-15)
*/
HAL_StatusTypeDef I2C::configDigitalFilter(uint32_t FilterState)
{
    return(HAL_I2CEx_ConfigDigitalFilter(&m_hi2c, FilterState));
}