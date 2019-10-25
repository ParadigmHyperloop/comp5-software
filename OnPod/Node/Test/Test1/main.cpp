#include <unity.h>
#include "mock_class.h"
#include "driver1.h"

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

