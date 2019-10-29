#include <unity.h>
#include "PWMManager.h"

PWMManager PWM(8000000, 0, 200, 100, htim2, TIM_CHANNEL_1);

void testSetFrequencyHz(void)
{
    PWM.setFrequencyHz(300);
    TEST_ASSERT_EQUAL_UINT8(300, PWM.getFrequencyHz());
}

void testSetPeriodMs(void)
{
    PWM.setPeriodMs(200);
    TEST_ASSERT_EQUAL_UINT32(200, PWM.getPeriodMs());
}

void testSetPeriodUs(void)
{
    PWM.setPeriodUs(50);
    TEST_ASSERT_EQUAL_UINT32(50, PWM.getPeriodUs());
}

void testSetPulseMs(void)
{
    PWM.setPulseMs(100);
    TEST_ASSERT_EQUAL_UINT32(100, PWM.getPulseMs());
}

void testSetPulseUs(void)
{
    PWM.setPulseUs(25);
    TEST_ASSERT_EQUAL_UINT32(25, PWM.getPulseUs());
}

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(testSetFrequencyHz);
    UNITY_END();
    return 0;
}

