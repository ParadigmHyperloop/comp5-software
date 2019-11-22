#include <vector>
#include "event_scheduler.h"

void EventScheduler::updateEvents(timeMs_t current_time)
{
    std::vector<eventId_t> events_to_erase;
    for (auto& [id, event] : m_events)
    {
        if (event.state == EventState::STOPPED)
        {
            continue;
        }

        if (current_time - event.last_time_called_ms >= event.delay_ms)
        {
            event.callback();
            event.last_time_called_ms = current_time;
            if (event.type == EventType::FINITE)
            {
                event.num_calls_left--;
                if (event.num_calls_left == 0)
                {
                    events_to_erase.push_back(id);
                }
            }
        }
    }
    for (auto const id : events_to_erase)
    {
        m_events.erase(id);
    }
}

eventId_t EventScheduler::findFreeEventId(void)
{
    // If map is too damn big return error
    if (m_events.size() >= m_MAX_NUM_EVENTS)
    {
        return -1;
    }
    else if (m_events.empty())
    {
        return 0;
    }
    
    // Iterate over the map and see if index_being_checked is already taken
    // If so, check the next index. If not, the new event's id will be index_being_checked
    eventId_t index_being_checked = 0;
    for (auto event : m_events)
    {
        if (event.first == index_being_checked)
        {
            index_being_checked++;
        }
        else
        {
            return index_being_checked;
        }
    }
    if (index_being_checked <= m_MAX_NUM_EVENTS)
    {
        return index_being_checked;
    }
    return -1;
}

void EventScheduler::startEvent(eventId_t id)
{
    m_events[id].state = EventState::STARTED;
}

void EventScheduler::stopEvent(eventId_t id)
{
    m_events[id].state = EventState::STOPPED;
}

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time, uint32_t repeat_count)
{
    eventId_t id = findFreeEventId();
    if (id == -1)
    {
        return id;
    }
    Event event;
    event.type = EventType::FINITE;
    event.state = EventState::STARTED;
    event.delay_ms = delay_ms;
    event.last_time_called_ms = current_time;
    event.callback = callback;
    event.num_calls_left = repeat_count;
    m_events.insert({id, event});
    return id;
}

eventId_t EventScheduler::callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)
{
    eventId_t id = findFreeEventId();
    if (id == -1)
    {
        return id;
    }
    Event event;
    event.type = EventType::FOREVER;
    event.state = EventState::STARTED;
    event.delay_ms = delay_ms;
    event.last_time_called_ms = current_time;
    event.callback = callback;
    event.num_calls_left = 0;
    m_events.insert({id, event});
    return id;
}

eventId_t EventScheduler::callFunctionAfter(timeMs_t delay_ms, void (*callback)(void),
                                            timeMs_t current_time)
{
    return callFunctionEvery(delay_ms, callback, current_time, 1);
}
