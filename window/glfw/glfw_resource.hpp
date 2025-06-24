#pragma once

#include <glm/glm.hpp>
#include "glfw.hpp"

namespace window::glfw
{
    /// @brief GLFW资源
    class GLFWResource : base::Resource
    {
    public:
        /// @brief 资源类型
        enum class ResourceType : base::Int64
        {
            /// @brief 无
            None,
            /// @brief 窗口
            Window,
            /// @brief 监视器
            Monitor,
            /// @brief 鼠标
            Cursor,
        };

    public:
        GLFWResource() = default;
        ~GLFWResource() override = default;
    };

} // namespace window::glfw
