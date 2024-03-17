
#pragma once

#include "data_entity_link.h"

#include <array>

namespace Data
{
    class CEntityList;
}

namespace Data
{
    class CEntity
    {
        public:

            enum EFacet
            {
                GraphicsFacet,
                LogicFacet,
                NumberOfFacets
            };

        public:

            void SetFacet(EFacet _Type, void* _pFacet);
            void* GetFacet(EFacet _Type);

        private:

            using CFacetArray = std::array<void*, NumberOfFacets>;

        private:

            CFacetArray m_Facets;
            CEntityLink m_Link;

        private:

            friend class CEntityLink;
            friend class CEntityList;
    };
}
