#include "can_interface.h"
#include "convert_hal_status.h"

{
    m_tx_header.StdId = 0x7FF;      // Lowest priority
    m_tx_header.ExtId = 0x000;      // Always 0 
    m_tx_header.IDE = CAN_ID_STD;   // Always standard
    m_tx_header.RTR = CAN_RTR_DATA; // Always data
    m_tx_header.DLC = 0;            // 0 by default

    m_rx_header.StdId = 0x7FF;        // Lowest priority
    m_rx_header.ExtId = 0x000;        // Always 0 
    m_rx_header.IDE = CAN_ID_STD;     // Always standard
    m_tx_header.RTR = CAN_RTR_DATA;   // Always data
    m_tx_header.DLC = 0;              // 0 by default
    m_rx_header.Timestamp = 0;        // Never use this lol
    m_rx_header.FilterMatchIndex = 0; // wtf is this TODO
}
/// START/STOP ///
bool CANInterface::start(void) {
    return halStatusToBool( HAL_CAN_Start(m_can_handle) );
}

bool CANInterface::stop(void) {
    return halStatusToBool( HAL_CAN_Stop(m_can_handle) );
}

/// TRANSMIT ///
uint8_t CANInterface::getNumEmptyTxMailboxes(void) 
{
    return HAL_CAN_GetTxMailboxesFreeLevel(m_can_handle);
}

void CANInterface::setTxMailbox0(void) 
{
    m_tx_mailbox = CAN_TX_MAILBOX0;
}

void CANInterface::setTxMailbox1(void) 
{
    m_tx_mailbox = CAN_TX_MAILBOX1;
}

void CANInterface::setTxMailbox2(void) 
{
    m_tx_mailbox = CAN_TX_MAILBOX2;
}

bool CANInterface::isTxMessagePendingMailbox0(void) 
{
    return HAL_CAN_IsTxMessagePending(m_can_handle, CAN_TX_MAILBOX0);
}

bool CANInterface::isTxMessagePendingMailbox1(void) 
{
    return HAL_CAN_IsTxMessagePending(m_can_handle, CAN_TX_MAILBOX1);
}

bool CANInterface::isTxMessagePendingMailbox2(void) 
{
    return HAL_CAN_IsTxMessagePending(m_can_handle, CAN_TX_MAILBOX2);
}

bool CANInterface::transmit(uint8_t *txData)
{
    return halStatusToBool( HAL_CAN_AddTxMessage(m_can_handle, &m_tx_header, txData, &m_tx_mailbox) );
}

/// RECEIVE ///
uint8_t CANInterface::getNumMessagesFifo0(void) 
{
    return HAL_CAN_GetRxFifoFillLevel(m_can_handle, CAN_FILTER_FIFO0);
}

uint8_t CANInterface::getNumMessagesFifo1(void)
{
    return HAL_CAN_GetRxFifoFillLevel(m_can_handle, CAN_FILTER_FIFO1);
}

void CANInterface::setRxFifo0(void) {
    m_rx_fifo = CAN_RX_FIFO0;
}

void CANInterface::setRxFifo1(void) {
    m_rx_fifo = CAN_RX_FIFO1;
}

bool CANInterface::receive(uint8_t *rxData) 
{
    return halStatusToBool( HAL_CAN_GetRxMessage(m_can_handle, m_rx_fifo, &m_rx_header, rxData) );
}
