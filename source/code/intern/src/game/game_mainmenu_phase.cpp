#include "game_mainmenu_phase.h"

namespace Game
{
    int CMainMenuPhase::InternOnEnter()
    {
        return 0;
    }

    int CMainMenuPhase::InternOnRun()
    {
        return nextRunPhase;
    }

    int CMainMenuPhase::InternOnLeave()
    {
        return 0;
    }
}
