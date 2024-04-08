#pragma once

#include "data_entity.h"

namespace Data 
{
    class CPlayerSystem 
    {
    public:
        static CPlayerSystem& GetInstance()
        {
            static CPlayerSystem instance;
            return instance;
        };

        CPlayerSystem(const CPlayerSystem&) = delete;
        CPlayerSystem& operator = (const CPlayerSystem&) = delete;

    public:
        CEntity* GetPlayer();
        void SetPlayer(CEntity* m_pPlayer);

    private:
        CPlayerSystem() : m_pPlayer(nullptr)
        {};

    private:
        CEntity* m_pPlayer;
    };
}