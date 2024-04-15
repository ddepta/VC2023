#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Gfx
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
        void OnEnter();
        void OnRun();
        void OnLeave();

    public:
        struct SSplash
        {
            std::vector<std::string> m_SplashTexts;
            std::string m_CurrentSplashText;
            float m_TextScale = 1.0f;
            bool m_Growing = false;

            SSplash() = default;

            void GenerateRandomSplashText();
            std::string GetCurrentSplashText();
        };

    public:
        SSplash m_Splash;

    private:
        void HandleSplashPulsation();

    private:
        CMainMenuPhase()
        {
            m_Splash.m_SplashTexts.push_back("the cake is a lie");
            m_Splash.m_SplashTexts.push_back("Eggsciting!");
            m_Splash.m_SplashTexts.push_back("Eggsclusive!");
            m_Splash.m_SplashTexts.push_back("Easter Eggs!");
            m_Splash.m_SplashTexts.push_back("Uses SFML!");
            m_Splash.m_SplashTexts.push_back("Keyboard compatible!");
            m_Splash.m_SplashTexts.push_back("Praise the sun!");
            m_Splash.m_SplashTexts.push_back("Do a barrel roll!");
            m_Splash.m_SplashTexts.push_back("It's a-me, Mario!");
            m_Splash.m_SplashTexts.push_back("Hey! Listen!");
            m_Splash.m_SplashTexts.push_back("C-C-C-COMBO BREAKER!");
            m_Splash.m_SplashTexts.push_back("LEEEEEROY JENKINSSS");
        };
    };
}