#ifndef NODE_EVENT_SCHEDULER_H
#define NODE_EVENT_SCHEDULER_H

#include <stdint.h>
#include "event.h"

// Ranges from 0-127. -1 indicates error in finding free ID
typedef int8_t eventId_t;
typedef uint32_t timeMs_t;

class EventScheduler
{
    private:
        static const uint8_t m_MAX_NUM_EVENTS = 50;
        Event m_events[m_MAX_NUM_EVENTS];

        eventId_t findFreeEvent(void); 
        
    public:
        void updateEvents(timeMs_t current_time);

        void startEvent(eventId_t event_id);
        void stopEvent(eventId_t event_id);

        // Call `callback` every `delay_ms` milliseconds, `repeat_count` times
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full
        eventId_t callFunctionEvery(timeMs_t delay_ms, void (*callback)(void), 
                                    timeMs_t current_time, uint32_t repeat_count);
        // Call `callback` every `delay_ms` milliseconds, forever
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full
        eventId_t callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                    timeMs_t current_time);
        // Call `callback` after `delay_ms` milliseconds
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full
        eventId_t callFunctionAfter(timeMs_t delay_ms, void (*callback)(void),
                                    timeMs_t current_time);
};

#endif