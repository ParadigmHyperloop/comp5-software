#include <stdint.h>

#ifndef MOCK_PWMINTERFACE_H
#define MOCK_PWMINTERFACE_H

class mock_PWMInterface
{
public:
    mock_PWMInterface(uint64_t clockSpeed, uint32_t preScaler, uint32_t period,
    uint32_t pulse, uint8_t timer, uint32_t channel);
    void PWMStart();
    void PWMStop();
    void setPeriod(uint32_t period);
    void setPulse(uint32_t pulse);

private:
    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;
    uint8_t m_timer;
    uint32_t m_channel;    
};

#endif