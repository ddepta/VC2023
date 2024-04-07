#pragma once

#include <queue>

#include "../data/data_event.h"
#include "gui_input.h"

namespace Gui
{
	class CInputSystem
	{
		using InputQueue = std::queue<CInput*>;

		public:
            static CInputSystem& GetInstance()
            {
                static CInputSystem instance;
                return instance;
            };

            CInputSystem(const CInputSystem&) = delete;
            CInputSystem& operator = (const CInputSystem&) = delete;

            CInput& GetNextInput();
            void RemoveNextInput();
            bool InputQueueHasInputs() const;

            void OnRun();

            static void DispatchEvent(Data::CEvent& _rEvent);

        private:
            CInputSystem() {};

            InputQueue m_InputQueue;
	};
}