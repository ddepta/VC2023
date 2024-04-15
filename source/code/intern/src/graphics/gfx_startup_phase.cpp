#include "gfx_startup_phase.h"

#include "data/data_meta_entity_system.h"

#include <tinyxml2.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Gfx
{
    void CStartupPhase::OnEnter()
    {}

    void CStartupPhase::OnRun(tinyxml2::XMLDocument& _rMetaEntityXml)
    {
        Data::CMetaEntitySystem& rMetaEntitySystem = Data::CMetaEntitySystem::GetInstance();

        tinyxml2::XMLElement* pMetaEntities = _rMetaEntityXml.FirstChildElement("meta-entities");

        for (tinyxml2::XMLElement* pXmlMetaEntity = pMetaEntities->FirstChildElement("meta-entity"); pXmlMetaEntity != nullptr; pXmlMetaEntity = pXmlMetaEntity->NextSiblingElement())
        {
            pXmlMetaEntity->FindAttribute("name")->Value();
            auto Id = rMetaEntitySystem.GetMetaEntityID(pXmlMetaEntity->FindAttribute("name")->Value());
            Data::CMetaEntity& rMetaEntity = rMetaEntitySystem.GetMetaEntityByID(Id);

            tinyxml2::XMLElement* pGraphics = pXmlMetaEntity->FirstChildElement("graphics");

            std::string Texture = pGraphics->FirstChildElement("texture")->FindAttribute("value")->Value();

            sf::Texture* pTexture = new sf::Texture();

            if (pTexture->loadFromFile("..\\resources\\textures\\" + Texture))
            {
                rMetaEntity.m_Facets[Data::CMetaEntity::SFacetType::GraphicsFacet] = pTexture;
            }
        }
    }

    void CStartupPhase::OnLeave()
    {}
}
