#ifndef NODE_EVENT_SCHEDULER_H
#define NODE_EVENT_SCHEDULER_H

#include <map>
#include <stdint.h>
#include "event.h"

class EventScheduler
{
    private:
        // Number of events that can be active at once
        static const int16_t m_MAX_NUM_EVENTS = 50;
        // Map to hold events and their ids
        std::map<eventId_t, Event> m_events;

        // Return a free event id
        eventId_t findFreeEventId(void);

    public:
        int16_t getMaxNumEvents(void) { return m_MAX_NUM_EVENTS; };
        // Check if any callbacks must be called and execute them.
        // If the repeat limit is reached, reset the event object.
        void updateEvents(timeMs_t current_time);

        // Resumes the event's calls
        void startEvent(eventId_t event_id);
        // Pauses all the event's calls.
        // If the event has a certain number of repeats, they will be preserved after starting again.
        void stopEvent(eventId_t event_id);

        // Call `callback` every `delay_ms` milliseconds, `repeat_count` times.
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full.
        eventId_t callFunctionEvery(timeMs_t delay_ms, void (*callback)(void), 
                                    timeMs_t current_time, uint32_t repeat_count);
        // Call `callback` every `delay_ms` milliseconds, forever.
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full.
        eventId_t callFunctionEvery(timeMs_t delay_ms, void (*callback)(void),
                                    timeMs_t current_time);
        // Call `callback` after `delay_ms` milliseconds.
        // Returns index of event in `m_event_list` or -1 if `m_event_list` is full.
        eventId_t callFunctionAfter(timeMs_t delay_ms, void (*callback)(void),
                                    timeMs_t current_time);
};

#endif
