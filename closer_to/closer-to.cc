#include "closer-to.hh"

#include <iostream>
#define F(x) ((x < 0) ? -x : x)

CloserTo::CloserTo(int i)
{
    this->i_ = i;
}

bool CloserTo::operator()(const int& a, const int& b) const
{
    auto nb = i_ - b;
    auto na = i_ - a;

    // ABS
    nb = F(nb);
    na = F(na);
    if (na == nb)
    {
        return a <= b;
    }
    return na < nb;
}
