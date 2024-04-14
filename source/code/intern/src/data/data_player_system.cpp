#include "data_player_system.h"

namespace Data 
{
    CEntity* CPlayerSystem::GetPlayer()
    {
        return m_pPlayer;
    }

    void CPlayerSystem::SetPlayer(CEntity* _pPlayer)
    {
        this->m_pPlayer = _pPlayer;
    }

    CPlayerSystem::EDirection CPlayerSystem::GetPlayerDirection()
    {
        return m_PlayerDirection;
    }

    bool CPlayerSystem::GetPlayerAnimationState()
    {
        return m_AnimatePlayer;
    }

    void CPlayerSystem::SetPlayerAnimationState(bool _AnimatePlayer)
    {
        m_AnimatePlayer = _AnimatePlayer;
    }

    void CPlayerSystem::SetPlayerDirection(EDirection _Direction)
    {
        this->m_PlayerDirection = _Direction;
    }
}