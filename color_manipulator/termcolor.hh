#pragma once

#include <iostream>
#include <memory>

namespace termcolor
{
    enum class background : unsigned int
    {
        black = 40,
        red = 41,
        green = 42,
        yellow = 43,
        blue = 44,
        magenta = 45,
        cyan = 46,
        white = 47
    };

    enum class foreground : unsigned int
    {
        black = 30,
        red = 31,
        green = 32,
        yellow = 33,
        blue = 34,
        magenta = 35,
        cyan = 36,
        white = 37
    };

    class my_ostream
    {
    public:
        my_ostream(int code, std::ostream& out);
        ~my_ostream();

        std::ostream& out;
        std::string suffix = "m";
        std::string prefix = "\x1B[";
        int color;
    };

    my_ostream operator<<(std::ostream& out, background value);
    my_ostream operator<<(std::ostream& out, foreground value);
    my_ostream&& operator<<(my_ostream&& ost, foreground);
    my_ostream&& operator<<(my_ostream&& ost, background);
    my_ostream&& operator<<(my_ostream&& ost,
                            std::ostream& (*fn)(std::ostream&));

    template <typename T>
    my_ostream&& operator<<(my_ostream&& ost, T rhs)
    {
        ost.out << rhs;
        return std::move(ost);
    }

} // namespace termcolor
