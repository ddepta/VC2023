#include "game_startup_phase.h"

namespace Game
{
    int CStartupPhase::InternOnEnter()
    {
        return 0;
    }

    int CStartupPhase::InternOnRun()
    {
        return EPhase::MainMenu;
    }

    int CStartupPhase::InternOnLeave()
    {
        return 0;
    }
}