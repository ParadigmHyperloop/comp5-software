#include "main.h"

class I2C
{
    private:

    // I2C Handle Type Def structure contains the config info for the specified I2C.
    I2C_HandleTypeDef m_hi2c;
    uint8_t* m_data;

    public:

    // Constructor
    I2C(I2C_HandleTypeDef hi2c);
    
    // Getter/setter for I2C HandleTypeDef
    void setHandleTypeDef(I2C_HandleTypeDef hi2c);
    I2C_HandleTypeDef getHandleTypeDef();

    // Getter for data
    uint8_t* getRecentData();

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
    HAL_StatusTypeDef masterTransmit(uint16_t address, uint8_t *data, uint32_t timeout);   
    HAL_StatusTypeDef masterRecieve(uint16_t address, uint8_t *data, uint32_t size, uint32_t timeout);

    // Config methods for digital and analog  noise filters
    HAL_StatusTypeDef configAnalogFilter(uint32_t FilterState);
    HAL_StatusTypeDef configDigitalFilter(uint32_t FilterState);
   
   
};


