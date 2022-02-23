#include "path.hh"

Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_)
        return *this;

    if (is_file)
        final_ = true;
    path_.push_back(tail);
    return *this;
}
