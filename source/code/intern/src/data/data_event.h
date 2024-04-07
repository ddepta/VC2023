#pragma once

#include "data_event_type.h"

namespace Data
{
    class CEvent
    {
    public:
        void SetType(SEventType::EEventType _EventType);
        SEventType::EEventType GetType() const;

        void SetData(int _Data);
        int GetData() const;

    protected:
        SEventType::EEventType m_TypeId;
        int m_Data;
    };
}
