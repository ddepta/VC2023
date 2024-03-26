#include "data_entity_system.h"
#include "data_meta_entity_system.h"
#include "../core/core_splitstrings.h"

#include <tinyxml2.h>
#include <sstream>
#include <string>
#include <vector>

namespace Data
{
    int CEntitySystem::Initialize(tinyxml2::XMLDocument& _rDocument)
    {
        int EntityCount = 0;

        CMetaEntitySystem& _rMetaEntitySystem = CMetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* pEntities = _rDocument.FirstChildElement("entities");

        // Iterate over each entity
        for (tinyxml2::XMLElement* pXmlEntity = pEntities->FirstChildElement("_rEntity"); pXmlEntity != nullptr; pXmlEntity = pXmlEntity->NextSiblingElement())
        {
            // Extract entity name and meta-entity name
            std::string Name = pXmlEntity->FindAttribute("name")->Value();
            std::string MetaEntityName = pXmlEntity->FindAttribute("meta-_rEntity")->Value();

            // Get meta-entity ID and reference
            auto _ID = _rMetaEntitySystem.GetMetaEntityID(MetaEntityName);
            CMetaEntity& _rMetaEntity = _rMetaEntitySystem.GetMetaEntityByID(_ID);

            // Extract data element
            tinyxml2::XMLElement* pDataElement = pXmlEntity->FirstChildElement("data");

            // Extract type, size, and position information
            auto Type = atoi(pDataElement->FirstChildElement("type")->FirstChild()->Value());
            auto SizeStrings = Core::SplitStrings(pDataElement->FirstChildElement("m_Size")->FirstChild()->Value(), ';');
            auto PositionStrings = Core::SplitStrings(pDataElement->FirstChildElement("m_Position")->FirstChild()->Value(), ';');

            CEntity& _rEntity = CreateEntity(Name);

            if (Type >= SEntityCategory::NumberOfMembers)
            {
                _rEntity.m_Category = SEntityCategory::Undefined;
            }
            else
            {
                _rEntity.m_Category = SEntityCategory::Enum(Type);
            }

            _rEntity.m_Size = Core::Float3(
                std::stof(SizeStrings[0]),
                std::stof(SizeStrings[1]),
                std::stof(SizeStrings[2])
            );

            _rEntity.m_Position = Core::Float3(
                std::stof(PositionStrings[0]),
                std::stof(PositionStrings[1]),
                std::stof(PositionStrings[2])
            );

            _rEntity.m_AABB = Core::CAABB3<float>(
                Core::Float3(_rEntity.m_Position[0], _rEntity.m_Position[1], _rEntity.m_Position[2]),
                Core::Float3(_rEntity.m_Position[0] + _rEntity.m_Size[0], _rEntity.m_Position[1] + _rEntity.m_Size[1], _rEntity.m_Position[2] + _rEntity.m_Size[2])
            );

            _rEntity.m_pMetaEntity = &_rMetaEntity;

            EntityCount++;
        }

        return EntityCount;
    }

    CEntity& CEntitySystem::CreateEntity(std::string _Name)
    {
        Core::CIDManager::BID ID = m_IdManager.Register(_Name);

        CEntity& _rEntity = m_itemManager.CreateItem(ID);
        _rEntity.m_Id = ID;

        return _rEntity;
    }

    std::vector<Data::CEntity*> CEntitySystem::GetAllEntities()
    {
        return m_itemManager.GetAllItems();
    }
}
