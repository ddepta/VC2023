#include <iostream>
#include <assert.h>

#include "gui_input_system.h"

#include "data/data_event_system.h"
#include "data/data_event_type.h"

namespace Gui
{
    void CInputSystem::DispatchEvent(Data::CEvent& _rEvent)
    {
        CInput& rInput = *(new CInput());

        rInput.m_KeyInput.Key = sf::Keyboard::Key(_rEvent.GetData());

        CInputSystem::GetInstance().m_InputQueue.push(&rInput);
    }

    CInput& CInputSystem::GetNextInput()
    {
        assert(!m_InputQueue.empty());

        return *m_InputQueue.front();
    }

    void CInputSystem::RemoveNextInput()
    {
        assert(!m_InputQueue.empty());

        CInput* pInput = m_InputQueue.front();

        delete pInput;

        m_InputQueue.pop();
    }

    bool CInputSystem::InputQueueHasInputs() const
    {
        return !m_InputQueue.empty();
    }

    void CInputSystem::OnRun()
    {
        CInput Input;

        while (InputQueueHasInputs())
        {
            Input = GetNextInput();

            if (Input.m_KeyInput.Key == sf::Keyboard::Key::Escape)
            {
                Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::EscapePressed);
            }
            else if (Input.m_KeyInput.Key == sf::Keyboard::Key::Enter)
            {
                Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::EnterPressed);
            }
            //else if (Input.m_KeyInput.Key == sf::Keyboard::Key::Up)
            //{
            //    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::UpPressed);
            //}
            //else if (Input.m_KeyInput.Key == sf::Keyboard::Key::Down)
            //{
            //    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::DownPressed);
            //}
            //else if (Input.m_KeyInput.Key == sf::Keyboard::Key::Left)
            //{
            //    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::LeftPressed);
            //}
            //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            //{
            //    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::RightPressed);
            //}

            RemoveNextInput();
        }
    }
}