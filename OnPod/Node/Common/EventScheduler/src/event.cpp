#include "event.h"

void Event::cleanup(void)
{
    m_type = EventType::UNASSIGNED;
    m_state = EventState::STOPPED;
    m_callback = nullptr;
    m_delay_ms = 0;
    m_last_time_called_ms = 0;
    m_num_calls_left = 0;
}
