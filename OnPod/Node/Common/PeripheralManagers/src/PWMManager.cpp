#include "PWMManager.h"

PWMManager::PWMManager(uint64_t clockSpeed, uint32_t preScaler,
 uint32_t period, uint32_t pulse, PWMInterface interface)
: m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period),
m_pulse(pulse), m_interface(interface)
{}

void PWMManager::PWMStart()
{
    m_interface.setParameters(m_clockSpeed, m_preScaler, 
    m_period, m_pulse, m_timer, m_channel);
    
    m_mockInterface.setParameters(m_clockSpeed, m_preScaler, 
    m_period, m_pulse, m_timer, m_channel);
    
    m_interface.PWMStart();
}

void PWMManager::PWMStop()
{
    m_interface.PWMStop();
}

void PWMManager::setPulseMs(uint32_t newPulse)
{
    m_pulse = (newPulse / 1000.0) * ((float)m_clockSpeed / (float)m_pulse);
}

uint32_t PWMManager::getPulseMs()
{
    return m_pulse * 1000.0;
}

void PWMManager::setPulseUs(uint32_t newPulse)
{
    m_pulse = (newPulse / 1000000.0) * ((float)m_clockSpeed / (float)m_pulse);
}

uint32_t PWMManager::getPulseUs()
{
    return m_pulse * 1000000.0;
}

void PWMManager::setDutyCyclePercent(uint8_t newDutyCycle)
{
    m_pulse = m_period * (newDutyCycle / 100.0);
}

uint8_t PWMManager::getDutyCyclePercent()
{
    return ((float)m_pulse / (float)m_period) * 100.0;
}

void PWMManager::setPeriodMs(uint32_t newPeriod)
{
    m_period = (newPeriod / 1000.0) * ((float)m_clockSpeed / (float)m_preScaler);
}

uint32_t PWMManager::getPeriodMs()
{
    return m_period * 1000.0;
}

void PWMManager::setPeriodUs(uint32_t newPeriod)
{
    m_period = (newPeriod / 1000000.0) * ((float)m_clockSpeed / (float)m_preScaler);
}

uint32_t PWMManager::getPeriodUs()
{
    return m_period * 1000000.0;
}

void PWMManager::setFrequencyHz(uint32_t newFrequency)
{
    m_period = (1.0 / newFrequency) * ((float)m_clockSpeed / (float)m_preScaler);
}

uint32_t PWMManager::getFrequencyHz()
{
    return 1.0 / m_period;
}

void PWMManager::updateInterface()
{
    m_interface.setPeriod(m_period);
    m_interface.setPulse(m_pulse);
}