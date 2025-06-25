#include "enum_string.hpp"

#define WINDOW_ENUM_STRING_ACTION(action) \
    case Action::action:                  \
        os << #action;                    \
        break;

#define WINDOW_ENUM_STRING_MOUSE_BUTTON(mouse_button) \
    case MouseButton::mouse_button:                   \
        os << #mouse_button;                          \
        break;

namespace window
{
    std::ostream &operator<<(std::ostream &os, Key key)
    {
        base::Int32 i = static_cast<base::Int32>(key);
        if (i >= 32 && i <= 126)
            os << static_cast<char>(key);

        return os;
    }

    std::ostream &operator<<(std::ostream &os, Action action)
    {
        switch (action)
        {
            WINDOW_ENUM_STRING_ACTION(None);
            WINDOW_ENUM_STRING_ACTION(Pressed);
            WINDOW_ENUM_STRING_ACTION(Released);
            WINDOW_ENUM_STRING_ACTION(Echo);

        default:
            os << "Unknown";
            break;
        }

        return os;
    }

    std::ostream &operator<<(std::ostream &os, MouseButton mouse_button)
    {
        switch (mouse_button)
        {
            WINDOW_ENUM_STRING_MOUSE_BUTTON(None);
            WINDOW_ENUM_STRING_MOUSE_BUTTON(Left);
            WINDOW_ENUM_STRING_MOUSE_BUTTON(Middle);
            WINDOW_ENUM_STRING_MOUSE_BUTTON(Right);
            WINDOW_ENUM_STRING_MOUSE_BUTTON(Extra1);
            WINDOW_ENUM_STRING_MOUSE_BUTTON(Extra2);

        default:
            os << "Unknown";
            break;
        }

        return os;
    }

} // namespace window
