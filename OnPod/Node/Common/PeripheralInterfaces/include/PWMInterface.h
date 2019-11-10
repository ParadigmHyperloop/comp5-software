#include "stm32f3xx_hal.h"

#ifndef PWMINTERFACE_H
#define PWMINTERFACE_H

class PWMInterface
{
public:
    PWMInterface(uint64_t clockSpeed, uint32_t preScaler, uint32_t period,
    uint32_t pulse, TIM_HandleTypeDef timer, uint32_t channel);
    void PWMStart(TIM_HandleTypeDef &timer);
    void PWMStop();
    void setPeriod(uint32_t period);
    void setPulse(uint32_t pulse);

private:
    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;
    uint32_t m_channel;
    TIM_HandleTypeDef m_timer;
};


#endif