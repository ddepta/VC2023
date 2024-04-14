#include "gfx_mainmenu_phase.h"
#include "game/game_application.h"
#include "gui/gui_mainmenu_phase.h"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {}

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
        TitleSprite.setPosition((ViewSize.x - TitleSprite.getGlobalBounds().width) / 2, WindowSize.y / 10);

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

        rApplication.m_Window.display();
    }

    void CMainMenuPhase::OnLeave()
    {}
}
