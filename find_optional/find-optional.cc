#include "find-optional.hh"

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    for (long unsigned int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) == value)
        {
            return std::optional<std::size_t>(i);
        }
    }
    return std::nullopt;
}
