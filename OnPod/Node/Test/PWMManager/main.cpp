#include <unity.h>
#include "PWMManager.h"

PWMManager::PWMManager(uint64_t clockSpeed, uint32_t preScaler, 
uint32_t period, uint32_t pulse, mock_PWMInterface interface)
: m_clockSpeed(clockSpeed), m_preScaler(preScaler), m_period(period),
m_pulse(pulse), m_mockInterface(interface)
{}

void setFrequencyHz_normalInput_frequencySet(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setFrequencyHz(300);
    TEST_ASSERT_EQUAL_UINT32(26666, PWM.getPeriodCycles());
}

void setFrequencyHz_setZeroFrequency_periodSetToZero(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setFrequencyHz(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPeriodCycles());
}

void setFrequencyHz_frequencyGreaterThanClockSpeed_periodSetToZero(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setFrequencyHz(10000000);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPeriodCycles());
}

void testSetPeriodMs_normalInput_periodSet(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setPeriodMs(200);
    TEST_ASSERT_EQUAL_UINT32(1600000, PWM.getPeriodCycles());
}

void testSetPeriodMs_zeroPeriod_periodSetToZero(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setPeriodMs(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPeriodCycles());
}

void testSetPeriodMs_periodGreaterthanClockCycle_periodSet(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);

    PWM.setPeriodMs(1200);
    TEST_ASSERT_EQUAL_UINT32(9600000, PWM.getPeriodCycles());
}

void testSetPeriodUs(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);
    PWM.setPeriodUs(50);
    TEST_ASSERT_EQUAL_UINT32(400, PWM.getPeriodCycles());
    PWM.setPeriodUs(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPeriodCycles());
    PWM.setPeriodUs(1200000);
    TEST_ASSERT_EQUAL_UINT32(9600000, PWM.getPeriodCycles());
}

void testSetPulseMs(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);
    PWM.setPulseMs(100);
    TEST_ASSERT_EQUAL_UINT32(800000, PWM.getPulseCycles());
    PWM.setPulseMs(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPulseCycles());
    PWM.setPulseMs(1200);
    TEST_ASSERT_EQUAL_UINT32(9600000, PWM.getPulseCycles());
}

void testSetPulseUs(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);
    PWM.setPulseUs(25);
    TEST_ASSERT_EQUAL_UINT32(200, PWM.getPulseCycles());
    PWM.setPulseUs(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPulseCycles());
    PWM.setPulseUs(1200000);
    TEST_ASSERT_EQUAL_UINT32(9600000, PWM.getPulseCycles());
}

void testdutyCyclePercent(void)
{
    mock_PWMInterface interface(8000000, 0, 200, 100, 1, 0);
    PWMManager PWM(8000000, 0, 200, 100, interface);
    PWM.setDutyCyclePercent(75);
    TEST_ASSERT_EQUAL_UINT32(150, PWM.getPulseCycles());
    PWM.setDutyCyclePercent(100);
    TEST_ASSERT_EQUAL_UINT32(200, PWM.getPulseCycles());
    PWM.setDutyCyclePercent(0);
    TEST_ASSERT_EQUAL_UINT32(0, PWM.getPulseCycles());
}

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(testSetFrequencyHz);
    UNITY_END();
    return 0;
}

