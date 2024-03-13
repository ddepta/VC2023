#include "game_unload_phase.h"

namespace Game
{
    int CUnloadPhase::InternOnEnter()
    {
        return 0;
    }

    int CUnloadPhase::InternOnRun()
    {
        return EPhase::MainMenu;
    }

    int CUnloadPhase::InternOnLeave()
    {
        return 0;
    }
}
