#include "PWMManager.h"

PWM::PWM(uint32_t per, uint32_t pul, TIM_HandleTypeDef &tim, uint32_t chan) : 
    period(per), pulse(pul), timer(tim), channel(chan)
    {};

void PWM::PWMStart()
{
    __HAL_TIM_SET_COUNTER(&timer, period);
    __HAL_TIM_SET_COMPARE(&timer, channel, pulse);
    HAL_TIM_PWM_Start(&timer, channel);
}

void PWM::PWMStop()
{
    HAL_TIM_PWM_Stop(&timer, channel);
}

void PWM::setDutyCycle(uint32_t newPulse)
{
    pulse = newPulse;
    __HAL_TIM_SET_COMPARE(&timer, channel, pulse);
}

void PWM::setPeriod(uint32_t newPeriod)
{
    period = newPeriod;
    __HAL_TIM_SET_COUNTER(&timer, period);
}
