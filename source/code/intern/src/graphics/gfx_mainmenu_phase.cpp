#include "gfx_mainmenu_phase.h"
#include "game/game_application.h"
#include <SFML/Graphics/Text.hpp>

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();

        m_BackgroundTexture.loadFromFile("..\\resources\\images\\background.png");
        m_BackgroundTexture.setRepeated(true);

        sf::IntRect Rectangle(0, 0, 900, 600);
        sf::Vector2f Size = rApplication.m_Window.getView().getSize();

        m_BackgroundSprite = sf::Sprite(m_BackgroundTexture, Rectangle);
        m_BackgroundSprite.setPosition((float)Rectangle.left, (float)Rectangle.top - 600.0f + Size.y);
    }

    void CMainMenuPhase::OnRun()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();
        sf::Vector2f Size = rApplication.m_Window.getView().getSize();

        sf::Font Font;
        Font.loadFromFile("..\\resources\\font\\Berlin Sans FB Regular.ttf");

        sf::Color TextColor = sf::Color(191, 255, 191);
        sf::Color OutlineColor = sf::Color(10, 69, 0);

        sf::Text TitleText;

        TitleText.setString("Ostereier-Suche");
        TitleText.setCharacterSize(60);
        TitleText.setFillColor(TextColor);
        TitleText.setFont(Font);
        TitleText.setOutlineColor(OutlineColor);
        TitleText.setOutlineThickness(1.5f);
        TitleText.setPosition((Size.x - TitleText.getGlobalBounds().width) / 2, 120);

        sf::Text StartText;

        StartText.setString("Start (ENTER)");
        StartText.setCharacterSize(40);
        StartText.setFillColor(TextColor);
        StartText.setFont(Font);
        StartText.setOutlineColor(OutlineColor);
        StartText.setOutlineThickness(1.5f);
        StartText.setPosition((Size.x - StartText.getGlobalBounds().width) / 2, 250);

        sf::Text ExitText;

        ExitText.setString("Beenden (ESC)");
        ExitText.setCharacterSize(40);
        ExitText.setFillColor(TextColor);
        ExitText.setFont(Font);
        ExitText.setOutlineColor(OutlineColor);
        ExitText.setOutlineThickness(1.5f);
        ExitText.setPosition((Size.x - ExitText.getGlobalBounds().width) / 2, 300);

        sf::Text WASDText;

        WASDText.setString("W + A + S + D");
        WASDText.setCharacterSize(30);
        WASDText.setFillColor(TextColor);
        WASDText.setFont(Font);
        WASDText.setOutlineColor(OutlineColor);
        WASDText.setOutlineThickness(1.5f);
        WASDText.setPosition((Size.x - WASDText.getGlobalBounds().width) / 2, 450);

        sf::Text ArrowText;

        ArrowText.setString("Pfeiltasten");
        ArrowText.setCharacterSize(30);
        ArrowText.setFillColor(TextColor);
        ArrowText.setFont(Font);
        ArrowText.setOutlineColor(OutlineColor);
        ArrowText.setOutlineThickness(1.5f);
        ArrowText.setPosition((Size.x - ArrowText.getGlobalBounds().width) / 2, 500);

        rApplication.m_Window.clear(sf::Color::Black);

        rApplication.m_Window.draw(m_BackgroundSprite);
        rApplication.m_Window.draw(TitleText);
        rApplication.m_Window.draw(StartText);
        rApplication.m_Window.draw(ExitText);
        rApplication.m_Window.draw(WASDText);
        rApplication.m_Window.draw(ArrowText);

        rApplication.m_Window.display();
    }

    void CMainMenuPhase::OnLeave()
    {}
}
