#pragma once
#include "game_phase.h"
#include "data/data_event.h"

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

    public:
        static void OnStart(Data::CEvent& _rEvent);
        static void OnExit(Data::CEvent& _rEvent);
        static void DispatchInput(Data::CEvent& _rEvent);
        static void OnDown(Data::CEvent& _rEvent);
        static void OnUp(Data::CEvent& _rEvent);

    private:
        CMainMenuPhase() : m_NextRunPhase(CPhase::MainMenu) {};

    private:
        CPhase::EPhase m_NextRunPhase;

    private:
        int InternOnEnter() override;
        int InternOnRun() override;
        int InternOnLeave() override;
    };
}