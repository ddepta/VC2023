#include "game_mainmenu_phase.h"
#include "data/data_mainmenu_phase.h"
#include "gui/gui_mainmenu_phase.h"
#include "graphics/gfx_mainmenu_phase.h"
#include "data/data_event_system.h"

namespace Game
{
    int CMainMenuPhase::InternOnEnter()
    {
        nextRunPhase = EPhase::MainMenu;

        Data::CEventSystem::GetInstance().Register(Data::SEventType::EnterPressed, &CMainMenuPhase::OnStart);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::EscapePressed, &CMainMenuPhase::OnExit);

        Data::CMainMenuPhase::GetInstance().OnEnter();
        Gui ::CMainMenuPhase::GetInstance().OnEnter();
        Gfx ::CMainMenuPhase::GetInstance().OnEnter();

        return 0;
    }

    int CMainMenuPhase::InternOnRun()
    {
        Data::CMainMenuPhase::GetInstance().OnRun();
        Gui ::CMainMenuPhase::GetInstance().OnRun();
        Gfx ::CMainMenuPhase::GetInstance().OnRun();

        return nextRunPhase;
    }

    int CMainMenuPhase::InternOnLeave()
    {
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::EnterPressed, &CMainMenuPhase::OnStart);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::EscapePressed, &CMainMenuPhase::OnExit);

        Data::CMainMenuPhase::GetInstance().OnLeave();
        Gui ::CMainMenuPhase::GetInstance().OnLeave();
        Gfx ::CMainMenuPhase::GetInstance().OnLeave();

        return 0;
    }

    void CMainMenuPhase::OnStart(Data::CEvent& _rEvent)
    {
        CMainMenuPhase::GetInstance().nextRunPhase = CPhase::LoadMap;
    }

    void CMainMenuPhase::OnExit(Data::CEvent& _rEvent)
    {
        CMainMenuPhase::GetInstance().nextRunPhase = CPhase::Shutdown;
    }
}
