#include "gui_shutdown_phase.h"

#include "data/data_event_type.h"
#include "data/data_event_system.h"
#include "gui/gui_input_system.h"

namespace Gui
{
    void CShutdownPhase::OnEnter()
    {}

    void CShutdownPhase::OnRun()
    {}

    void CShutdownPhase::OnLeave()
    {
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::DispatchEvent, &CInputSystem::GetInstance().DispatchEvent);
    }
}