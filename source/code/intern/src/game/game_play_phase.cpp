
#include "game_play_phase.h"

#include "logic/logic_play_phase.h"
#include "gui/gui_play_phase.h"
#include "graphics/gfx_play_phase.h"
#include "data/data_event_system.h"
#include "data/data_score_system.h"
#include <core/core_time.h>

namespace Game
{
    int CPlayPhase::InternOnEnter()
    {
        m_NextRunPhase = EPhase::Play;

        Data::CScoreSystem::GetInstance().ResetScore();

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

        return m_NextRunPhase;
    }

    int CPlayPhase::InternOnLeave()
    {
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::Finished, &Finish);
        Data::CEventSystem::GetInstance().Unregister(Data::SEventType::EscapePressed, &Exit);

        Logic::CPlayPhase::GetInstance().OnLeave();
        Gui  ::CPlayPhase::GetInstance().OnLeave();
        Gfx  ::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    void CPlayPhase::Finish(Data::CEvent&)
    {
        CPlayPhase::GetInstance().m_NextRunPhase = CPhase::UnloadMap;
    }

    void CPlayPhase::Exit(Data::CEvent&)
    {
        CPlayPhase::GetInstance().m_NextRunPhase = CPhase::UnloadMap;
    }
}

