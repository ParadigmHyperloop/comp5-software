#include "PWMManager.h"

PWMManager::PWMManager(uint64_t clockSpeed, uint32_t preScaler,
 uint32_t period, uint32_t pulse, TIM_HandleTypeDef &tim, uint32_t channel)
: m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period),
m_pulse(pulse), m_timer(tim), m_channel(channel)
{}

void PWMManager::PWMStart()
{
    m_interface.setParameters(m_clockSpeed, m_preScaler, 
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
    m_interface.setPulse(m_pulse);
}

void PWMManager::setPulseUs(uint32_t newPulse)
{
    m_pulse = (newPulse / 1000000.0) * ((float)m_clockSpeed / (float)m_pulse);
    m_interface.setPulse(m_pulse);
}

void PWMManager::setDutyCyclePercent(uint8_t newDutyCycle)
{
    m_pulse = m_period * (newDutyCycle / 100.0);
    m_interface.setPulse(m_pulse);
}

void PWMManager::setPeriodMs(uint32_t newPeriod)
{
    m_period = (newPeriod / 1000.0) * ((float)m_clockSpeed / (float)m_preScaler);
    m_interface.setPeriod(m_period);
}

void PWMManager::setPeriodUs(uint32_t newPeriod)
{
    m_period = (newPeriod / 1000000.0) * ((float)m_clockSpeed / (float)m_preScaler);
    m_interface.setPeriod(m_period);
}

void PWMManager::setFrequencyHz(uint32_t newFrequency)
{
    m_period = (1.0 / newFrequency) * ((float)m_clockSpeed / (float)m_preScaler);
    m_interface.setPeriod(m_period);
}