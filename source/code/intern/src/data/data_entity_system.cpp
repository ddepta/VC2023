#include "data_entity_system.h"
#include "data_meta_entity_system.h"
#include "data_player_system.h"
#include "data_score_system.h"
#include "../core/core_splitstrings.h"

#include <tinyxml2.h>
#include <sstream>
#include <string>
#include <vector>

namespace Data
{
    int CEntitySystem::Initialize(tinyxml2::XMLDocument& _rLevelXml)
    {
        int EntityCount = 0;

        CMetaEntitySystem& rMetaEntitySystem = CMetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* pEntities = _rLevelXml.FirstChildElement("entities");

        int MaxScore = 0;

        Core::CVector2<float> LevelSize;

        // -----------------------------------------------------------------------------
        // Iterate over each entity
        // -----------------------------------------------------------------------------
        for (tinyxml2::XMLElement* pXmlEntity = pEntities->FirstChildElement("entity"); pXmlEntity != nullptr; pXmlEntity = pXmlEntity->NextSiblingElement())
        {
            // -----------------------------------------------------------------------------
            // Extract entity name and meta-entity name
            // Get meta-entity ID and reference
            // Extract data element
            // Extract type, size, and position information
            // -----------------------------------------------------------------------------
            std::string Name = pXmlEntity->FindAttribute("name")->Value();
            std::string MetaEntityName = pXmlEntity->FindAttribute("meta-entity")->Value();

            auto Id = rMetaEntitySystem.GetMetaEntityID(MetaEntityName);
            CMetaEntity& rMetaEntity = rMetaEntitySystem.GetMetaEntityByID(Id);

            tinyxml2::XMLElement* pDataElement = pXmlEntity->FirstChildElement("data");

            auto Type = atoi(pDataElement->FirstChildElement("type")->FirstChild()->Value());
            auto SizeStrings = Core::SplitStrings(pDataElement->FirstChildElement("size")->FirstChild()->Value(), ';');
            auto PositionStrings = Core::SplitStrings(pDataElement->FirstChildElement("position")->FirstChild()->Value(), ';');

            CEntity& rEntity = CreateEntity(Name);

            if (Type >= SEntityCategory::NumberOfMembers)
            {
                rEntity.m_Category = SEntityCategory::Undefined;
            }
            else
            {
                rEntity.m_Category = SEntityCategory::Enum(Type);
            }

            // -----------------------------------------------------------------------------
            // Count eggs to define the max score
            // -----------------------------------------------------------------------------
            if (rEntity.m_Category == SEntityCategory::Egg)
            {
                MaxScore++;
            }

            if (rEntity.m_Category == SEntityCategory::Character)
            {
                Data::CPlayerSystem& rPlayerSystem = Data::CPlayerSystem::GetInstance();
                rPlayerSystem.SetPlayer(&rEntity);
            }

            rEntity.m_Size = Core::Float3(
                std::stof(SizeStrings[0]),
                std::stof(SizeStrings[1]),
                std::stof(SizeStrings[2])
            );

            rEntity.m_Position = Core::Float3(
                std::stof(PositionStrings[0]),
                std::stof(PositionStrings[1]),
                std::stof(PositionStrings[2])
            );

            rEntity.m_AABB = Core::CAABB3<float>(
                Core::Float3(rEntity.m_Position[0], rEntity.m_Position[1], rEntity.m_Position[2]),
                Core::Float3(rEntity.m_Position[0] + rEntity.m_Size[0], rEntity.m_Position[1] + rEntity.m_Size[1], rEntity.m_Position[2] + rEntity.m_Size[2])
            );

            rEntity.m_pMetaEntity = &rMetaEntity;

            LevelSize[0] = rEntity.m_Position[0] + rEntity.m_Size[0];
            LevelSize[1] = rEntity.m_Position[1] + rEntity.m_Size[1];

            EntityCount++;
        }

        m_LevelSize = LevelSize;

        Data::CScoreSystem& rScoreSystem = Data::CScoreSystem::GetInstance();
        rScoreSystem.SetMaxScore(MaxScore);

        return EntityCount;
    }

    CEntity& CEntitySystem::CreateEntity(std::string _Name)
    {
        Core::CIDManager::BID ID = m_IdManager.Register(_Name);

        CEntity& rEntity = m_itemManager.CreateItem(ID);
        rEntity.m_Id = ID;

        return rEntity;
    }

    void CEntitySystem::DestroyEntity(CEntity& _rEntity)
    {
        m_itemManager.DestroyItem(_rEntity.m_Id);
    }

    std::vector<Data::CEntity*> CEntitySystem::GetAllEntities()
    {
        return m_itemManager.GetAllItems();
    }
}
