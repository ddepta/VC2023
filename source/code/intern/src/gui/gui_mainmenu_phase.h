#pragma once

namespace Gui
{
    class CMainMenuPhase
    {
    public:
        static CMainMenuPhase& GetInstance()
        {
            static CMainMenuPhase instance;
            return instance;
        };

        CMainMenuPhase(const CMainMenuPhase&) = delete;
        CMainMenuPhase& operator = (const CMainMenuPhase&) = delete;

    public:
        enum EMenuState
        {
            Start,
            Exit
        };

    public:
        void OnEnter();
        void OnRun();
        void OnLeave();

        EMenuState GetMenuState();
        void SetMenuState(EMenuState _MenuState);

    private:
        CMainMenuPhase() : m_MenuState(Start)
        {};

    private:
        EMenuState m_MenuState;
    };
}