#include "I2Cwrapper.h"

//Constructor 
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

//Transmits in master mode an amount of data in blocking mode
/*
    @params - address: Target device 7-bit address 
            - *data: pointer to data buffer
            - size: Amount of data to be sent
            - timeout: timeout duration
*/
void I2C::masterTransmit(uint16_t address, uint8_t *data, uint32_t size, uint32_t timeout)     
{
    HAL_I2C_Master_Transmit(&m_hi2c, address, data, size, timeout);  
}

void I2C::masterRecieve()
{
    //implement
}

void I2C::slaveTransmit()
{
    //implement
}

void I2C::slaveRecieve()
{
    //implement
}

