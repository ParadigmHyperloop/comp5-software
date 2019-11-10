#include "event_scheduler.h"

void EventScheduler::updateEvents(timeMs_t current_time)
{
    for (eventId_t id = 0; id < m_MAX_NUM_EVENTS; id++)
    {
        Event event = m_events[id];
        if (event.getType() == EventType::UNASSIGNED 
            || event.getState() == EventState::STOPPED)
        {
            continue;
        }
        if ((current_time-event.getLastTimeCalledMs() >= event.getDelayMs()))
        {
            event.callCallback();
            if (event.getType() == EventType::FINITE)
            {
                event.decrementNumCallsLeft();
                if (event.getNumCallsLeft() == 0)
                {
                    event.cleanup();
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

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void), uint32_t repeat_count,
                                            timeMs_t current_time)
{
    eventId_t id = findFreeEvent();
    Event event = m_events[id];
    event.setType(EventType::FINITE);
    event.setState(EventState::STARTED);
    event.setDelayMs(delay_ms);
    event.setLastTimeCalledMs(current_time);
    event.setCallback(callback);
    event.setNumCallsLeft(repeat_count);
    return id;
}

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)

{
    eventId_t id = findFreeEvent();
    Event event = m_events[id];
    event.setType(EventType::FOREVER);
    event.setState(EventState::STARTED);
    event.setDelayMs(delay_ms);
    event.setLastTimeCalledMs(current_time);
    event.setCallback(callback);
    event.setNumCallsLeft(0);
    return id;
}

eventId_t EventScheduler::callFunctionAfter(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)
{
    eventId_t id = findFreeEvent();
    Event event = m_events[id];
    event.setType(EventType::FINITE);
    event.setState(EventState::STARTED);
    event.setDelayMs(delay_ms);
    event.setLastTimeCalledMs(current_time);
    event.setCallback(callback);
    event.setNumCallsLeft(1);
    return id;
}