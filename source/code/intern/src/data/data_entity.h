
#pragma once

#include "data_entity_link.h"
#include "data_entity_category.h"
#include "data_meta_entity.h"

#include <array>
#include "../core/core_id_manager.h"

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

	public:
		Core::CIDManager::BID m_Id;
		SEntityCategory::Enum m_Category;
		Core::CVector3<float> m_Position;
		Core::CVector3<float> m_Size;
		Core::CAABB3<float> m_AABB;
		CMetaEntity* m_pMetaEntity;

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
