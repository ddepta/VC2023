
#include "game_application.h"

#include <assert.h>
#include "game_phase.h"
#include "game_startup_phase.h"
#include "game_load_phase.h"
#include "game_mainmenu_phase.h"
#include "game_play_phase.h"
#include "game_shutdown_phase.h"
#include "game_unload_phase.h"

#include <SFML/Graphics.hpp>

namespace Game
{
    CApplication::CApplication()
        : m_pPhases
          { 
              &CShutdownPhase  ::GetInstance(),
              &CStartupPhase   ::GetInstance(),
              &CLoadPhase      ::GetInstance(),
              &CMainMenuPhase  ::GetInstance(),
              &CPlayPhase      ::GetInstance(),
              &CUnloadPhase    ::GetInstance(),
          }
        , m_CurrentPhase(CPhase::Undefined)
    {
    }

    void CApplication::Startup()
    {
        sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }

    void CApplication::Run()
    {
    }

    void CApplication::Shutdown() 
    {
    }

    void CApplication::RunPhases()
    {
        CPhase* pCurrentPhase = m_pPhases[m_CurrentPhase];

        assert(pCurrentPhase != nullptr);

        CPhase::EPhase NextPhase = static_cast<CPhase::EPhase>(pCurrentPhase->OnRun());

        if (NextPhase != m_CurrentPhase)
        {
            pCurrentPhase->OnLeave();

            m_CurrentPhase = NextPhase;

            pCurrentPhase = m_pPhases[m_CurrentPhase];

            assert(pCurrentPhase != nullptr);
            
            pCurrentPhase->OnEnter();
        }
    }
}

int main()
{
    Game::CApplication& application = Game::CApplication::GetInstance();

    application.Startup();
    application.Run();
    application.Shutdown();
}