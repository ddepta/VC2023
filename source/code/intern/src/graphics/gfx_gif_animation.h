#ifndef __GFX_GIF_ANIMATION_H__
#define __GFX_GIF_ANIMATION_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>

namespace Gfx
{
    class CGifAnimation
    {
    public:
        CGifAnimation(const char* _pFilename);

        const sf::Vector2i& GetSize();
        void Update(sf::Sprite& _rSprite, bool _Animate);

    private:
        sf::Vector2i m_Size;
        sf::Clock m_Clock;
        sf::Time m_StartTime;
        sf::Time m_TotalDelay;
        std::vector<std::tuple<int, sf::Texture>> m_Frames;
        std::vector<std::tuple<int, sf::Texture>>::iterator m_FrameIter;
        bool m_Animate = false;
    };
}

#endif // __GFX_GIF_ANIMATION_H__