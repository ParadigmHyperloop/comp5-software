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

        EventType getType(void);
        EventState getState(void);
        timeMs_t getDelayMs(void);
        timeMs_t getLastTimeCalledMs(void);
        uint32_t getNumCallsLeft(void);

        // Setters

        void setType(EventType type);
        void setState(EventState state);
        void setDelayMs(timeMs_t delay_ms);
        void setLastTimeCalledMs(timeMs_t time_ms);
        void setCallback(void (*callback)(void));
        void setNumCallsLeft(uint32_t num_calls);

        // Take away one from the event's `m_num_calls_left`
        void decrementNumCallsLeft(void);
        void callCallback(void);
        // Reset event attributes to prepare for reassignment
        void cleanup(void);
};

#endif