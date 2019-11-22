#ifndef NODE_EVENT_H
#define NODE_EVENT_H

#include <stdint.h>

typedef int16_t eventId_t; // Should range from 0-127. -1 indicates error in finding free ID
typedef uint32_t timeMs_t; // Time in ms

enum class EventType
{
    FINITE,     // Repeat X number of times
    FOREVER,    // Repeat forever
};

enum class EventState
{
    STARTED,
    STOPPED,
};

struct Event
{
    EventType type = EventType::FINITE;
    EventState state = EventState::STOPPED;
    void (*callback)(void) = nullptr;
    timeMs_t delay_ms = 0;
    timeMs_t last_time_called_ms = 0;
    uint32_t num_calls_left = 0;
    eventId_t id = 0;
};

#endif
