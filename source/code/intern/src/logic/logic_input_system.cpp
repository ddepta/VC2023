#include "logic_input_system.h"

#include <assert.h>

namespace Logic 
{
    CInput& CInputSystem::CreateInput() 
    {
        return *(new CInput());
    }

    void CInputSystem::AddInput(CInput& _rInput) 
    {
        m_InputQueue.push(&_rInput);
    }

    CInput& CInputSystem::GetNextInQueue() 
    {
        assert(!m_InputQueue.empty());

        return *m_InputQueue.front();
    }

    void CInputSystem::RemoveNextInQueue() 
    {
        CInput* pEvent = m_InputQueue.front();
        delete pEvent;
        m_InputQueue.pop();
    }

    bool CInputSystem::InputQueueIsEmpty() const 
    {
        return m_InputQueue.empty();
    }

    void CInputSystem::DispatchInputToLogic(Data::CEvent& _rEvent)
    {
        CInput& rEvent = *(new CInput());
        rEvent.SetType(Data::SEventType::EEventType(_rEvent.GetData()));

        CInputSystem::GetInstance().AddInput(rEvent);
	}
}