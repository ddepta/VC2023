#pragma once

#include "data_entity.h"
#include <tinyxml2.h>
#include <string>
#include "../core/core_id_manager.h"
#include "../core/core_item_manager.h"

namespace Data
{
    class CEntitySystem
    {
    public:
        static CEntitySystem& GetInstance()
        {
            static CEntitySystem instance;
            return instance;
        };

        CEntitySystem(const CEntitySystem&) = delete;
        CEntitySystem& operator = (const CEntitySystem&) = delete;

    public:
        int Initialize(tinyxml2::XMLDocument& _rDocument);
        CEntity& CreateEntity(std::string _Name);

    private:
        CEntitySystem() {};

    private:
        Core::CIDManager m_IdManager;
        Core::CItemManager<CEntity> m_itemManager;
    };
}