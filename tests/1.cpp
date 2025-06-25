#include <iostream>
#define WINDOW_USE_GLFW
#include "../window/window.hpp"

class MyWindow : public window::glfw::Window
{
public:
    MyWindow() : window::glfw::Window(640, 480) {}

protected:
    void _handle_event(const base::EventRef &event) override
    {
        auto type = static_cast<window::BaseEvent::EventType>(event->get_event_type());
        if (type == window::BaseEvent::EventType::Key)
        {
            auto e = base::get_if<window::KeyEvent>(event);
            std::cout << e->key_code << ", " << e->action << std::endl;
        }
        else if (type == window::BaseEvent::EventType::Resized)
        {
            auto e = base::get_if<window::ResizedEvent>(event);
            std::cout << e->size.x << ", " << e->size.y << std::endl;
        }
    }
};

int main()
{
    window::glfw::init_glfw();
    {
        MyWindow win;
        while (win.is_open())
            window::glfw::glfw_poll_events();
    }
    window::glfw::term_glfw();

    return 0;
}
