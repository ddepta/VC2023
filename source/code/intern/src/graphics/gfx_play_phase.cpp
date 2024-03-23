#include "gfx_play_phase.h"
#include "game/game_application.h"
#include <SFML/Graphics/CircleShape.hpp>

namespace Gfx
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        Game::CApplication& rInstance = Game::CApplication::GetInstance();

        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        rInstance.m_Window.draw(shape);
        rInstance.m_Window.display();
    }

    void CPlayPhase::OnLeave() {}
}