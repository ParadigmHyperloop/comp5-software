#ifndef NODE_CAN_INTERFACE_H
#define NODE_CAN_INTERFACE_H

#include "stm32f3xx_hal.h"

class CANInterface
{
private:
    CAN_HandleTypeDef *m_can_handle;

    CAN_TxHeaderTypeDef m_tx_header;
    uint32_t m_tx_mailbox = CAN_TX_MAILBOX0;
    CAN_RxHeaderTypeDef m_rx_header;
    uint32_t m_rx_fifo = CAN_RX_FIFO0;

public:
    // Constructor
    CANInterface(CAN_HandleTypeDef *can_handle);

    // Start CAN peripheral - returns true if successful
    bool start(void);
    // Stop CAN peripheral - returns true if successful
    bool stop(void);

    // Returns number of empty transmit mailboxes
    uint8_t getNumEmptyTxMailboxes(void);
    // Set transmit mailbox to CAN_TX_MAILBOX0
    void setTxMailbox0(void);
    // Set transmit mailbox to CAN_TX_MAILBOX1
    void setTxMailbox1(void);
    // Set transmit mailbox to CAN_TX_MAILBOX2
    void setTxMailbox2(void);
    // Check if a tx message is pending in CAN_TX_MAILBOX0
    bool isTxMessagePendingMailbox0(void);
    // Check if a tx message is pending in CAN_TX_MAILBOX1
    bool isTxMessagePendingMailbox1(void);
    // Check if a tx message is pending in CAN_TX_MAILBOX2
    bool isTxMessagePendingMailbox2(void);
    // Copy message to transmit mailbox - returns true if successful
    bool transmit(uint8_t *txData);

    // Get number of messages in recieve fifo 0
    uint8_t getNumMessagesFifo0(void);
    // Get number of messages in recieve fifo 0
    uint8_t getNumMessagesFifo1(void);
    // Set recieve fifo to CAN_RX_FIFO0
    void setRxFifo0(void);
    // Set recieve fifo to CAN_RX_FIFO1
    void setRxFifo1(void);
    // Copy message from receive fifo - returns true if successful
    bool receive(uint8_t *rxData);
};

#endif