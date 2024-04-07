#include "data_event.h"

namespace Data
{
    void CEvent::SetType(SEventType::EEventType _Type)
    {
        m_TypeId = _Type;
    }

    SEventType::EEventType CEvent::GetType() const
    {
        return m_TypeId;
    }

    void CEvent::SetData(int _Data)
    {
        m_Data = _Data;
    }

    int CEvent::GetData() const
    {
        return m_Data;
    }
}
