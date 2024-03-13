
#pragma once

#include "game_phase.h"

namespace Game
{
    class CPlayPhase : public CPhase
    {
        public:
            static CPlayPhase& GetInstance()
            {
                static CPlayPhase instance;
                return instance;
            };

            CPlayPhase(const CPlayPhase&) = delete;
            CPlayPhase& operator = (const CPlayPhase&) = delete;
        private:
            CPlayPhase() :
                nextRunPhase(CPhase::Play)
            {};

        private:
            int InternOnEnter() override;
            int InternOnLeave() override;
            int InternOnRun() override;

        private:
            CPhase::EPhase nextRunPhase;
    };
}