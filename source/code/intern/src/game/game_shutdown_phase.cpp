#include "game_shutdown_phase.h"
#include "data/data_shutdown_phase.h"
#include "logic/logic_shutdown_phase.h"
#include "gui/gui_shutdown_phase.h"
#include "graphics/gfx_shutdown_phase.h"

namespace Game
{
    int CShutdownPhase::InternOnEnter()
    {
        Data ::CShutdownPhase::GetInstance().OnEnter();
        Logic::CShutdownPhase::GetInstance().OnEnter();
        Gui  ::CShutdownPhase::GetInstance().OnEnter();
        Gfx  ::CShutdownPhase::GetInstance().OnEnter();

        return 0;
    }

    int CShutdownPhase::InternOnRun()
    {
        Data ::CShutdownPhase::GetInstance().OnRun();
        Logic::CShutdownPhase::GetInstance().OnRun();
        Gui  ::CShutdownPhase::GetInstance().OnRun();
        Gfx  ::CShutdownPhase::GetInstance().OnRun();

        return EPhase::Undefined;
    }

    int CShutdownPhase::InternOnLeave()
    {
        Data ::CShutdownPhase::GetInstance().OnLeave();
        Logic::CShutdownPhase::GetInstance().OnLeave();
        Gui  ::CShutdownPhase::GetInstance().OnLeave();
        Gfx  ::CShutdownPhase::GetInstance().OnLeave();

        return 0;
    }
}
