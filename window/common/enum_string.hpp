#pragma once

#include <iostream>
#include "enums.hpp"

namespace window
{
    std::ostream &operator<<(std::ostream &os, Key key);

    std::ostream &operator<<(std::ostream &os, Action action);

    std::ostream &operator<<(std::ostream &os, MouseButton mouse_button);

} // namespace window
