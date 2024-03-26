#include "data_meta_entity.h"
#include <string>

namespace Data 
{
    CMetaEntity::CMetaEntity() {}

    CMetaEntity::CMetaEntity(int _Id, std::string _Name, float _Size, Core::AABB3Float _AABB)
        : m_Id(_Id)
        , m_Name(_Name)
        , m_Size(_Size)
        , m_AABB(_AABB)
    {}

    CMetaEntity::~CMetaEntity() {}
}