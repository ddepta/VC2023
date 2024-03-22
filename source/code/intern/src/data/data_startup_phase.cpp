#include "data_startup_phase.h"
#include "data_meta_entity_system.h"

namespace Data
{
    void CStartupPhase::OnEnter()
    {}

    void CStartupPhase::OnRun(tinyxml2::XMLDocument& _rDocument)
    {
        CMetaEntitySystem::GetInstance().Initialize(_rDocument);
    }

    void CStartupPhase::OnLeave()
    {}
}
