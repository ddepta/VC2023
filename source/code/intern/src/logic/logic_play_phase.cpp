#include "logic_play_phase.h"
#include "logic_input_system.h"

#include "../data/data_event_type.h"
#include "../data/data_event_system.h"

namespace Logic
{
    void CPlayPhase::OnEnter() 
    {
        Data::CEventSystem::GetInstance().Register(Data::SEventType::DispatchInput, &CInputSystem::DispatchInputToLogic);
    }

    void CPlayPhase::OnRun() {}

    void CPlayPhase::OnLeave() {}
}