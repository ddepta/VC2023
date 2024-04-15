
#include "game_application.h"

#include "game_phase.h"
#include "game_startup_phase.h"
#include "game_load_phase.h"
#include "game_mainmenu_phase.h"
#include "game_play_phase.h"
#include "game_shutdown_phase.h"
#include "game_unload_phase.h"
#include "data/data_event_system.h"

#include <assert.h>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
    CApplication::CApplication()
        : m_pPhases
          { 
              &CStartupPhase   ::GetInstance(),
              &CMainMenuPhase  ::GetInstance(),
              &CLoadPhase      ::GetInstance(),
              &CPlayPhase      ::GetInstance(),
              &CUnloadPhase    ::GetInstance(),
              &CShutdownPhase  ::GetInstance(),
          }
        , m_CurrentPhase(CPhase::Undefined)
    {
    }

    void CApplication::Startup()
    {
        // -----------------------------------------------------------------------------
        // Create the game window
        // -----------------------------------------------------------------------------
        m_Window.create(sf::VideoMode(1600, 900), "Visual Computing - Daniel Depta");

        m_CurrentPhase = CPhase::Startup;

        m_pPhases[m_CurrentPhase]->OnEnter();
    }

    void CApplication::Run()
    {
        sf::Event event;
        bool Running = true;

        // -----------------------------------------------------------------------------
        // Game loop
        // -----------------------------------------------------------------------------
        while(Running)
        {
            if (m_Window.isOpen() == false)
            {
                break;
            }

            while (m_Window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    m_Window.close();
                }

                // -----------------------------------------------------------------------------
                // Event (input) handling
                // Fires a event for each input
                // -----------------------------------------------------------------------------
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Key::Escape)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::EscapePressed);
                    }
                    else if (event.key.code == sf::Keyboard::Key::Enter)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::EnterPressed);
                    }
                    else if (event.key.code == sf::Keyboard::Key::Up || event.key.code == sf::Keyboard::Key::W)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::UpPressed);
                    }
                    else if (event.key.code == sf::Keyboard::Key::Down || event.key.code == sf::Keyboard::Key::S)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::DownPressed);
                    }
                    else if (event.key.code == sf::Keyboard::Key::Left || event.key.code == sf::Keyboard::Key::A)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::LeftPressed);
                    }
                    else if (event.key.code == sf::Keyboard::Key::Right || event.key.code == sf::Keyboard::Key::D)
                    {
                        Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::DispatchInput, Data::SEventType::RightPressed);
                    }
                }
            }

            Running = RunPhases();
        }
    }

    void CApplication::Shutdown() 
    {
    }

    bool CApplication::RunPhases()
    {
        CPhase* pCurrentPhase = m_pPhases[m_CurrentPhase];

        assert(pCurrentPhase != nullptr);

        CPhase::EPhase NextPhase = static_cast<CPhase::EPhase>(pCurrentPhase->OnRun());

        if (NextPhase != m_CurrentPhase)
        {
            pCurrentPhase->OnLeave();

            // -----------------------------------------------------------------------------
            // exit the while-loop when shutting down
            // -----------------------------------------------------------------------------
            if (m_CurrentPhase == CPhase::Shutdown)
            {
                return false;
            }

            m_CurrentPhase = NextPhase;

            pCurrentPhase = m_pPhases[m_CurrentPhase];

            assert(pCurrentPhase != nullptr);
            
            pCurrentPhase->OnEnter();
        }

        return true;
    }
}

int main()
{
    Game::CApplication& rApplication = Game::CApplication::GetInstance();

    // -----------------------------------------------------------------------------
    // Startup
    // -----------------------------------------------------------------------------
    try
    {
        rApplication.Startup();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Failed to start" << std::endl;
    }

    // -----------------------------------------------------------------------------
    // Running
    // -----------------------------------------------------------------------------
    try
    {
        rApplication.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Failed to run" << std::endl;
    }

    // -----------------------------------------------------------------------------
    // Shutdown
    // -----------------------------------------------------------------------------
    try
    {
        rApplication.Shutdown();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Failed to shutdown" << std::endl;
    }

    return 0;
}