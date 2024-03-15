
#include "game_play_phase.h"

#include "../../src/logic/logic_play_phase.h"
#include "../../src/gui/gui_play_phase.h"
#include "../../src/graphics/gfx_play_phase.h"

namespace Game
{
    int CPlayPhase::InternOnEnter()
    {
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
        Logic::CPlayPhase::GetInstance().OnRun();
        Gui  ::CPlayPhase::GetInstance().OnRun();
        Gfx  ::CPlayPhase::GetInstance().OnRun();

        return 0;
    }
}

