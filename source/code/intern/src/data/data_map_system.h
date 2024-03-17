#pragma once

#include "data_entity_category.h"
#include "data_entity_iterator.h"
#include "../core/core_aabb.h"

namespace Data
{
	namespace MapSystem
	{
		CEntityIterator Begin();
		CEntityIterator Begin(SEntityCategory _Category);

		CEntityIterator Begin(const Core::AABB2Float& _rAABB);
		CEntityIterator Begin(const Core::AABB2Float& _rAABB, SEntityCategory _Category);

		CEntityIterator& Next(CEntityIterator& _Where);
		CEntityIterator& Next(CEntityIterator& _Where, SEntityCategory _Category);

		CEntityIterator& Next(CEntityIterator& _Where, const Core::AABB2Float& _rAABB);
		CEntityIterator& Next(CEntityIterator& _Where, const Core::AABB2Float& _rAABB, SEntityCategory _Category);

		CEntityIterator End();

		bool Next(void* _pTicket);
		CEntity& GetEntity(void* _pTicket);
	}
}
