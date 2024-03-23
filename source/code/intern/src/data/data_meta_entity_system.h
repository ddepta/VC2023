
#pragma once

#include <string>
#include "tinyxml2.h"
#include "data_meta_entity.h"

namespace Data
{
    class CMetaEntitySystem
    {
    public:
        static CMetaEntitySystem& GetInstance()
        {
            static CMetaEntitySystem instance;
            return instance;
        }

        CMetaEntitySystem(const CMetaEntitySystem&) = delete;
        CMetaEntitySystem& operator = (const CMetaEntitySystem&) = delete;

    public:
        int Initialize(tinyxml2::XMLDocument& _rDocument);

    private:
        CMetaEntitySystem() {};
    };
}