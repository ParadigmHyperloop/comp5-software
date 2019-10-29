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
    uint32_t getPeriodMs();
    void setPeriodUs(uint32_t newPeriod);
    uint32_t getPeriodUs();
    void setDutyCyclePercent(uint8_t newDutyCycle);
    uint8_t getDutyCyclePercent();
    void setFrequencyHz(uint32_t newFrequency);
    uint32_t getFrequencyHz();
    void setPulseMs(uint32_t newPulse);
    uint32_t getPulseMs();
    void setPulseUs(uint32_t newPulse);
    uint32_t getPulseUs();

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