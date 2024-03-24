#include "game_load_phase.h"
#include "data/data_load_phase.h"
#include "logic/logic_load_phase.h"
#include "gui/gui_load_phase.h"
#include "graphics/gfx_load_phase.h"

#include "tinyxml2.h"

namespace Game
{
    int CLoadPhase::InternOnEnter()
    {
        Data ::CLoadPhase::GetInstance().OnEnter();
        Logic::CLoadPhase::GetInstance().OnEnter();
        Gui  ::CLoadPhase::GetInstance().OnEnter();
        Gfx  ::CLoadPhase::GetInstance().OnEnter();

        return 0;
    }

    int CLoadPhase::InternOnRun()
    {
        tinyxml2::XMLDocument* pDocument = new tinyxml2::XMLDocument();
        pDocument->LoadFile("..\\resources\\level\\level.xml");

        Data ::CLoadPhase::GetInstance().OnRun(*pDocument);
        Logic::CLoadPhase::GetInstance().OnRun();
        Gui  ::CLoadPhase::GetInstance().OnRun();
        Gfx  ::CLoadPhase::GetInstance().OnRun();

        return EPhase::Play;
    }

    int CLoadPhase::InternOnLeave()
    {
        Data ::CLoadPhase::GetInstance().OnLeave();
        Logic::CLoadPhase::GetInstance().OnLeave();
        Gui  ::CLoadPhase::GetInstance().OnLeave();
        Gfx  ::CLoadPhase::GetInstance().OnLeave();

        return 0;
    }
}
