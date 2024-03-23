#include "game_startup_phase.h"
#include "data/data_startup_phase.h"
#include "logic/logic_startup_phase.h"
#include "gui/gui_startup_phase.h"
#include "graphics/gfx_startup_phase.h"

#include "tinyxml2.h"

namespace Game
{
    int CStartupPhase::InternOnEnter()
    {
        //Logic::CStartupPhase::GetInstance().OnEnter();
        Gui::CStartupPhase::GetInstance().OnEnter();
        Gfx::CStartupPhase::GetInstance().OnEnter();

        return 0;
    }

    int CStartupPhase::InternOnRun()
    {
        tinyxml2::XMLDocument* pDocument = new tinyxml2::XMLDocument();
        pDocument->LoadFile("..\\resources\\meta\\meta_entity.xml");

        Data::CStartupPhase::GetInstance().OnRun(*pDocument);
        Logic::CStartupPhase::GetInstance().OnRun();
        Gui::CStartupPhase::GetInstance().OnRun();
        Gfx::CStartupPhase::GetInstance().OnRun();

        return EPhase::MainMenu;
    }

    int CStartupPhase::InternOnLeave()
    {
        //Data::CStartupPhase::GetInstance().OnLeave();
        Logic::CStartupPhase::GetInstance().OnLeave();
        Gui::CStartupPhase::GetInstance().OnLeave();
        Gfx::CStartupPhase::GetInstance().OnLeave();

        return 0;
    }
}