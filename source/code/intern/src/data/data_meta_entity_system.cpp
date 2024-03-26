
#include "data_meta_entity.h"
#include "data_meta_entity_system.h"
#include "../core/core_splitstrings.h"

namespace Data
{
    int CMetaEntitySystem::Initialize(tinyxml2::XMLDocument& _rDocument)
    {
        tinyxml2::XMLElement* pMetaEntities = _rDocument.FirstChildElement("meta-entities");

        int MetaEntityCount = 0;

        for (tinyxml2::XMLElement* pMetaEntity = pMetaEntities->FirstChildElement("meta-entity"); pMetaEntity != nullptr; pMetaEntity = pMetaEntity->NextSiblingElement())
        {
            std::string Name = pMetaEntity->FindAttribute("name")->Value();
            tinyxml2::XMLElement* pDataElement = pMetaEntity->FirstChildElement("data");
            float Size = pDataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

            auto MinCorner = Core::SplitStrings(pDataElement->FirstChildElement("aabb")->FindAttribute("minCorner")->Value(), ';');
            auto MaxCorner = Core::SplitStrings(pDataElement->FirstChildElement("aabb")->FindAttribute("maxCorner")->Value(), ';');

            Core::AABB3Float AABB = Core::AABB3Float(
                Core::Float3(
                    std::stof(MinCorner[0]),
                    std::stof(MinCorner[1]),
                    std::stof(MinCorner[2])
                ),
                Core::Float3(
                    std::stof(MaxCorner[0]),
                    std::stof(MaxCorner[1]),
                    std::stof(MaxCorner[2])
                )
            );

            CMetaEntity& rEntity = CreateMetaEntity(Name);
            rEntity.m_Name = Name;
            rEntity.m_Size = Size;
            rEntity.m_AABB = AABB;

            MetaEntityCount++;
        }

        return MetaEntityCount;
    }

    CMetaEntity& CMetaEntitySystem::CreateMetaEntity(std::string _Name)
    {
        Core::CIDManager::BID Id = m_IdManager.Register(_Name);

        return m_itemManager.CreateItem(Id);
    }

    CMetaEntity& CMetaEntitySystem::GetMetaEntityByID(Core::CIDManager::BID _ID)
    {
        return m_itemManager.GetItem(_ID);
    }

    Core::CIDManager::BID CMetaEntitySystem::GetMetaEntityID(std::string _Name)
    {
        return m_IdManager.GetByName(_Name);
    }
}