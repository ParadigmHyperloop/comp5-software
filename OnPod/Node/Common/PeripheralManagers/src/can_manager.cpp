#include "can_manager.h"


CANManager::CANManager(CANInterface can_interface) : m_can_interface(can_interface) {}

/// TRANSMIT ///
bool CANManager::transmit(void)
{
    if (m_can_interface.getNumEmptyTxMailboxes() == 0)
    {
        return false;
    }

    if (!m_can_interface.isTxMessagePendingMailbox(CanTxMailbox::MAILBOX0))
    {
        m_can_interface.setTxMailbox(CanTxMailbox::MAILBOX0);
    }
    else if (!m_can_interface.isTxMessagePendingMailbox(CanTxMailbox::MAILBOX1))
    {
        m_can_interface.setTxMailbox(CanTxMailbox::MAILBOX1);
    }
    else if (!m_can_interface.isTxMessagePendingMailbox(CanTxMailbox::MAILBOX2))
    {
        m_can_interface.setTxMailbox(CanTxMailbox::MAILBOX2);
    }

    return m_can_interface.transmit(m_tx_buffer);
}

void CANManager::setTxId(uint16_t can_id)
{
    m_can_interface.setTxId(can_id);
}

void CANManager::txMsgSetBool(bool data, uint8_t position)
{
    m_tx_buffer[position] = data;
}

void CANManager::txMsgSetFloat(float data, uint8_t position)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = position; index < position+sizeof(float); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index-position];
    }
}

void CANManager::txMsgSetDouble(double data)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = 0; index < sizeof(double); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index];
    }
}

void CANManager::txMsgSetUInt8(uint8_t data, uint8_t position)
{
    m_tx_buffer[position] = data;
}

void CANManager::txMsgSetUInt16(uint16_t data, uint8_t position)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = position; index < position+sizeof(uint16_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index-position];
    }
}

void CANManager::txMsgSetUInt32(uint32_t data, uint8_t position)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = position; index < position+sizeof(uint32_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index-position];
    }
}

void CANManager::txMsgSetUInt64(uint64_t data)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = 0; index < sizeof(uint64_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index];
    }
}

void CANManager::txMsgSetInt8(int8_t data, uint8_t position)
{
    uint8_t data_as_uint8_t = (uint8_t)data;
    m_tx_buffer[position] = data_as_uint8_t;
}

void CANManager::txMsgSetInt16(int16_t data, uint8_t position)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = 0; index < sizeof(int16_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index];
    }
}

void CANManager::txMsgSetInt32(int32_t data, uint8_t position)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = 0; index < sizeof(int32_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index];
    }
}

void CANManager::txMsgSetInt64(int64_t data)
{
    uint8_t *data_as_uint8_t = (uint8_t*)(&data);
    for (uint8_t index = 0; index < sizeof(int64_t); index++)
    {
        m_tx_buffer[index] = data_as_uint8_t[index];
    }
}