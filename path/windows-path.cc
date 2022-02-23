#include "windows-path.hh"

std::string WindowsPath::to_string() const
{
    std::string s;

    for (int i = 0; i < path_.size() - 1; i++)
    {
        s.append(path_.at(i));
        s.append("\\");
    }

    if (final_)
        s.append(path_.back());
    else
    {
        s.append(path_.back());
        s.append("\\");
    }
    return s;
}
