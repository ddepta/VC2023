#include "gfx_mainmenu_phase.h"
#include "game/game_application.h"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {}

    void CMainMenuPhase::OnRun()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();
        sf::Vector2f ViewSize = rApplication.m_Window.getView().getSize();
        sf::Vector2u WindowSize = rApplication.m_Window.getSize();

        sf::Texture BackgroundTexture;

        BackgroundTexture.loadFromFile("..\\resources\\images\\pattern.png");
        BackgroundTexture.setRepeated(true);

        std::cout << rApplication.m_Window.getSize().x << "\n";

        sf::IntRect Position(0, 0, WindowSize.x, WindowSize.y);
        sf::FloatRect ViewPort(0.0f, 0.0f, WindowSize.x, WindowSize.y);

        rApplication.m_Window.setView(sf::View(ViewPort));

        sf::Sprite BackgroundSprite = sf::Sprite(BackgroundTexture, Position);
        BackgroundSprite.setPosition((float)Position.left, (float)Position.top);

        rApplication.m_Window.clear(sf::Color::Black);

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
        TitleText.setPosition((ViewSize.x - TitleText.getGlobalBounds().width) / 2, 120);

        sf::Text StartText;

        StartText.setString("Start (ENTER)");
        StartText.setCharacterSize(40);
        StartText.setFillColor(TextColor);
        StartText.setFont(Font);
        StartText.setOutlineColor(OutlineColor);
        StartText.setOutlineThickness(1.5f);
        StartText.setPosition((ViewSize.x - StartText.getGlobalBounds().width) / 2, 250);

        sf::Text ExitText;

        ExitText.setString("Beenden (ESC)");
        ExitText.setCharacterSize(40);
        ExitText.setFillColor(TextColor);
        ExitText.setFont(Font);
        ExitText.setOutlineColor(OutlineColor);
        ExitText.setOutlineThickness(1.5f);
        ExitText.setPosition((ViewSize.x - ExitText.getGlobalBounds().width) / 2, 300);

        sf::Text WASDText;

        WASDText.setString("W + A + S + D");
        WASDText.setCharacterSize(30);
        WASDText.setFillColor(TextColor);
        WASDText.setFont(Font);
        WASDText.setOutlineColor(OutlineColor);
        WASDText.setOutlineThickness(1.5f);
        WASDText.setPosition((ViewSize.x - WASDText.getGlobalBounds().width) / 2, 450);

        sf::Text ArrowText;

        ArrowText.setString("Pfeiltasten");
        ArrowText.setCharacterSize(30);
        ArrowText.setFillColor(TextColor);
        ArrowText.setFont(Font);
        ArrowText.setOutlineColor(OutlineColor);
        ArrowText.setOutlineThickness(1.5f);
        ArrowText.setPosition((ViewSize.x - ArrowText.getGlobalBounds().width) / 2, 500);

        rApplication.m_Window.clear(sf::Color::Black);

        rApplication.m_Window.draw(BackgroundSprite);
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
