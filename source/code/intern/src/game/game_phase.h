
#pragma once

namespace Game
{
    class CPhase
    {
        public:

            enum EPhase
            {
                Startup,
                Shutdown,
                LoadMap,
                MainMenu,
                Play,
                UnloadMap,
                NumberOfMembers,
                Undefined = -1,
            };

        public:

            int OnEnter();
            int OnLeave();
            int OnRun();

        private:

            virtual int InternOnEnter() = 0;
            virtual int InternOnLeave() = 0;
            virtual int InternOnRun() = 0;
    };
}
