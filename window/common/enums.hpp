#pragma once

#include <base/base.hpp>

namespace window
{
    /// @brief 按键
    enum class Key : base::Int32
    {
        Unknown = -1,
        None = 0,

        Backspace = 8,
        Tab,
        Enter = 13,
        Escape = 27,

        Space = ' ',
        Exclamation = '!',
        DoubleQuote = '"',
        Hash = '#',
        Dollar = '$',
        Percent = '%',
        Ampersand = '&',
        SingleQuote = '\'',
        LeftParen = '(',
        RightParen = ')',
        Asterisk = '*',
        Plus = '+',
        Comma = ',',
        Minus = '-',
        Period = '.',
        Slash = '/',

        Num0 = '0',
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,

        Colon = ':',
        Semicolon = ';',
        Less = '<',
        Equal = '=',
        Greater = '>',
        Question = '?',
        At = '@',

        A = 'A',
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,

        LeftBracket = '[',
        Backslash = '\\',
        RightBracket = ']',
        Caret = '^',
        Underscore = '_',
        Grave = '`',

        LeftBrace = '{',
        Bar = '|',
        RightBrace = '}',
        Tilde = '~',

        F1 = 256,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,

        Up,
        Down,
        Left,
        Right,
        PageUp,
        PageDown,
        Home,
        End,
    };

    /// @brief 动作
    enum class Action : base::Int32
    {
        Unknown = -1,
        None = 0,

        Pressed,
        Released,
        Echo,
    };

    /// @brief 鼠标按键
    enum class MouseButton : base::Int32
    {
        Unknown = -1,
        None = 0,

        Left,
        Middle,
        Right,
        Extra1,
        Extra2,
    };

} // namespace window
