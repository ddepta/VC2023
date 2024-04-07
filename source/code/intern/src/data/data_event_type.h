#pragma once

namespace Data
{
    struct SEventType
    {
        enum EEventType
        {
            DispatchEvent,
            DispatchInput,
            Finished,
            EscapePressed,
            EnterPressed,
            UpPressed,
            DownPressed,
            LeftPressed,
            RightPressed,
            NumberOfMembers,
            Undefined = -1,
        };
    };
}