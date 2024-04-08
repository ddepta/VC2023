#include "gfx_play_phase.h"
#include "game/game_application.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "data/data_meta_entity_system.h"
#include "data/data_entity.h"
#include "data/data_entity_system.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Gfx
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();

        rApplication.m_Window.clear(sf::Color::Black);

        for (Data::CEntity* pEntity : Data::CEntitySystem::GetInstance().GetAllEntities())
        {
            if (pEntity != nullptr)
            {
                if (pEntity->m_pMetaEntity->m_Name == "player")
                {
                    sf::Vector2f Size = rApplication.m_Window.getView().getSize();

                    sf::View View = rApplication.m_Window.getView();
                    float X = pEntity->m_Position[0];
                    float Y = pEntity->m_Position[1];

                    View.setCenter(X, Y);

                    rApplication.m_Window.setView(View);
                }

                sf::Texture* pTexture = static_cast<sf::Texture*>(pEntity->m_pMetaEntity->m_Facets[Data::CMetaEntity::SFacetType::GraphicsFacet]);
                assert(pTexture != nullptr);

                sf::Sprite Sprite(*pTexture);
                Sprite.setPosition(pEntity->m_Position[0], pEntity->m_Position[1]);

                rApplication.m_Window.draw(Sprite);
            }
        }

        rApplication.m_Window.display();
    }

    void CPlayPhase::OnLeave() {}
}