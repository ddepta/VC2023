
#include "data_meta_entity.h"
#include "data_meta_entity_system.h"
#include "../core/core_item_manager.h"
#include "../core/core_id_manager.h"
#include "../core/core_aabb3.h"

namespace Data
{
    int CMetaEntitySystem::Initialize(tinyxml2::XMLDocument& _rDocument)
    {
        tinyxml2::XMLElement* pMetaEntities = _rDocument.FirstChildElement("meta-entities");
        tinyxml2::XMLElement* pMetaEntity = pMetaEntities->FirstChildElement("meta-entity");

        int MetaEntityCount = 0;

        while (pMetaEntity != nullptr)
        {
            std::string name = pMetaEntity->FindAttribute("name")->Value();
            tinyxml2::XMLElement* pDataElement = pMetaEntity->FirstChildElement("data");
            float size = pDataElement->FirstChildElement("size")->FindAttribute("value")->FloatValue();

            MetaEntityCount++;

            pMetaEntity = pMetaEntity->NextSiblingElement();
        }

        return MetaEntityCount;
    }
            CMetaEntity& CreateMetaEntity(std::string& _rName)
            {
                return CMetaEntitySystem::GetInstance().CreateMetaEntity(_rName);
            }

            void DestroyMetaEntity(CMetaEntity& _rMetaEntity)
            {
                CMetaEntitySystem::GetInstance().DestroyMetaEntity(_rMetaEntity);
            }

            CMetaEntity* SearchMetaEntity(std::string& _rName)
            {
                return CMetaEntitySystem::GetInstance().SearchMetaEntity(_rName);
            }

            CMetaEntity& GetMetaEntity(int _ID)
            {
                return CMetaEntitySystem::GetInstance().GetMetaEntity(_ID);
            }

}