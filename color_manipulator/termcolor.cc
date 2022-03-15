#include "termcolor.hh"

namespace termcolor
{
    termcolor::my_ostream::my_ostream(int code, std::ostream& out)
        : out(out)
    {
        this->color = code;
    }

    my_ostream::~my_ostream()
    {
        this->out << prefix << "0" << suffix;
    }

    my_ostream&& operator<<(my_ostream&& ost, foreground value)
    {
        ost.color = static_cast<int>(value);
        ost.out << ost.prefix;
        ost.out << ost.color << ost.suffix;
        return std::move(ost);
    }

    my_ostream&& operator<<(my_ostream&& ost, background value)
    {
        ost.color = static_cast<int>(value);
        ost.out << ost.prefix;
        ost.out << ost.color << ost.suffix;
        return std::move(ost);
    }

    my_ostream operator<<(std::ostream& out, termcolor::background value)
    {
        out << "\x1B[" << static_cast<int>(value) << "m";
        return termcolor::my_ostream(static_cast<int>(value), out);
    }

    my_ostream operator<<(std::ostream& out, termcolor::foreground value)
    {
        out << "\x1B[" << static_cast<int>(value) << "m";
        return termcolor::my_ostream(static_cast<int>(value), out);
    }

    my_ostream&& operator<<(termcolor::my_ostream&& ost,
                            std::ostream& (*fn)(std::ostream&))
    {
        ost.out << fn;
        return std::move(ost);
    }

} // namespace termcolor
