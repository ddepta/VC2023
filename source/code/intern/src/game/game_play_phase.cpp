
#include "game_play_phase.h"

#include "logic/logic_play_phase.h"
#include "gui/gui_play_phase.h"
#include "graphics/gfx_play_phase.h"
#include <core/core_time.h>

namespace Game
{
    int CPlayPhase::InternOnEnter()
    {
        nextRunPhase = EPhase::Play;

        Logic::CPlayPhase::GetInstance().OnEnter();
        Gui  ::CPlayPhase::GetInstance().OnEnter();
        Gfx  ::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnLeave()
    {

        Logic::CPlayPhase::GetInstance().OnLeave();
        Gui  ::CPlayPhase::GetInstance().OnLeave();
        Gfx  ::CPlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnRun()
    {
        Core::Time::OnFrame();

        Logic::CPlayPhase::GetInstance().OnRun();
        Gui  ::CPlayPhase::GetInstance().OnRun();
        Gfx  ::CPlayPhase::GetInstance().OnRun();

        return nextRunPhase;
    }
}

