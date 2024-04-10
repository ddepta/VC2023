#include "data_score_system.h"

namespace Data
{
    int CScoreSystem::GetScore()
    {
        return m_Score;
    }

    int CScoreSystem::GetMaxScore()
    {
        return m_MaxScore;
    }

    void CScoreSystem::IncreaseScore()
    {
        m_Score++;
    }

    void CScoreSystem::SetMaxScore(int _MaxScore)
    {
        m_MaxScore = _MaxScore;
    }

    void CScoreSystem::ResetScore()
    {
        m_Score = 0;
    }
}
