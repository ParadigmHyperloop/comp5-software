#ifndef PWMMANAGER_H
#define PWMMANAGER_H

class PWM
{
public:
    PWM(uint32_t per, uint32_t pul, TIM_HandleTypeDef &tim, uint32_t chan);
    void PWMStart();
    void PWMStop();
    void setDutyCycle(uint32_t newPulse);
    void setPeriod(uint32_t newPeriod);

private:
    uint32_t period;
    uint32_t pulse;            //duty cycle
    TIM_HandleTypeDef timer;   //timer which is configured for PWM
    uint32_t channel;          //corresponds to one of channel preprocessor definitions
};

#endif