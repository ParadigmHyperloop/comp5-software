#pragma once

class I2CManager
{
    private:

    // pointer to I2C Handle Type Def structure contains the config info for the specified I2C.
    I2C_HandleTypeDef *m_hi2c;
    uint8_t m_dataRecieved[4]; // Data buffer for read data
    uint32_t m_timeout; // timeout

    public:

    // Constructor
    I2CManager(I2C_HandleTypeDef *hi2c);
    
    // Returns a pointer to the data recieved buffer
    uint8_t* getRecievedData() {  return m_dataRecieved; }

    // Get state, and error methods
    HAL_I2C_StateTypeDef getState() { return HAL_I2C_GetState(m_hi2c); }
    uint32_t getError() { return HAL_I2C_GetError(m_hi2c); }

    // Getter and setter for I2C addressing mode
    void setAddressingMode(uint32_t mode) { (*m_hi2c).Init.AddressingMode = mode; }
    uint32_t getAddressingMode() { return (*m_hi2c).Init.AddressingMode; }

    // Master transmit and recieve functions (blocking mode)
    HAL_StatusTypeDef masterTransmit(uint16_t address, uint8_t *data, uint32_t timeout);   
    HAL_StatusTypeDef masterRecieve(uint16_t address, uint32_t timeout);

    // Reading / writing from device internal memory addresses 
    HAL_StatusTypeDef memWrite(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize, uint32_t timeout);
    HAL_StatusTypeDef memRead(uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize, uint32_t timeout);
    HAL_StatusTypeDef isDeviceReady(uint16_t devAddress, uint32_t trials = 100);

    // Config methods for digital and analog  noise filters
    //TO BE TESTED
    HAL_StatusTypeDef configAnalogFilter(uint32_t FilterState);
    HAL_StatusTypeDef configDigitalFilter(uint32_t FilterState);
};


