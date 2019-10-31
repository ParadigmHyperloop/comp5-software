#include "PWMInterface.h"

PWMInterface::PWMInterface(uint64_t clockSpeed, uint32_t preScaler, uint32_t period,
uint32_t pulse, TIM_HandleTypeDef timer, uint32_t channel) : 
m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period),
m_pulse(pulse), m_timer(timer), m_channel(channel)
{}

void PWMInterface::PWMStart(TIM_HandleTypeDef &timer)
{
    m_timer = timer;
    HAL_TIM_PWM_Start(&m_timer, m_channel);
    __HAL_TIM_SET_PRESCALER(&m_timer, m_preScaler);
    __HAL_TIM_SET_AUTORELOAD(&m_timer, m_period);
    __HAL_TIM_SET_COMPARE(&m_timer, m_channel, m_pulse);
}

void PWMInterface::PWMStop()
{
    HAL_TIM_PWM_Stop(&m_timer, m_channel);
}

void PWMInterface::setPeriod(uint32_t period)
{
    m_period = period;
    __HAL_TIM_SET_AUTORELOAD(&m_timer, m_period);
}

void PWMInterface::setPulse(uint32_t pulse)
{
    m_pulse = pulse;
    __HAL_TIM_SET_COMPARE(&m_timer, m_channel, m_pulse);    
}