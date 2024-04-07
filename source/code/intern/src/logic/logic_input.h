#pragma once

#include "../data/data_event_type.h"

namespace Logic 
{
    class CInput 
    {
        public:
            CInput();
            ~CInput();

        public:
            Data::SEventType::EEventType GetType() const;
            void SetType(Data::SEventType::EEventType m_Type);

        private:
            Data::SEventType::EEventType m_Type;
    };
}