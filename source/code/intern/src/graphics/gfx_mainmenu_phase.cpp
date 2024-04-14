#include "gfx_mainmenu_phase.h"
#include "game/game_application.h"
#include "gui/gui_mainmenu_phase.h"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {
        m_Splash.GenerateRandomSplashText();
    }

    void CMainMenuPhase::OnRun()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();

        rApplication.m_Window.clear(sf::Color::Black);

        sf::View View = rApplication.m_Window.getView();
        sf::Vector2f ViewSize = rApplication.m_Window.getView().getSize();
        sf::Vector2u WindowSize = rApplication.m_Window.getSize();

        sf::Font Font;
        Font.loadFromFile("..\\resources\\font\\Minecraft.otf");

        sf::Color TextColor = sf::Color(255, 255, 255);
        sf::Color SplashColor = sf::Color(255, 255, 0);

        // Scale viewport when resizing
        sf::FloatRect ViewPort(0.0f, 0.0f, WindowSize.x, WindowSize.y);

        rApplication.m_Window.setView(sf::View(ViewPort));

        // Calculate the proportional scaling for textures
        float MaxScaleFactor = std::max((float)WindowSize.x / 1600, (float)WindowSize.y / 900);
        float MinScaleFactor = std::min((float)WindowSize.x / 1600, (float)WindowSize.y / 900);

        sf::Texture BackgroundTexture;

        BackgroundTexture.loadFromFile("..\\resources\\images\\background_new.png");

        sf::Sprite BackgroundSprite(BackgroundTexture);
        BackgroundSprite.setPosition(0, 0);
        BackgroundSprite.setScale(MaxScaleFactor, MaxScaleFactor);

        sf::Texture TitleTexture;

        TitleTexture.loadFromFile("..\\resources\\images\\title.png");


        sf::Sprite TitleSprite(TitleTexture);
        TitleSprite.setScale(MinScaleFactor, MinScaleFactor);

        float TitlePositionX = (ViewSize.x - TitleSprite.getGlobalBounds().width) / 2;
        float TitlePositionY = WindowSize.y / 10;

        TitleSprite.setPosition(TitlePositionX, TitlePositionY);

        sf::Texture MenuTexture;

        if (Gui::CMainMenuPhase::GetInstance().GetMenuState() == Gui::CMainMenuPhase::Start)
        {
            MenuTexture.loadFromFile("..\\resources\\images\\menu_start.png");
        }
        else
        {
            MenuTexture.loadFromFile("..\\resources\\images\\menu_exit.png");
        }

        sf::Sprite MenuSprite(MenuTexture);
        //std::cout << "menusprite: " << MenuSprite.getGlobalBounds().width;
        MenuSprite.setScale(MinScaleFactor, MinScaleFactor);
        //std::cout << "menusprite: " << MenuSprite.getGlobalBounds().width << "\n";
        MenuSprite.setPosition((ViewSize.x - (MenuSprite.getGlobalBounds().width - (115 * MinScaleFactor))) / 2, (ViewSize.y - (MenuSprite.getGlobalBounds().height - (28 * MinScaleFactor))) / 2);

        sf::Texture ControlsTexture;

        ControlsTexture.loadFromFile("..\\resources\\images\\controls.png");

        sf::Sprite ControlsSprite(ControlsTexture);
        //std::cout << "menusprite: " << ControlsSprite.getGlobalBounds().width;
        ControlsSprite.setScale(MinScaleFactor, MinScaleFactor);
        //std::cout << "ControlsSprite: " << ControlsSprite.getGlobalBounds().width << "\n";
        ControlsSprite.setPosition((ViewSize.x - ControlsSprite.getGlobalBounds().width) / 2, (ViewSize.y - ControlsSprite.getGlobalBounds().height) / 1.1);

        sf::Text VersionText;

        VersionText.setString("Ostereiersuche 1.21");
        VersionText.setCharacterSize(30);
        VersionText.setFillColor(TextColor);
        VersionText.setFont(Font);
        VersionText.setPosition(10, (ViewSize.y - VersionText.getGlobalBounds().height - 20));

        sf::Text SplashText;

        SplashText.setString(m_Splash.GetCurrentSplashText());
        SplashText.setCharacterSize(50);
        SplashText.setFillColor(SplashColor);
        SplashText.setFont(Font);
        SplashText.setOutlineColor(sf::Color::Black);
        SplashText.setOutlineThickness(2.0f);
        SplashText.setRotation(-20.0f);

        if (m_Splash.m_Growing)
        {
            m_Splash.m_TextScale += 0.01f;
        }
        else
        {
            m_Splash.m_TextScale -= 0.01;
        }

        if (m_Splash.m_TextScale < 0.95f)
        {
            m_Splash.m_Growing = true;
        }
        if (m_Splash.m_TextScale >= 1.0f)
        {
            m_Splash.m_Growing = false;
        }

        SplashText.setScale(MinScaleFactor * m_Splash.m_TextScale, MinScaleFactor * m_Splash.m_TextScale);
        SplashText.setPosition(TitlePositionX + (800 * MinScaleFactor) - (SplashText.getGlobalBounds().width / 2), TitlePositionY + (150 * MinScaleFactor));

        sf::Text NameText;

        NameText.setString("Daniel Depta - FH Erfurt");
        NameText.setCharacterSize(30);
        NameText.setFillColor(TextColor);
        NameText.setFont(Font);
        NameText.setPosition(ViewSize.x - NameText.getGlobalBounds().width - 10, (ViewSize.y - VersionText.getGlobalBounds().height - 20));

        rApplication.m_Window.clear(sf::Color::Black);

        rApplication.m_Window.draw(BackgroundSprite);
        rApplication.m_Window.draw(TitleSprite);
        rApplication.m_Window.draw(MenuSprite);
        rApplication.m_Window.draw(ControlsSprite);
        rApplication.m_Window.draw(VersionText);
        rApplication.m_Window.draw(NameText);
        rApplication.m_Window.draw(SplashText);

        rApplication.m_Window.display();
    }

    void CMainMenuPhase::OnLeave()
    {}

    void CMainMenuPhase::SSplash::GenerateRandomSplashText()
    {
        int RandomPosition = std::rand() % m_SplashTexts.size();
        
        m_CurrentSplashText = m_SplashTexts[RandomPosition];
    }

    std::string CMainMenuPhase::SSplash::GetCurrentSplashText()
    {
        return m_CurrentSplashText;
    }
}
