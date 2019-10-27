#include "main.h"
#include "PWMInterface.h"

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
    void setDutyCyclePercent(uint8_t newDutyCycle);
    void setFrequencyHz(uint32_t newFrequency);
    void setPulseMs(uint32_t newPulse);
    void setPulseUs(uint32_t newPulse);

private:
    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;            
    TIM_HandleTypeDef m_timer;   
    uint32_t m_channel;         
    PWMInterface m_interface;
};

#endif