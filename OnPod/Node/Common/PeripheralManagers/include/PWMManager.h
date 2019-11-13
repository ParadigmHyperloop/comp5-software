#include <stdint.h>
#include "PWMInterface.h"
#include "mock_PWMInterface.h"

#ifndef PWMMANAGER_H
#define PWMMANAGER_H

class PWMManager
{
public:
    
    // Constructor
    PWMManager(uint64_t clockSpeed, uint32_t preScaler, uint32_t period, 
    uint32_t pulse, PWMInterface interface);

    // Start and Stop
    void PWMStart();
    void PWMStop();

    // Getters
    uint32_t getPeriodCycles();
    uint32_t getPeriodMs();
    uint32_t getPeriodUs();
    uint8_t getDutyCyclePercent();
    uint32_t getFrequencyHz();
    uint32_t getPulseCycles();
    uint32_t getPulseMs();
    uint32_t getPulseUs();


    // Setters
    void setPeriodCycles(uint32_t newPeriod);
    void setPeriodMs(uint32_t newPeriod);
    void setPeriodUs(uint32_t newPeriod);
    void setDutyCyclePercent(uint8_t newDutyCycle);
    void setFrequencyHz(uint32_t newFrequency);
    void setPulseCycles(uint32_t newPulse);
    void setPulseMs(uint32_t newPulse);
    void setPulseUs(uint32_t newPulse);

    // Updates the member interface object which will apply any changes
    // to member variables and call the PWMInterface methods
    void updateInterface();

private:

    uint64_t m_clockSpeed;
    uint32_t m_preScaler;
    uint32_t m_period;
    uint32_t m_pulse;                   
    PWMInterface m_interface;
    mock_PWMInterface m_mockInterface;

};
#endif
