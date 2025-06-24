#include "glfw_window.hpp"

namespace window::glfw
{
    GLFWwindow *GLFWWindow::create_glfw_window(int width, int height, const char *title = "",
                                               GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr)
    {
        GLFWwindow *window = glfwCreateWindow(width, height, title, monitor, share);
        if (!window)
            throw BASE_MAKE_RUNTIME_ERROR(
                "Failed to create GLFW window with width: ", width,
                ", height: ", height,
                ", title: \"", title,
                "\", monitor: ", monitor,
                ", share: ", share);

        return window;
    }

    glm::ivec2 GLFWWindow::get_pos() const
    {
        glm::ivec2 pos;
        glfwGetWindowPos(m_window, &pos.x, &pos.y);
        return pos;
    }

    glm::ivec2 GLFWWindow::get_size() const
    {
        glm::ivec2 size;
        glfwGetWindowSize(m_window, &size.x, &size.y);
        return size;
    }

    void GLFWWindow::set_icon(const base::BaseImageRef &image)
    {
        GLFWimage img = {image->get_width(),
                         image->get_height(),
                         const_cast<unsigned char *>(
                             reinterpret_cast<const unsigned char *>(
                                 image->get_raw_pixels()))};
        glfwSetWindowIcon(m_window, 1, &img);
    }

} // namespace window::glfw
