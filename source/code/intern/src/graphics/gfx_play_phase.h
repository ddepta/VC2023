#pragma once

#include "gfx_gif_animation.h"

namespace Gfx
{
    class CPlayPhase
    {
        public:
            static CPlayPhase& GetInstance()
            {
                static CPlayPhase instance;
                return instance;
            };

            CPlayPhase(const CPlayPhase&) = delete;
            CPlayPhase& operator = (const CPlayPhase&) = delete;

        public:
            void OnEnter();
            void OnRun();
            void OnLeave();

            AnimatedGIF m_PlayerGif;

        private:
            CPlayPhase() : m_PlayerGif("..\\resources\\textures\\player.gif"){};
        };
}