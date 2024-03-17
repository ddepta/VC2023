
#include "data_meta_entity.h"
#include "data_meta_entity_system.h"
#include "../core/core_item_manager.h"
#include "../core/core_id_manager.h"

using namespace Data;

namespace
{
    class CDataMetaEntitySystem
    {
    public:

        static CDataMetaEntitySystem& GetInstance();

    public:

        CMetaEntity& CreateMetaEntity(const std::string& _rName);
        void DestroyMetaEntity(CMetaEntity& _rMetaEntity);

        CMetaEntity* SearchMetaEntity(std::string& _rName);
        CMetaEntity& GetMetaEntity(int _ID);

    private:

        class CInternMetaEntity : public CMetaEntity
        {
            friend class CDataMetaEntitySystem;
        };

        using CMetaEntityAllocator = Core::CItemManager<CInternMetaEntity>;

    private:

        CMetaEntityAllocator m_Allocator;
        Core::CIDManager     m_Names;

    private:

        CDataMetaEntitySystem();
        ~CDataMetaEntitySystem();
    };
}

namespace
{
    CDataMetaEntitySystem& CDataMetaEntitySystem::GetInstance()
    {
        static CDataMetaEntitySystem s_Instance;

        return s_Instance;
    }
}

namespace
{
    // Konstruktor, Destruktor, MemberMethoden
    CMetaEntity& CDataMetaEntitySystem::CreateMetaEntity(const std::string& _rName)
    {
        Core::CIDManager::BID ID = m_Names.Register(_rName);

        CInternMetaEntity& rMetaEntity = m_Allocator.CreateItem(ID);

        return rMetaEntity;
    }
}

namespace Data
{
    namespace MetaEntitySystem
    {
        CMetaEntity& CreateMetaEntity(std::string& _rName)
        {
            return CDataMetaEntitySystem::GetInstance().CreateMetaEntity(_rName);
        }

        void DestroyMetaEntity(CMetaEntity& _rMetaEntity)
        {
            CDataMetaEntitySystem::GetInstance().DestroyMetaEntity(_rMetaEntity);
        }

        CMetaEntity* SearchMetaEntity(std::string& _rName)
        {
            return CDataMetaEntitySystem::GetInstance().SearchMetaEntity(_rName);
        }

        CMetaEntity& GetMetaEntity(int _ID)
        {
            return CDataMetaEntitySystem::GetInstance().GetMetaEntity(_ID);
        }
    }
}
