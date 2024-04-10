#include "data_score_system.h"

namespace Data
{
    int CScoreSystem::GetScore()
    {
        return m_Score;
    }

    void CScoreSystem::IncreaseScore()
    {
        m_Score++;
    }
}
