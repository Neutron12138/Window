#include <iostream>
#define WINDOW_USE_GLFW
#include "../window/window.hpp"

int main()
{
    window::glfw::init_glfw();
    auto window = window::glfw::GLFWWindow::create(640, 480);
    while (!window->should_close())
        window::glfw::glfw_poll_events();
    window.reset();
    window::glfw::term_glfw();

    return 0;
}
