#pragma once

#include "glfw_resource.hpp"

namespace glfw
{
    class GLFWWindow;
    using GLFWWindowRef = base::Ref<GLFWWindow>;
    using GLFWWindowWeakRef = base::WeakRef<GLFWWindow>;

    GLFWwindow *create_glfw_window(int width, int height, const char *title = "",
                                   GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);
        if (!window)
            throw std::runtime_error(base::to_string(
                "Failed to create GLFW window with width: ", width,
                ", height: ", height,
                ", title: \"", title,
                "\", monitor: ", monitor,
                ", share: ", share));

        return window;
    }

    /// @brief GLFW窗口
    class GLFWWindow : public GLFWResource
    {
    public:
        static GLFWWindowRef create(int width, int height, const std::string &title = {},
                                    GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr)
        {
            return std::make_shared<GLFWWindow>(width, height, title, monitor, share);
        }

    private:
        GLFWwindow *m_window = nullptr;

    public:
        GLFWWindow(int width, int height, const std::string &title = {},
                   GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr)
        {
            m_window = create_glfw_window(width, height, title.data(), monitor, share);
        }

        ~GLFWWindow() override { glfwDestroyWindow(m_window); }

    public:
        GLFWwindow *get_window() const { return m_window; }
        base::Int64 get_resource_type() const override { return static_cast<base::Int64>(ResourceType::Window); }

    public:
        int should_close() const { return glfwWindowShouldClose(m_window); }
        std::string get_title() const { return glfwGetWindowTitle(m_window); }
        void *get_user_pointer() const { return glfwGetWindowUserPointer(m_window); }

        void make_context_current() { glfwMakeContextCurrent(m_window); }
        void set_should_close(int value) { glfwSetWindowShouldClose(m_window, value); }
        void swap_buffers() { glfwSwapBuffers(m_window); }
        void set_title(const std::string &title) { glfwSetWindowTitle(m_window, title.data()); }
        void set_user_pointer(void *pointer) { glfwSetWindowUserPointer(m_window, pointer); }
        void set_pos(const glm::ivec2 &pos) { glfwSetWindowPos(m_window, pos.x, pos.y); }
        void set_size(const glm::ivec2 &size) { glfwSetWindowSize(m_window, size.x, size.y); }

        glm::ivec2 get_pos() const
        {
            glm::ivec2 pos;
            glfwGetWindowPos(m_window, &pos.x, &pos.y);
            return pos;
        }

        glm::ivec2 get_size() const
        {
            glm::ivec2 size;
            glfwGetWindowSize(m_window, &size.x, &size.y);
            return size;
        }
    };

} // namespace glfw
