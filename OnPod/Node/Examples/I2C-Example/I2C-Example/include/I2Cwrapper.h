#include "main.h"

class I2C
{
    private:

    // I2C Handle Type Def structure contains the config info for the specified I2C.
    I2C_HandleTypeDef m_hi2c;

    public:

    // Constructor
    I2C(I2C_HandleTypeDef hi2c);

    // Getter/setter for I2C HandleTypeDef
    void setHandleTypeDef(I2C_HandleTypeDef hi2c);
    I2C_HandleTypeDef getHandleTypeDef();

    // Various transmit and recieve functions(some undefined as of yet)
    void masterTransmit(uint16_t address, uint8_t *data, uint32_t size, uint32_t timeout);    
    void masterRecieve();
    void slaveTransmit();
    void slaveRecieve();
   
};

