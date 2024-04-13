#include "gfx_play_phase.h"
#include "game/game_application.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "data/data_meta_entity_system.h"
#include "data/data_entity.h"
#include "data/data_entity_system.h"
#include "data/data_score_system.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace Gfx
{
    void CPlayPhase::OnEnter() {}

    void CPlayPhase::OnRun() 
    {
        Game::CApplication& rApplication = Game::CApplication::GetInstance();
        rApplication.m_Window.clear(sf::Color::Black);

        sf::View View = rApplication.m_Window.getView();
        sf::Vector2f Size = rApplication.m_Window.getView().getSize();

        sf::Texture BackgroundTexture;
        BackgroundTexture.loadFromFile("..\\resources\\images\\gras.png");
        BackgroundTexture.setRepeated(true);

        sf::Sprite BackgroundSprite;

        sf::IntRect Rectangle(0, 0, 2624, 2624);

        BackgroundSprite = sf::Sprite(BackgroundTexture, Rectangle);
        BackgroundSprite.setPosition((float)Rectangle.left, (float)Rectangle.top - 600.0f + Size.y);

        rApplication.m_Window.draw(BackgroundSprite);

        sf::Font Font;
        Font.loadFromFile("..\\resources\\font\\Berlin Sans FB Regular.ttf");

        sf::Color OutlineColor = sf::Color(10, 69, 0);

        std::string Score = std::to_string(Data::CScoreSystem::GetInstance().GetScore());
        std::string MaxScore = std::to_string(Data::CScoreSystem::GetInstance().GetMaxScore());

        sf::Text ScoreLabelText;

        ScoreLabelText.setString("Ostereier:   /" + MaxScore);
        ScoreLabelText.setCharacterSize(30);
        ScoreLabelText.setFillColor(sf::Color(191, 255, 191));
        ScoreLabelText.setFont(Font);
        ScoreLabelText.setOutlineColor(OutlineColor);
        ScoreLabelText.setOutlineThickness(1.5f);

        sf::Text ScoreText;

        ScoreText.setString(Score);
        ScoreText.setCharacterSize(30);
        ScoreText.setFillColor(sf::Color(42, 255, 42));
        ScoreText.setFont(Font);
        ScoreText.setOutlineColor(OutlineColor);
        ScoreText.setOutlineThickness(1.5f);
        ScoreText.setStyle(sf::Text::Bold);

        for (Data::CEntity* pEntity : Data::CEntitySystem::GetInstance().GetAllEntities())
        {
            if (pEntity != nullptr)
            {
                if (pEntity->m_pMetaEntity->m_Name == "player")
                {
                    sf::Vector2f Size = rApplication.m_Window.getView().getSize();

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

        auto XPosition = View.getCenter().x - Size.x / 2 + 10.0f;
        auto YPosition = View.getCenter().y - Size.y / 2 + 3.0f;

        ScoreLabelText.setPosition(XPosition, YPosition);
        ScoreText.setPosition(XPosition + 145.0f - ScoreText.getGlobalBounds().width, YPosition);

        rApplication.m_Window.draw(ScoreLabelText);
        rApplication.m_Window.draw(ScoreText);

        rApplication.m_Window.display();
    }

    void CPlayPhase::OnLeave() {}
}