
#pragma once

#include "game_phase.h"

#include <array>

namespace Game
{
    class CApplication
    {
        private:

            // Old School: CPhase* m_pPhases[CPhase::NumberOfMembers];

            std::array<CPhase*, CPhase::NumberOfMembers> m_pPhases;
            CPhase::EPhase                               m_CurrentPhase;

        private:

            CApplication();

            void Run();

        private:

            void RunPhases();
    };
}
