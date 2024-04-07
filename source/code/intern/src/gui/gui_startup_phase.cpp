#include "gui_startup_phase.h"

#include "data/data_event_type.h"
#include "data/data_event_system.h"
#include "gui/gui_input_system.h"

namespace Gui
{
    void CStartupPhase::OnEnter()
    {
        Data::CEventSystem::GetInstance().Register(Data::SEventType::DispatchEvent, &CInputSystem::GetInstance().DispatchEvent);
    }

    void CStartupPhase::OnRun()
    {}

    void CStartupPhase::OnLeave()
    {}
}