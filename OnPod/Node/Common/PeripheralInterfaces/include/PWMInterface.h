#include "main.h"

#ifndef PWMINTERFACE_H
#define PWMINTERFACE_H

class PWMInterface
{
public:
    void PWMStart();
    void PWMStop();
    void setPeriod(uint32_t period);
    void setPulse(uint32_t pulse);
    void setParameters(uint64_t clockSpeed, uint32_t preScaler, 
    uint32_t period, uint32_t pulse, TIM_HandleTypeDef timer, uint32_t channel);

private:
    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;
    TIM_HandleTypeDef m_timer;
    uint32_t m_channel;
};


#endif