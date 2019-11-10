#include "event_scheduler.h"

void EventScheduler::updateEvents(timeMs_t current_time)
{
    // Iterate through m_events array
    for (eventId_t id = 0; id < m_MAX_NUM_EVENTS; id++)
    {
        // Ignore stopped or unused event objects
        if (m_events[id].getType() == EventType::UNASSIGNED || 
            m_events[id].getState() == EventState::STOPPED)
        {
            continue;
        }
        // If the event's delay has passed
        if ((current_time - m_events[id].getLastTimeCalledMs() >= m_events[id].getDelayMs()))
        {
            m_events[id].callCallback();
            m_events[id].setLastTimeCalledMs(current_time);
            // If the event only runs a certain number of times
            if (m_events[id].getType() == EventType::FINITE)
            {
                m_events[id].decrementNumCallsLeft();
                // Unassign/reset event objects that are finished
                if (m_events[id].getNumCallsLeft() == 0)
                {
                    m_events[id].cleanup();
                }
            }
        }
    }
}

eventId_t EventScheduler::findFreeEvent(void)
{
    for (eventId_t id = 0; id < m_MAX_NUM_EVENTS; id++)
    {
        if (m_events[id].getType() == EventType::UNASSIGNED)
        {
            return id;
        }
    }
    return -1;
}

void EventScheduler::startEvent(eventId_t event_id)
{
    m_events[event_id].setState(EventState::STARTED);
}

void EventScheduler::stopEvent(eventId_t event_id)
{
    m_events[event_id].setState(EventState::STOPPED);
}

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time, uint32_t repeat_count)
{
    eventId_t id = findFreeEvent();
    m_events[id].setType(EventType::FINITE);
    m_events[id].setState(EventState::STARTED);
    m_events[id].setDelayMs(delay_ms);
    m_events[id].setLastTimeCalledMs(current_time);
    m_events[id].setCallback(callback);
    m_events[id].setNumCallsLeft(repeat_count);
    return id;
}

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)
{
    eventId_t id = findFreeEvent();
    m_events[id].setType(EventType::FOREVER);
    m_events[id].setState(EventState::STARTED);
    m_events[id].setDelayMs(delay_ms);
    m_events[id].setLastTimeCalledMs(current_time);
    m_events[id].setCallback(callback);
    m_events[id].setNumCallsLeft(0);
    return id;
}

eventId_t EventScheduler::callFunctionAfter(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)
{
    return callFunctionEvery(delay_ms, callback, current_time, 1);
}