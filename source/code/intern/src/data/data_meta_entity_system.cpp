
#include "data_meta_entity.h"
#include "data_meta_entity_system.h"

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
}