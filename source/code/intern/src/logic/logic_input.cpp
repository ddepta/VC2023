#include "logic_input.h"

#include "../data/data_event_type.h"

namespace Logic 
{
    CInput::CInput() : m_Type(Data::SEventType::EEventType::Undefined) {}

    CInput::~CInput() {}

    Data::SEventType::EEventType CInput::GetType() const
    {
        return m_Type;
    }

    void CInput::SetType(Data::SEventType::EEventType _Type)
    {
        this->m_Type = _Type;
    }
}