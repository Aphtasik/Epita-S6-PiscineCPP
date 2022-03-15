#include "closer-to.hh"

#include <iostream>
#define ABS(x) ((-x) ? (x < 0) : (x))

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    return (ABS(i_ - a) < ABS(i_ - b));
}
