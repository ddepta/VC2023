#include "game_unload_phase.h"
#include "data/data_unload_phase.h"
#include "logic/logic_unload_phase.h"
#include "gui/gui_unload_phase.h"
#include "graphics/gfx_unload_phase.h"

namespace Game
{
    int CUnloadPhase::InternOnEnter()
    {
        Data ::CUnloadPhase::GetInstance().OnEnter();
        Logic::CUnloadPhase::GetInstance().OnEnter();
        Gui  ::CUnloadPhase::GetInstance().OnEnter();
        Gfx  ::CUnloadPhase::GetInstance().OnEnter();

        return 0;
    }

    int CUnloadPhase::InternOnRun()
    {
        Data ::CUnloadPhase::GetInstance().OnRun();
        Logic::CUnloadPhase::GetInstance().OnRun();
        Gui  ::CUnloadPhase::GetInstance().OnRun();
        Gfx  ::CUnloadPhase::GetInstance().OnRun();

        return EPhase::MainMenu;
    }

    int CUnloadPhase::InternOnLeave()
    {
        Data ::CUnloadPhase::GetInstance().OnLeave();
        Logic::CUnloadPhase::GetInstance().OnLeave();
        Gui  ::CUnloadPhase::GetInstance().OnLeave();
        Gfx  ::CUnloadPhase::GetInstance().OnLeave();

        return 0;
    }
}
