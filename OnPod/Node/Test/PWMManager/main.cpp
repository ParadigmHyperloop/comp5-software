#include <unity.h>
#include "PWMManager.h"

PWMManager PWM(8000000, 0, 200, 100, htim2, TIM_CHANNEL_1);

void testOne(void)
{
    TEST_ASSERT_EQUAL_UINT8(7, 7);
}

int main(void) 
{
    UNITY_BEGIN();
    RUN_TEST(testOne);
    UNITY_END();
    return 0;
}

