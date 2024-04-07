
#include "game_play_phase.h"

#include "logic/logic_play_phase.h"
#include "gui/gui_play_phase.h"
#include "graphics/gfx_play_phase.h"
#include "data/data_event_system.h"
#include <core/core_time.h>

namespace Game
{
    int CPlayPhase::InternOnEnter()
    {
        nextRunPhase = EPhase::Play;

        Core::Time::Reset();

        Data::CEventSystem::GetInstance().Register(Data::SEventType::Finished, &Finish);
        Data::CEventSystem::GetInstance().Register(Data::SEventType::EscapePressed, &Exit);

        Logic::CPlayPhase::GetInstance().OnEnter();
        Gui  ::CPlayPhase::GetInstance().OnEnter();
        Gfx  ::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnRun()
    {
        Core::Time::OnFrame();

        Logic::CPlayPhase::GetInstance().OnRun();
        Gui::CPlayPhase::GetInstance().OnRun();
        Gfx::CPlayPhase::GetInstance().OnRun();

        return nextRunPhase;
    }

    int CPlayPhase::InternOnLeave()
    {

        Logic::CPlayPhase::GetInstance().OnLeave();
        Gui  ::CPlayPhase::GetInstance().OnLeave();
        Gfx  ::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    void CPlayPhase::Finish(Data::CEvent& _rEvent)
    {
        CPlayPhase::GetInstance().nextRunPhase = CPhase::UnloadMap;
    }

    void CPlayPhase::Exit(Data::CEvent& _rEvent)
    {
        CPlayPhase::GetInstance().nextRunPhase = CPhase::UnloadMap;
    }
}

