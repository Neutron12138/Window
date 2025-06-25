#pragma once

#include <glm/glm.hpp>
#include <base/base.hpp>

namespace window
{
    class BaseEvent;
    using BaseEventRef = base::Ref<BaseEvent>;
    using BaseEventWeakRef = base::WeakRef<BaseEvent>;

    /// @brief 事件基类
    class BaseEvent : public base::Event
    {
    public:
        /// @brief 事件类型
        enum class EventType : base::Int64
        {
            /// @brief 无
            None,
            /// @brief 窗口关闭
            Closed,
            /// @brief 窗口大小改变
            Resized,
            /// @brief 按键按下或松开
            Key,
        };

    public:
        BaseEvent() = default;
        ~BaseEvent() override = default;
    };

} // namespace window
