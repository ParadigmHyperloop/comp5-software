#include "mock_PWMInterface.h"

mock_PWMInterface::mock_PWMInterface(uint64_t clockSpeed, uint32_t preScaler, uint32_t period,
uint32_t pulse, uint8_t timer, uint32_t channel) : 
m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period), 
m_pulse(pulse), m_timer(timer), m_channel(channel)
{}

void mock_PWMInterface::PWMStart()
{
}

void mock_PWMInterface::PWMStop()
{
}

void mock_PWMInterface::setPeriod(uint32_t period)
{
    m_period = period;
}

void mock_PWMInterface::setPulse(uint32_t pulse)
{
    m_pulse = pulse;
}
