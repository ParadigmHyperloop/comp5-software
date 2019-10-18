#include "PWMManager.h"

PWMManager::PWMManager(uint64_t clockSpeed, uint32_t preScaler, uint32_t period, uint32_t pulse, TIM_HandleTypeDef &tim, uint32_t channel)
: m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period), m_pulse(pulse), m_timer(tim), m_channel(channel)
{};

void PWMManager::PWMStart()
{
    HAL_TIM_PWM_Start(&m_timer, m_channel);
    __HAL_TIM_SET_PRESCALER(&m_timer, m_preScaler);
    __HAL_TIM_SET_COUNTER(&m_timer, m_period);
    __HAL_TIM_SET_COMPARE(&m_timer, m_channel, m_pulse);
}

void PWMManager::PWMStop()
{
    HAL_TIM_PWM_Stop(&m_timer, m_channel);
}

void PWMManager::setPulse(uint32_t newPulse)
{
    m_pulse = newPulse;
    __HAL_TIM_SET_COMPARE(&m_timer, m_channel, m_pulse);
}

void PWMManager::setDutyCycle(uint8_t newDutyCycle)
{
    m_pulse = m_period * (newDutyCycle / 100.0);
    __HAL_TIM_SET_COMPARE(&m_timer, m_channel, m_pulse);
}

void PWMManager::setPeriodMs(uint32_t newPeriod)
{
    m_period = newPeriod / 1000.0;
    __HAL_TIM_SET_COUNTER(&m_timer, m_period);
}

void PWMManager::setPeriodUs(uint32_t newPeriod)
{
    m_period = newPeriod / 1000000.0;
    __HAL_TIM_SET_COUNTER(&m_timer, m_period);
}

void PWMManager::setFrequencyHz(uint32_t newFrequency)
{
    m_period = 1.0 / newFrequency;
    __HAL_TIM_SET_COUNTER(&m_timer, m_period);
}
