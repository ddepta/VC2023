#include "data_event_system.h"

#include <iostream>
#include <cassert>

namespace Data
{
    CEventSystem::CEventSystem()
    {}

    CEventSystem::~CEventSystem()
    {}

    void CEventSystem::Register(SEventType::EEventType _Type, EventListener _Listener)
    {
        m_EventListeners.push_back(std::make_pair(_Type, _Listener));
    }

    void CEventSystem::Unregister(SEventType::EEventType _Type, EventListener _Listener)
    {
        for (auto Iterator = m_EventListeners.begin(); Iterator != m_EventListeners.end(); ++Iterator)
        {
            assert(Iterator->second != nullptr);

            if (Iterator->second == _Listener)
            {
                m_EventListeners.erase(Iterator);
                break;
            }
        }
    }

    void CEventSystem::FireEvent(SEventType::EEventType _Type)
    {
        CEvent* pEvent = nullptr;
        try
        {
            pEvent = new CEvent();
            pEvent->SetType(_Type);
            FireEvent(*pEvent);
        } catch (...)
        {
            delete pEvent;
        }
    }

    void CEventSystem::FireEvent(SEventType::EEventType _Type, int _Data)
    {
        CEvent* pEvent = nullptr;
        try
        {
            pEvent = new CEvent();
            pEvent->SetType(_Type);
            pEvent->SetData(_Data);
            FireEvent(*pEvent);
        } catch (...)
        {
            delete pEvent;
        }
    }

    void CEventSystem::FireEvent(CEvent& _rEvent)
    {
        for (EventListenerPair _Listener : m_EventListeners)
        {
            if (_Listener.first == _rEvent.GetType())
            {
                (*_Listener.second)(_rEvent);
            }
        }
    }

    void CEventSystem::AddEvent(CEvent& _rEvent)
    {
        m_QueuedEvents.push_back(_rEvent);
    }

    void CEventSystem::ProcessEvents()
    {
        for (CEvent& rEvent : m_QueuedEvents)
        {
            FireEvent(rEvent);
        }
    }
}
