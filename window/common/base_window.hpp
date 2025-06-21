#pragma once

#include "base_event.hpp"

namespace window
{
    class BaseWindow;
    using BaseWindowRef = base::Ref<BaseWindow>;
    using BaseWindowWeakRef = base::WeakRef<BaseWindow>;

    /// @brief 窗口基类
    class BaseWindow : public base::EventHandler
    {
    public:
        BaseWindow() = default;
        ~BaseWindow() override = default;

    public:
        virtual bool is_open() const = 0;
        virtual glm::ivec2 get_position() const = 0;
        virtual glm::ivec2 get_size() const = 0;
        virtual std::string get_title() const = 0;

        virtual void close_window() = 0;
        virtual void set_position(const glm::ivec2 &position) = 0;
        virtual void set_size(const glm::ivec2 &size) = 0;
        virtual void set_title(const std::string &title) = 0;
        virtual void set_icon(const base::BaseImageRef &image) = 0;

    public:
        void request_handle_event(const base::EventRef &event) override
        {
            if (!BaseEvent::convert(event))
                throw std::runtime_error(base::to_string(
                    "Unsupported event: Event@", event.get(),
                    ", event type: ", event->get_event_type()));

            EventHandler::request_handle_event(event);
        }
    };

} // namespace window
