#pragma once
#include "game_phase.h"

namespace Game
{
    class CMainMenuPhase : public CPhase
    {
        public:
            static CMainMenuPhase& GetInstance()
            {
                static CMainMenuPhase instance;
                return instance;
            };

            CMainMenuPhase(CMainMenuPhase const&) = delete;
            CMainMenuPhase& operator=(CMainMenuPhase const&) = delete;

        private:
            CMainMenuPhase() :
                nextRunPhase(CPhase::MainMenu)
            {};

        private:
            CPhase::EPhase nextRunPhase;

        private:
            int InternOnEnter() override;
            int InternOnRun() override;
            int InternOnLeave() override;
    };
}