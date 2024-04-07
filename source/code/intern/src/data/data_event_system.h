#pragma once
#include <list>

#include "data_event.h"
#include "data_event_listener.h"
#include "data_event_type.h"

namespace Data
{
    using EventListenerPair = std::pair<SEventType::EEventType, EventListener>;
    using EventListenerList = std::list<EventListenerPair>;

    class CEventSystem
    {
    public:
        static CEventSystem& GetInstance()
        {
            static CEventSystem s_Instance;
            return s_Instance;
        };

    public:
        void Register(SEventType::EEventType _Type, EventListener _Listener);
        void Unregister(SEventType::EEventType _Type, EventListener _Listener);

        void FireEvent(SEventType::EEventType _Type);
        void FireEvent(SEventType::EEventType _Type, int _Data);

        void AddEvent(CEvent& _Event);
        void ProcessEvents();

    private:
        void FireEvent(CEvent& _Event);

    private:
        CEventSystem();
        ~CEventSystem();

    private:
        CEventSystem(const CEventSystem&) = delete;
        CEventSystem& operator = (const CEventSystem&) = delete;

    private:
        std::list<CEvent> m_QueuedEvents;
        EventListenerList m_EventListeners;
    };
}
