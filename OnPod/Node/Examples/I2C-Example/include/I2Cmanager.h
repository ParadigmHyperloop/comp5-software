#include "main.h"

class I2C
{
    private:

    // pointer to I2C Handle Type Def structure contains the config info for the specified I2C.
    I2C_HandleTypeDef *m_hi2c;
    uint8_t *m_recentData; // pointer to data most recently transmitted
    uint8_t *m_dataRecieved; // pointer to data most recently received
    uint16_t m_dev_address; // address of device most recently transmitted to
    uint32_t m_timeout; // timeout 

    public:

    // Constructor
    I2C(I2C_HandleTypeDef *hi2c, uint32_t timeout);
    
    // Getter/setter for I2C HandleTypeDef
    HAL_I2C_StateTypeDef setHandleTypeDef(I2C_HandleTypeDef *hi2c);
    I2C_HandleTypeDef* getHandleTypeDef();

    // Getter for data
    void setRecentData(uint8_t *pData);
    uint8_t* getRecentData();

    void setRecievedData(uint8_t *pData);
    uint8_t* getRecievedData();

    void setDevAddress(uint16_t dev_address);
    uint16_t getDevAddress();

    void setTimeout(uint32_t timeout);
    uint32_t getTimeout();

    //get state, mode, and error methods
    HAL_I2C_StateTypeDef getState();
    HAL_I2C_ModeTypeDef getMode();
    uint32_t getError();

    /* Getter and setter for addressing mode (10 bit or 7 bit) 
        #defined as:
        I2C_ADDRESSINGMODE_7BIT
        I2C_ADDRESSINGMODE_10BIT
    */
    void setAddressingMode(uint32_t mode);
    uint32_t getAddressingMode();

    // Master transmit and recieve functions (blocking mode)
    HAL_StatusTypeDef masterTransmit(uint16_t address, uint8_t *data);   
    HAL_StatusTypeDef masterRecieve(uint16_t address, uint8_t *data);

    // Reading / writing from internal register addresses. Functions for use with internal memory. 
    HAL_StatusTypeDef memWrite(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize);
    HAL_StatusTypeDef memRead(uint8_t *data, uint16_t devAddress, uint16_t memAddress, uint16_t memAddressSize);
    HAL_StatusTypeDef isDeviceReady(uint16_t devAddress, uint32_t trials = 100);

    // Config methods for digital and analog  noise filters
    HAL_StatusTypeDef configAnalogFilter(uint32_t FilterState);
    HAL_StatusTypeDef configDigitalFilter(uint32_t FilterState);
    
};


