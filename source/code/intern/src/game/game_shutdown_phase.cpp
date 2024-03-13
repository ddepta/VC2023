#include "game_shutdown_phase.h"

namespace Game
{
    int CShutdownPhase::InternOnEnter()
    {
        return 0;
    }

    int CShutdownPhase::InternOnRun()
    {
        return EPhase::Undefined;
    }

    int CShutdownPhase::InternOnLeave()
    {
        return 0;
    }
}
