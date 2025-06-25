#pragma once

#include "base_event.hpp"
#include "enums.hpp"

namespace window
{
    /// @brief 按键事件
    class KeyEvent : public BaseEvent
    {
    public:
        /// @brief 键码
        const Key key_code;
        /// @brief 动作
        const Action action;

    public:
        KeyEvent(Key kc, Action act) : key_code(kc), action(act) {}
        ~KeyEvent() override = default;

    public:
        base::Int64 get_event_type() const override { return static_cast<base::Int64>(EventType::Key); }
    };

} // namespace window
