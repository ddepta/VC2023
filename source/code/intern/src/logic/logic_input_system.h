#pragma once

#include <queue>

#include "logic_input.h"
#include "../data/data_event.h"

namespace Logic 
{
    class CInputSystem 
    {
        using InputQueue = std::queue<CInput*>;

        public:
            static CInputSystem& GetInstance()
            {
                static CInputSystem s_Instance;
                return s_Instance;
            }

            CInputSystem(const CInputSystem&) = delete;
            CInputSystem& operator = (const CInputSystem&) = delete;

        public:
            CInput& CreateInput();
            void AddInput(CInput& rEvent);
            CInput& GetNextInQueue();
            void RemoveNextInQueue();
            bool InputQueueIsEmpty() const;

            // event callbacks
            static void DispatchInput(Data::CEvent& _rEvent);

        private:
            CInputSystem() {}

        private:
            InputQueue m_InputQueue;
    };
}