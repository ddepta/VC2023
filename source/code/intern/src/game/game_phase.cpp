
#include "game_phase.h"

namespace Game
{
    int CPhase::OnEnter()
    {
        return InternOnEnter();
    }

    int CPhase::OnLeave()
    {
        return InternOnLeave();
    }

    int CPhase::OnRun()
    {
        return InternOnRun();
    }
}

