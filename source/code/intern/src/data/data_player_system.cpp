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

    void CPlayerSystem::SetPlayerDirection(EDirection _Direction)
    {
        this->m_PlayerDirection = _Direction;
    }
}