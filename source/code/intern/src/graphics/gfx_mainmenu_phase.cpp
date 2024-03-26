#include "gfx_mainmenu_phase.h"
#include "game/game_application.h"

namespace Gfx
{
    void CMainMenuPhase::OnEnter()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();

        m_BackgroundTexture.loadFromFile("..\\resources\\images\\background.png");
        m_BackgroundTexture.setRepeated(true);

        sf::IntRect Rectangle(0, 0, 1000, 1000);
        sf::Vector2f Size = rApplication.m_Window.getView().getSize();

        m_BackgroundSprite = sf::Sprite(m_BackgroundTexture, Rectangle);
        m_BackgroundSprite.setPosition((float)Rectangle.left, (float)Rectangle.top - 1000.0f + Size.y);
    }

    void CMainMenuPhase::OnRun()
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();

        rApplication.m_Window.clear(sf::Color::Black);

        rApplication.m_Window.draw(m_BackgroundSprite);

        rApplication.m_Window.display();
    }

    void CMainMenuPhase::OnLeave()
    {}
}
