#include "gui_mainmenu_phase.h"

namespace Gui
{
    void CMainMenuPhase::OnEnter()
    {}

    void CMainMenuPhase::OnRun()
    {}

    void CMainMenuPhase::OnLeave()
    {}

    CMainMenuPhase::EMenuState CMainMenuPhase::GetMenuState()
    {
        return m_MenuState;
    }
    void CMainMenuPhase::SetMenuState(EMenuState _MenuState)
    {
        this->m_MenuState = _MenuState;
    }
}