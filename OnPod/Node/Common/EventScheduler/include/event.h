#ifndef NODE_EVENT_H
#define NODE_EVENT_H

#include <stdint.h>

typedef uint32_t timeMs_t; // Time in ms

enum class EventType
{
    UNASSIGNED,
    FINITE,     // Repeat X number of times
    FOREVER,    // Repeat forever
};

enum class EventState
{
    STARTED,
    STOPPED,
};

class Event
{
    private:
        EventType m_type = EventType::UNASSIGNED;
        EventState m_state = EventState::STOPPED;
        void (*m_callback)(void) = nullptr;
        timeMs_t m_delay_ms = 0;
        timeMs_t m_last_time_called_ms = 0;
        uint32_t m_num_calls_left = 0;

    public:
        // Getters
        EventType getType(void) { return m_type; };
        EventState getState(void) { return m_state; };
        timeMs_t getDelayMs(void) { return m_delay_ms; };
        timeMs_t getLastTimeCalledMs(void) { return m_last_time_called_ms; };
        uint32_t getNumCallsLeft(void) { return m_num_calls_left; };

        // Setters
        void setType(EventType type) { m_type = type; };
        void setState(EventState state) { m_state = state; };
        void setDelayMs(timeMs_t delay_ms) { m_delay_ms = delay_ms; };
        void setLastTimeCalledMs(timeMs_t time_ms) { 
            m_last_time_called_ms = time_ms; 
        };
        void setCallback(void (*callback)(void)) { m_callback = callback; };
        void setNumCallsLeft(uint32_t num_calls) { 
            m_num_calls_left = num_calls; 
        };

        // Take away one from the event's `m_num_calls_left`
        void decrementNumCallsLeft(void) { m_num_calls_left--; };
        void callback(void) { m_callback(); };
        // Reset event attributes to prepare for reassignment
        void cleanup(void);
};

#endif
