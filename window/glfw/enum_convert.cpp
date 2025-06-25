#include "enum_convert.hpp"

namespace window::glfw
{
    Key convert_key(int key)
    {
        if (key >= GLFW_KEY_A && key <= GLFW_KEY_Z)
            return static_cast<Key>(key);
        else if (key >= GLFW_KEY_0 && key <= GLFW_KEY_9)
            return static_cast<Key>(key);

        return Key::Unknown;
    }

    Action convert_action(int action)
    {
        switch (action)
        {
        case GLFW_PRESS:
            return Action::Pressed;

        case GLFW_RELEASE:
            return Action::Released;

        case GLFW_REPEAT:
            return Action::Echo;
        }

        return Action::Unknown;
    }

} // namespace window::glfw
