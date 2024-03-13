#include "game_load_phase.h"

namespace Game
{
    int CLoadPhase::InternOnEnter()
    {
        return 0;
    }

    int CLoadPhase::InternOnRun()
    {
        return EPhase::Play;
    }

    int CLoadPhase::InternOnLeave()
    {
        return 0;
    }
}
