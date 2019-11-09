#ifndef NODE_CAN_MANAGER_H
#define NODE_CAN_MANAGER_H

#include "can_interface.h"


class CANManager
{
private:
    CANInterface m_can_interface;
    uint8_t m_tx_buffer[8] = {0};

public:
    CANManager (CANInterface can_interface);

    bool transmit(void);

    void setTxId(uint16_t can_id);

    void txMsgSetBool(bool data, uint8_t position);

    void txMsgSetFloat(float data, uint8_t position);
    void txMsgSetDouble(double data);

    void txMsgSetUInt8(uint8_t data, uint8_t position);
    void txMsgSetUInt16(uint16_t data, uint8_t position);
    void txMsgSetUInt32(uint32_t data, uint8_t position);
    void txMsgSetUInt64(uint64_t data);

    void txMsgSetInt8(int8_t data, uint8_t position);
    void txMsgSetInt16(int16_t data, uint8_t position);
    void txMsgSetInt32(int32_t data, uint8_t position);
    void txMsgSetInt64(int64_t data);
};

#endif