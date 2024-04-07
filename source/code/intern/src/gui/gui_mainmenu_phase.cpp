#include "gui_mainmenu_phase.h"
#include "gui_input_system.h"

namespace Gui
{
    void CMainMenuPhase::OnEnter()
    {}

    void CMainMenuPhase::OnRun()
    {
        CInputSystem::GetInstance().OnRun();
    }

    void CMainMenuPhase::OnLeave()
    {}
}