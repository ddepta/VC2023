
#pragma once

#include "game_phase.h"
#include "../data/data_event.h"

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

    public:
        static void Finish(Data::CEvent& _rEvent);
        static void Exit(Data::CEvent& _rEvent);

    private:
        CPlayPhase() : nextRunPhase(CPhase::Play) {};

    private:
        int InternOnEnter() override;
        int InternOnLeave() override;
        int InternOnRun() override;

    private:
        CPhase::EPhase nextRunPhase;
    };
}