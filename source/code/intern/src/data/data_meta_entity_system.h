
#pragma once

#include <string>
#include "tinyxml2.h"
#include "data_meta_entity.h"
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"

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
        CMetaEntity& GetMetaEntityByID(Core::CIDManager::BID _ID);
        Core::CIDManager::BID GetMetaEntityID(std::string _Name);

    private:
        CMetaEntitySystem() {};

    private:
        Core::CIDManager m_IdManager;
        Core::CItemManager<CMetaEntity> m_itemManager;
    };
}