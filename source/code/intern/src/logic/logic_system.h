#pragma once

#include "../core/core_vector.h"

namespace Logic
{
    class CSystem
    {
    public:
        static CSystem& GetInstance()
        {
            static CSystem instance;
            return instance;
        };

        CSystem(const CSystem&) = delete;
        CSystem& operator = (const CSystem&) = delete;

    public:
        void HandleInput();

    private:
        void MovePlayer(Core::Float2 _Direction, int _LookDirection);

    private:
        CSystem()
        {};
    };
}