#include "gfx_gif_animation.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_GIF
#include <stb_image.h>
#include <iostream>

namespace Gfx
{
    CGifAnimation::CGifAnimation(const char* _pFilename)
    {
        FILE* pFile = stbi__fopen(_pFilename, "rb");
        stbi__context Context;
        stbi__start_file(&Context, pFile);

        int* pDelays = nullptr;
        int Z = 0, Comp = 0;

        void* pPixels = stbi__load_gif_main(&Context, &pDelays, &m_Size.x, &m_Size.y, &Z, &Comp, STBI_rgb_alpha);

        sf::Image Image;
        int Step = m_Size.x * m_Size.y * 4;

        for (int Index = 0; Index < Z; Index++)
        {
            Image.create(m_Size.x, m_Size.y, (const sf::Uint8*)pPixels + Step * Index);

            sf::Texture Texture;
            Texture.loadFromImage(Image);

            m_Frames.push_back(std::tuple<int, sf::Texture>(pDelays[Index], Texture));
        }

        m_FrameIter = m_Frames.begin();

        stbi_image_free(pPixels);

        if (pDelays)
        {
            stbi_image_free(pDelays);
        }

        fclose(pFile);

        m_TotalDelay = sf::Time::Zero;
        m_StartTime = m_Clock.getElapsedTime();
    }

    const sf::Vector2i& CGifAnimation::GetSize()
    {
        return m_Size;
    }

    void CGifAnimation::Update(sf::Sprite& _rSprite, bool _Animate)
    {
        sf::Time Delay = sf::milliseconds(std::get<0>(*m_FrameIter));

        if (_Animate)
        {
            m_Animate = true;
        }

        while (m_StartTime + m_TotalDelay + Delay < m_Clock.getElapsedTime())
        {
            m_FrameIter++;
            if (m_FrameIter == m_Frames.end())
            {
                m_Animate = false;
                m_FrameIter = m_Frames.begin();
            }
            m_TotalDelay += Delay;
            Delay = sf::milliseconds(std::get<0>(*m_FrameIter));
        }

        if (!m_Animate)
        {
            m_FrameIter = m_Frames.begin();
        }

        sf::Texture& rTexture = std::get<1>(*m_FrameIter);
        _rSprite.setTexture(rTexture);
    }
}