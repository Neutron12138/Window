#pragma once

#include "glfw.hpp"
#include "../common/enums.hpp"

namespace window::glfw
{
    /// @brief 将GLFW的键码转换为Key
    /// @param key GLFW键码
    /// @return 转换后的结果
    Key convert_key(int key);

    /// @brief 将GLFW的动作转换为Action
    /// @param action GLFW动作
    /// @return 转换后的结果
    Action convert_action(int action);

} // namespace window::glfw
