
#include "game_play_phase.h"

#include "../../compiler/logic/logic_play_phase.h"
#include "../../compiler/gui/gui_play_phase.h"
#include "../../compiler/graphics/gfx_play_phase.h"

namespace Game
{
    int CPlayPhase::InternOnEnter()
    {
        Logic::PlayPhase::GetInstance().OnEnter();
        Gui  ::PlayPhase::GetInstance().OnEnter();
        Gfx  ::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnLeave()
    {
        Logic::PlayPhase::GetInstance().OnLeave();
        Gui  ::PlayPhase::GetInstance().OnLeave();
        Gfx  ::PlayPhase::GetInstance().OnEnter();

        return 0;
    }

    int CPlayPhase::InternOnRun()
    {
        Logic::PlayPhase::GetInstance().OnRun();
        Gui  ::PlayPhase::GetInstance().OnRun();
        Gfx  ::PlayPhase::GetInstance().OnRun();

        return 0;
    }
}

