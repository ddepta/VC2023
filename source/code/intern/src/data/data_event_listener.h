#pragma once

namespace Data
{
    class CEvent;
}

namespace Data
{
    using EventListener = void (*) (CEvent& _rEvent);
}
