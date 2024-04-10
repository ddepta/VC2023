#pragma once

namespace Data
{
    class CScoreSystem
    {
    public:
        static CScoreSystem& GetInstance()
        {
            static CScoreSystem instance;
            return instance;
        };

        CScoreSystem(const CScoreSystem&) = delete;
        CScoreSystem& operator = (const CScoreSystem&) = delete;

    public:
        int GetScore();
        void IncreaseScore();

    private:
        CScoreSystem() : m_Score(0) {};

    private:
        int m_Score;
    };
}