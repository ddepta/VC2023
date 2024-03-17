
#pragma once

#include <string>

namespace Data
{
    class CMetaEntity;
}

namespace Data
{
    namespace MetaEntitySystem
    {
        CMetaEntity& CreateMetaEntity(const std::string& _rName);
        void DestroyMetaEntity(CMetaEntity& _rMetaEntity);

        CMetaEntity* SearchMetaEntity(const std::string& _rName);
        CMetaEntity& GetMetaEntity(int _ID);
    }
}
