#pragma once
#include "game_phase.h"

namespace Game
{
    class CUnloadPhase : public CPhase
    {
        public:
            static CUnloadPhase& GetInstance()
            {
                static CUnloadPhase instance;
                return instance;
            };

            CUnloadPhase(const CUnloadPhase&) = delete;
            CUnloadPhase& operator = (const CUnloadPhase&) = delete;

        private:
            CUnloadPhase() {};

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;
        };
}