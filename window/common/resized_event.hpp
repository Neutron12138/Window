#pragma once

#include "base_event.hpp"

namespace window
{
    /// @brief 窗口大小改变事件
    class ResizedEvent : public BaseEvent
    {
    public:
        /// @brief 窗口新大小
        const glm::ivec2 size;

    public:
        ResizedEvent(base::UInt32 width, base::UInt32 height) : size(width, height) {}
        ~ResizedEvent() = default;

    public:
        base::Int64 get_event_type() const override { return static_cast<base::Int64>(EventType::Resized); }
    };

} // namespace window
