
#pragma once
#include "../core/core_aabb.h"
#include <string>

namespace Data
{
    class CMetaEntity
    {
    public:
        CMetaEntity();
        CMetaEntity(int _Id, std::string _Name, float _Size, Core::AABB3Float _AABB);

        ~CMetaEntity();

    public:
        int m_Id;
        std::string m_Name;
        float m_Size;
        Core::AABB3Float m_AABB;

        void* m_Facets[2];

    public:

        struct SFacetType
        {
            enum EType
            {
                GraphicsFacet,
                LogicFacet,
                NumberOfFacets
            };
        };
    };
}
