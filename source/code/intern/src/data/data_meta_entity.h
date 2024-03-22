
#pragma once
#include "../core/core_aabb.h"
#include <string>

namespace Data
{
    class CMetaEntity
    {
    public:
        CMetaEntity();
        CMetaEntity(int _Id, std::string _Name, float _Size, Core::AABB2Float _AABB);

        ~CMetaEntity();

    public:
        int Id;
        std::string Name;
        float Size;
        Core::AABB2Float AABB;

        void* facets[2];
    };
}
