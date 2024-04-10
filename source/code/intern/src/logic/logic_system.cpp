#include "logic_system.h"
#include "logic_input.h"
#include "logic_input_system.h"

#include "../data/data_entity_system.h"
#include "../data/data_entity_category.h"
#include "../data/data_player_system.h"
#include "../data/data_score_system.h"
#include "../data/data_event_system.h"

namespace Logic
{
    void CSystem::HandleInput()
    {
        CInputSystem& rInputSystem = CInputSystem::GetInstance();

        while (!rInputSystem.InputQueueIsEmpty())
        {
            CInput* pCurrentInput = &(rInputSystem.GetNextInQueue());

            float Movement = 64.0f;

            switch (pCurrentInput->GetType())
            {
                case Data::SEventType::UpPressed:
                    MovePlayer(Core::Float2(0.0f, -Movement));
                    break;
                case Data::SEventType::DownPressed:
                    MovePlayer(Core::Float2(0.0f, Movement));
                    break;
                case Data::SEventType::LeftPressed:
                    MovePlayer(Core::Float2(-Movement, 0.0f));
                    break;
                case Data::SEventType::RightPressed:
                    MovePlayer(Core::Float2(Movement, 0.0f));
                    break;
                default:
                    break;
            }

            rInputSystem.RemoveNextInQueue();
        }
    }

    void CSystem::MovePlayer(Core::Float2 _Direction)
    {
        Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
        Data::CEntity* pPlayerEntity = rPlayerSystem.GetPlayer();

        if (pPlayerEntity == nullptr)
        {
            return;
        }

        Core::CAABB3<float> NextPosition = Core::CAABB3<float>(
            Core::Float3(
                pPlayerEntity->m_Position[0] + _Direction[0] + 1, 
                pPlayerEntity->m_Position[1] + _Direction[1] + 1, 
                pPlayerEntity->m_Position[2]),
            Core::Float3(
                pPlayerEntity->m_Position[0] + _Direction[0] + 1, 
                pPlayerEntity->m_Position[1] + _Direction[1] + 1, 
                pPlayerEntity->m_Position[2])
        );

        std::vector<Data::CEntity*> Entities = Data::CEntitySystem::GetInstance().GetAllEntities();
        std::vector<Data::CEntity*> Points;

        bool WallCollision = false;

        for (Data::CEntity* pEntity : Entities)
        {
            if (pEntity != nullptr && NextPosition.Intersects(pEntity->m_AABB))
            {
                if (pEntity->m_Category == Data::SEntityCategory::Rock)
                {
                    WallCollision = true;
                }
                if (pEntity->m_Category == Data::SEntityCategory::Egg)
                {
                    Data::CEntitySystem::GetInstance().DestroyEntity(*pEntity);
                    Data::CScoreSystem::GetInstance().IncreaseScore();
                }
                if (pEntity->m_Category == Data::SEntityCategory::Finish)
                {
                    Data::CEventSystem::GetInstance().FireEvent(Data::SEventType::Finished);
                }
            }
        }

        if (!WallCollision)
        {
            pPlayerEntity->m_Position = 
                Core::Float3(
                    pPlayerEntity->m_Position[0] + _Direction[0], 
                    pPlayerEntity->m_Position[1] + _Direction[1], 
                    pPlayerEntity->m_Position[2]
                );

            pPlayerEntity->m_AABB = Core::CAABB3<float>(
                Core::Float3(
                    pPlayerEntity->m_Position[0], 
                    pPlayerEntity->m_Position[1], 
                    pPlayerEntity->m_Position[2]),
                Core::Float3(
                    pPlayerEntity->m_Position[0], 
                    pPlayerEntity->m_Position[1], 
                    pPlayerEntity->m_Position[2])
            );
        }
    }
}
