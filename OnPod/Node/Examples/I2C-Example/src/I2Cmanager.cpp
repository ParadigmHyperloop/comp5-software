#include"main.h"
#include "I2CManager.h"

// Constructor 
I2C::I2C(I2C_HandleTypeDef *hi2c, uint32_t timeout)
{
    setHandleTypeDef(hi2c);
    setTimeout(timeout);
}

//setter for I2C HandleTypeDef structure
HAL_I2C_StateTypeDef I2C::setHandleTypeDef(I2C_HandleTypeDef *hi2c)
{
    HAL_I2C_StateTypeDef state = HAL_I2C_GetState(hi2c);

    if(state==HAL_I2C_STATE_READY )
    {
        m_hi2c = hi2c;
    }
    else
    {
        //implement error handling
    }
    return state;
}

//getter for I2C HandleTypeDef
I2C_HandleTypeDef* I2C::getHandleTypeDef()
{
    return m_hi2c;
}

//setter for target device address
void I2C::setDevAddress(uint16_t devAddress)
{
    m_dev_address = devAddress;
}

//getter for device address
uint16_t I2C::getDevAddress()
{
    return m_dev_address;
}


void I2C::setTimeout(uint32_t timeout)
{
    m_timeout = timeout;
}

uint32_t I2C::getTimeout()
{
    return m_timeout;
}

// setter for I2C addressing mode (7 or 10 bit addressing mode)
void I2C::setAddressingMode(uint32_t mode)
{
    (*m_hi2c).Init.AddressingMode = mode;
}

//getter for I2C addressing mode (7 or 10 bit addressing mode)
uint32_t I2C::getAddressingMode()
{
    return (*m_hi2c).Init.AddressingMode;
}

//getter for I2C mode
HAL_I2C_ModeTypeDef I2C::getMode()
{
    return(HAL_I2C_GetMode(m_hi2c));
}

//getter for I2C state
HAL_I2C_StateTypeDef I2C::getState()
{
    return(HAL_I2C_GetState(m_hi2c));
}

//getter for I2C error code
uint32_t I2C::getError()
{
    return(HAL_I2C_GetError(m_hi2c));
}

//getter for the current / most recent data set
uint8_t* I2C::getRecentData()
{
    return m_recentData;
}

void I2C::setRecentData(uint8_t *data)
{
    m_recentData = data;
}

uint8_t* I2C::getRecievedData()
{
    return m_dataRecieved;
}

void I2C::setRecievedData(uint8_t *data)
{
    m_dataRecieved = data;
}



//TRANSMISSION FUNCTIONS
//Transmits in master mode an amount of data in blocking mode
/*
    @params - address: Target device 7-bit address 
            - *data: pointer to data buffer - uint8_t
            - size: Amount of data to be sent
            - timeout: timeout duration
*/
HAL_StatusTypeDef I2C::masterTransmit(uint16_t devAddress, uint8_t *data)     
{
    uint32_t size = sizeof(*data); 
    setRecentData(data);
    setDevAddress(devAddress);
    return (HAL_I2C_Master_Transmit(m_hi2c, devAddress, data, size, m_timeout));  
}

//Receive in master mode an amount of data in blocking mode using 
HAL_StatusTypeDef I2C::masterRecieve(uint16_t devAddress, uint8_t *data)
{
    uint32_t size = sizeof(*data); 
    setRecievedData(data);
    setDevAddress(devAddress);
    return HAL_I2C_Master_Receive(m_hi2c, devAddress, data, size, m_timeout);
}

HAL_StatusTypeDef I2C::memWrite(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize)
{
    uint32_t size = sizeof(*data); 
    setRecentData(data);
    setDevAddress(devAddress);
    return (HAL_I2C_Mem_Write(m_hi2c, devAddress, memAddress, memAddressSize, data, size, m_timeout));

}

HAL_StatusTypeDef I2C::memRead(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize)
{
    uint32_t size = sizeof(*data); 
    setRecievedData(data);
    setDevAddress(devAddress);
    return (HAL_I2C_Mem_Write(m_hi2c, devAddress, memAddress, memAddressSize, data, size, m_timeout));
}

//Checks if target device is ready for communication
HAL_StatusTypeDef I2C::isDeviceReady(uint16_t devAddress, uint32_t trials)
{
    return (HAL_I2C_IsDeviceReady(m_hi2c, devAddress, trials, m_timeout ));
}




//CONFIGURATION FUNCTIONS
/*  Configures analog noise filter - FilterState is the new state of 
    analog noise filter.

    #defines:
    I2C_ANALOGFILTER_ENABLE
    I2C_ANALOGFILTER_DISABLE
*/
HAL_StatusTypeDef I2C::configAnalogFilter(uint32_t FilterState)
{
    return(HAL_I2CEx_ConfigAnalogFilter(m_hi2c, FilterState ));
}

/*  Configures digital noise filter - FilterState is the coefficient of 
    digital noise filter between 0x00 and 0x0F
*/
HAL_StatusTypeDef I2C::configDigitalFilter(uint32_t FilterState)
{
    return(HAL_I2CEx_ConfigDigitalFilter(m_hi2c, FilterState));
}