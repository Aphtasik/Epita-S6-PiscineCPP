#include "closer-to.hh"

#include <iostream>

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    return (abs(i_ - a) < abs(b - i_));
}
