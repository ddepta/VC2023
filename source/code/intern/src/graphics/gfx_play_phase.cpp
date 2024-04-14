#include "gfx_play_phase.h"
#include "gfx_gif_animation.h"
#include "game/game_application.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "data/data_meta_entity_system.h"
#include "data/data_entity.h"
#include "data/data_entity_system.h"
#include "data/data_score_system.h"
#include "data/data_player_system.h"
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

        sf::Vector2f ViewSize = rApplication.m_Window.getView().getSize();
        sf::Vector2u WindowSize = rApplication.m_Window.getSize();

        // Rescale View to window size
        // Zoom view, so the view size stays the same
        View.setSize(WindowSize.x, WindowSize.y);
        float ScaleFactor = std::min((float) 1600 / WindowSize.x, (float) 900 / WindowSize.y);
        View.zoom(ScaleFactor * 0.55);

        sf::Texture BackgroundTexture;
        BackgroundTexture.loadFromFile("..\\resources\\images\\gras.png");
        BackgroundTexture.setRepeated(true);

        sf::Sprite BackgroundSprite;

        sf::IntRect Rectangle(0, 0, 2624, 2624);

        BackgroundSprite = sf::Sprite(BackgroundTexture, Rectangle);
        BackgroundSprite.setPosition((float)Rectangle.left, (float)Rectangle.top);

        rApplication.m_Window.draw(BackgroundSprite);

        Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();

        sf::Sprite PlayerGifSprite;

        bool AnimatePlayer = rPlayerSystem.GetPlayerAnimationState();

        //if (AnimatePlayer)
        //{
        //    std::cout << "animate sent --- ";
        //}
        m_PlayerGif.update(PlayerGifSprite, AnimatePlayer);


        //std::cout << "\n";
        if (AnimatePlayer)
        {
            rPlayerSystem.SetPlayerAnimationState(false);
        }

        for (Data::CEntity* pEntity : Data::CEntitySystem::GetInstance().GetAllEntities())
        {
            if (pEntity != nullptr)
            {
                sf::Texture* pTexture = static_cast<sf::Texture*>(pEntity->m_pMetaEntity->m_Facets[Data::CMetaEntity::SFacetType::GraphicsFacet]);
                assert(pTexture != nullptr);

                sf::Sprite Sprite(*pTexture);
                Sprite.setPosition(pEntity->m_Position[0], pEntity->m_Position[1]);

                if (pEntity->m_pMetaEntity->m_Name == "player")
                {
                    Sprite = PlayerGifSprite;
                    Sprite.setPosition(pEntity->m_Position[0], pEntity->m_Position[1]);
                    float X = pEntity->m_Position[0];
                    float Y = pEntity->m_Position[1];

                    View.setCenter(X, Y);

                    rApplication.m_Window.setView(View);

                    if (rPlayerSystem.GetPlayerDirection() == Data::CPlayerSystem::Right)
                    {
                        Sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
                    }
                    else
                    {
                        Sprite.setTextureRect(sf::IntRect(64, 0, -64, 64));
                    }
                }

                rApplication.m_Window.draw(Sprite);
            }
        }

        sf::Font Font;
        Font.loadFromFile("..\\resources\\font\\Minecraft.otf");

        sf::Color OutlineColor = sf::Color(10, 69, 0);

        std::string Score = std::to_string(Data::CScoreSystem::GetInstance().GetScore());
        std::string MaxScore = std::to_string(Data::CScoreSystem::GetInstance().GetMaxScore());

        sf::Text ScoreLabelText;

        ScoreLabelText.setString("Ostereier:   /" + MaxScore);
        ScoreLabelText.setCharacterSize(20);
        ScoreLabelText.setFillColor(sf::Color(191, 255, 191));
        ScoreLabelText.setFont(Font);
        ScoreLabelText.setOutlineColor(OutlineColor);
        ScoreLabelText.setOutlineThickness(1.5f);

        sf::Text ScoreText;

        ScoreText.setString(Score);
        ScoreText.setCharacterSize(20);
        ScoreText.setFillColor(sf::Color(42, 255, 42));
        ScoreText.setFont(Font);
        ScoreText.setOutlineColor(OutlineColor);
        ScoreText.setOutlineThickness(1.5f);
        ScoreText.setStyle(sf::Text::Bold);

        auto XPosition = View.getCenter().x - ViewSize.x / 2 + 10.0f;
        auto YPosition = View.getCenter().y - ViewSize.y / 2 + 3.0f;

        ScoreLabelText.setPosition(XPosition, YPosition);
        ScoreText.setPosition(XPosition + 107.0f, YPosition);

        rApplication.m_Window.draw(ScoreLabelText);
        rApplication.m_Window.draw(ScoreText);

        rApplication.m_Window.display();
    }

    void CPlayPhase::OnLeave() {}
}