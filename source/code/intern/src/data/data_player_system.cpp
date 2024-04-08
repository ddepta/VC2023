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
}