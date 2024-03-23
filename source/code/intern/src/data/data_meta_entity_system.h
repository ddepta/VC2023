
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
        CMetaEntity& CreateMetaEntity(const std::string& _rName);
        void DestroyMetaEntity(CMetaEntity& _rMetaEntity);

        CMetaEntity* SearchMetaEntity(std::string& _rName);
        CMetaEntity& GetMetaEntity(int _ID);

    private:

        class CInternMetaEntity : public CMetaEntity
        {
            friend class CMetaEntitySystem;
        };

    private:

        //Core::CIDManager     m_Names;
        //Core::CItemManager<CMetaEntity> m_itemManager;

    private:

        CMetaEntitySystem();
        ~CMetaEntitySystem();
    };
}