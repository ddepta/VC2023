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
        enum EDirection
        {
            Left,
            Right
        };

    public:
        CEntity* GetPlayer();
        void SetPlayer(CEntity* _pPlayer);
        EDirection GetPlayerDirection();
        bool GetPlayerAnimationState();
        void SetPlayerAnimationState(bool _AnimatePlayer);
        void SetPlayerDirection(EDirection _Direction);

    private:
        CPlayerSystem() : m_pPlayer(nullptr), m_PlayerDirection(Right)
        {};

    private:
        CEntity* m_pPlayer;
        EDirection m_PlayerDirection;
        bool m_AnimatePlayer = false;
    };
}