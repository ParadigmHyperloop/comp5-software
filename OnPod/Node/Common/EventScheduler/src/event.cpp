#include "event.h"

EventType Event::getType(void)
{
    return m_type;
}

EventState Event::getState(void)
{
    return m_state;
}

uint32_t Event::getDelayMs(void)
{
    return m_delay_ms;
}

uint32_t Event::getLastTimeCalledMs(void)
{
    return m_last_time_called_ms;
}

uint32_t Event::getNumCallsLeft(void)
{
    return m_num_calls_left;
}


void Event::setType(EventType type)
{
    m_type = type;
}

void Event::setState(EventState state)
{
    m_state = state;
}

void Event::setDelayMs(timeMs_t delay_ms)
{
    m_delay_ms = delay_ms;
}

void Event::setLastTimeCalledMs(timeMs_t time_ms)
{
    m_last_time_called_ms = time_ms;
}

void Event::setCallback(void (*callback)(void))
{
    m_callback = callback;
}

void Event::setNumCallsLeft(uint32_t num_calls)
{
    m_num_calls_left = num_calls;
}


void Event::decrementNumCallsLeft(void)
{
    m_num_calls_left--;
}


void Event::callCallback(void)
{
    m_callback();
}

void Event::cleanup(void)
{
    m_type = EventType::UNASSIGNED;
    m_state = EventState::STOPPED;
    m_callback = nullptr;
    m_delay_ms = 0;
    m_last_time_called_ms = 0;
    m_num_calls_left = 0;
}