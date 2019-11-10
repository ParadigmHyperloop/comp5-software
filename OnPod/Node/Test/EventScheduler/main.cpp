#include <unity.h>
#include "event_scheduler.h"

///// TEST HELPERS /////
uint16_t test_callback_run_count = 0;

void testCallback(void)
{
    test_callback_run_count++;
}

void resetTestCallback(void)
{
    test_callback_run_count = 0;
}

///// TESTS /////

// startEvent
void startEvent_eventNotStarted_eventStarted(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.stopEvent(event);
    event_scheduler.startEvent(event);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
}

void startEvent_eventStarted_eventStaysStarted(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.startEvent(event);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

// stopEvent
void stopEvent_eventStopped_eventStaysStopped(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.stopEvent(event);
    event_scheduler.stopEvent(event);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(0, test_callback_run_count);
    resetTestCallback();
}

void stopEvent_eventNotStopped_eventStopped(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.startEvent(event);
    event_scheduler.stopEvent(event);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(0, test_callback_run_count);
    resetTestCallback();
}

// callFunctionEvery (forever)
void callFunctionEveryForever_delayPassedOnce_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryForever_delayPassedTwice_functionCalledTwice(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    event_scheduler.updateEvents(1001);
    event_scheduler.updateEvents(2002);
    TEST_ASSERT_EQUAL_UINT16(2, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryForever_delayPassedThousandTimes_functionCalledThousandTimes(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    for (uint16_t i = 1; i <= 1000; i++)
    {
        event_scheduler.updateEvents(i*1001);
    }
    TEST_ASSERT_EQUAL_UINT16(1000, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryForever_delayNotPassed_functionNotCalled(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    event_scheduler.updateEvents(999);
    TEST_ASSERT_EQUAL_UINT16(0, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryForever_delayNotPassedThenPassed_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    event_scheduler.updateEvents(999);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryForever_delayExactlyReached_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0);
    event_scheduler.updateEvents(1000);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

// callFunctionEvery (finite)
void callFunctionEveryFinite_delayNotPassed_functionNotCalled(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0, 2);
    event_scheduler.updateEvents(999);
    TEST_ASSERT_EQUAL_UINT16(0, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryFinite_delayPassed_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0, 2);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryFinite_delayPassedTwice_functionCalledTwice(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0, 2);
    event_scheduler.updateEvents(1001);
    event_scheduler.updateEvents(2002);
    TEST_ASSERT_EQUAL_UINT16(2, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryFinite_delayPassedThreeTimes_functionCalledTwice(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0, 2);
    event_scheduler.updateEvents(1001);
    event_scheduler.updateEvents(2002);
    event_scheduler.updateEvents(3003);
    TEST_ASSERT_EQUAL_UINT16(2, test_callback_run_count);
    resetTestCallback();
}

void callFunctionEveryFinite_delayNotPassedThenPassed_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    eventId_t event = event_scheduler.callFunctionEvery(1000, testCallback, 0, 2);
    event_scheduler.updateEvents(999);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

// callFunctionAfter
void callFunctionAfter_delayPassed_functionCalled(void)
{
    EventScheduler event_scheduler;
    event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.updateEvents(1001);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

void callFunctionAfter_delayNotPassed_functionNotCalled(void)
{
    EventScheduler event_scheduler;
    event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.updateEvents(999);
    TEST_ASSERT_EQUAL_UINT16(0, test_callback_run_count);
    resetTestCallback();
}

void callFunctionAfter_delayPassedTwice_functionCalledOnce(void)
{
    EventScheduler event_scheduler;
    event_scheduler.callFunctionAfter(1000, testCallback, 0);
    event_scheduler.updateEvents(1001);
    event_scheduler.updateEvents(2002);
    TEST_ASSERT_EQUAL_UINT16(1, test_callback_run_count);
    resetTestCallback();
}

int main(void)
{
    UNITY_BEGIN();

    // startEvent
    RUN_TEST(startEvent_eventNotStarted_eventStarted);
    resetTestCallback();
    RUN_TEST(startEvent_eventStarted_eventStaysStarted);
    resetTestCallback();

    // stopEvent
    RUN_TEST(stopEvent_eventStopped_eventStaysStopped);
    resetTestCallback();
    RUN_TEST(stopEvent_eventNotStopped_eventStopped);
    resetTestCallback();

    // callFunctionEvery (forever)
    RUN_TEST(callFunctionEveryForever_delayPassedOnce_functionCalledOnce);
    resetTestCallback();
    RUN_TEST(callFunctionEveryForever_delayPassedTwice_functionCalledTwice);
    resetTestCallback();
    RUN_TEST(callFunctionEveryForever_delayPassedThousandTimes_functionCalledThousandTimes);
    resetTestCallback();
    RUN_TEST(callFunctionEveryForever_delayNotPassed_functionNotCalled);
    resetTestCallback();
    RUN_TEST(callFunctionEveryForever_delayNotPassedThenPassed_functionCalledOnce);
    resetTestCallback();
    RUN_TEST(callFunctionEveryForever_delayExactlyReached_functionCalledOnce);
    resetTestCallback();

    // callFunctionEvery (finite)
    RUN_TEST(callFunctionEveryFinite_delayNotPassed_functionNotCalled);
    resetTestCallback();
    RUN_TEST(callFunctionEveryFinite_delayPassed_functionCalledOnce);
    resetTestCallback();
    RUN_TEST(callFunctionEveryFinite_delayPassedTwice_functionCalledTwice);
    resetTestCallback();
    RUN_TEST(callFunctionEveryFinite_delayPassedThreeTimes_functionCalledTwice);
    resetTestCallback();
    RUN_TEST(callFunctionEveryFinite_delayNotPassedThenPassed_functionCalledOnce);
    resetTestCallback();

    // callFunctionAfter
    RUN_TEST(callFunctionAfter_delayPassed_functionCalled);
    resetTestCallback();
    RUN_TEST(callFunctionAfter_delayNotPassed_functionNotCalled);
    resetTestCallback();
    RUN_TEST(callFunctionAfter_delayPassedTwice_functionCalledOnce);
    resetTestCallback();

    UNITY_END();
}