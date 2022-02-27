#include "closer-to.hh"

#include <algorithm>

CloserTo::CloserTo(int i)
    : i_(i){};

bool CloserTo::operator()(const int& a, const int& b) const
{
    return (i_ - a >= b - i_);
}

