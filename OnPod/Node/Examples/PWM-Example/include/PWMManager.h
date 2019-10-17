#include "main.h"

#ifndef PWMMANAGER_H
#define PWMMANAGER_H

class PWMManager
{
public:
    PWMManager(uint64_t clockSpeed, uint32_t preScaler, uint32_t period, uint32_t pulse, TIM_HandleTypeDef &tim, uint32_t channel);
    void PWMStart();
    void PWMStop();
    void setPeriodMs(uint32_t newPeriod);
    void setPeriodUs(uint32_t newPeriod);
    void setDutyCycle(uint8_t newDutyCycle);
    void setFrequencyHz(uint32_t newFrequency);

private:
    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;            //duty cycle
    TIM_HandleTypeDef m_timer;   //timer which is configured for PWM
    uint32_t m_channel;          //corresponds to one of channel preprocessor definitions
};

#endif