#include "data_load_phase.h"
#include "data_entity_system.h"
#include <tinyxml2.h>

namespace Data
{
    void CLoadPhase::OnEnter()
    {}

    void CLoadPhase::OnRun(tinyxml2::XMLDocument& _rDocument)
    {
        CEntitySystem::GetInstance().Initialize(_rDocument);
    }

    void CLoadPhase::OnLeave()
    {}
}