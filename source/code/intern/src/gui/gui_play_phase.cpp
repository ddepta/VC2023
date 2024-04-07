#include "gui_play_phase.h"
#include "gui_input_system.h"

namespace Gui
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        CInputSystem::GetInstance().OnRun();
    }

    void CPlayPhase::OnLeave() {}
}