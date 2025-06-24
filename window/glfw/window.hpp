#pragma once

#include "../common/base_window.hpp"
#include "glfw_window.hpp"

namespace window::glfw
{
    class Window;
    using WindowRef = base::Ref<Window>;
    using WindowWeakRef = base::WeakRef<Window>;

    /// @brief 窗口
    class Window : public BaseWindow
    {
    private:
        /// @brief GLFW窗口
        GLFWWindowRef m_window;

    public:
        Window() = default;
        ~Window() = default;

    public:
        bool is_open() const { return !m_window->should_close(); }
        glm::ivec2 get_position() const { return m_window->get_pos(); }
        glm::ivec2 get_size() const { return m_window->get_size(); }
        std::string get_title() const { return m_window->get_title(); }

        void close_window() { m_window->set_should_close(true); }
        void set_position(const glm::ivec2 &position) { m_window->set_pos(position); }
        void set_size(const glm::ivec2 &size) { m_window->set_size(size); }
        void set_title(const std::string &title) { m_window->set_title(title); }
        void set_icon(const base::BaseImageRef &image) { m_window->set_icon(image); }
    };

} // namespace window::glfw
