#include "data_meta_entity.h"
#include <string>

namespace Data 
{
    CMetaEntity::CMetaEntity() {}

    CMetaEntity::CMetaEntity(int _Id, std::string _Name, float _Size, Core::AABB2Float _AABB)
        : Id(_Id)
        , Name(_Name)
        , Size(_Size)
        , AABB(_AABB)
    {}

    CMetaEntity::~CMetaEntity() {}
}