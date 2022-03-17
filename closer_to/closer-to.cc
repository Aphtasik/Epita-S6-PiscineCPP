#include "closer-to.hh"

#include <iostream>
#define F(x) ((-x) ? (x < 0) : (x))

CloserTo::CloserTo(int i)
{
    this->i_ = i;
}

bool CloserTo::operator()(const int& a, const int& b) const
{
    int na = F(i_ - a);
    int nb = F(i_ - b);
    if (na == nb)
        return a <= b;
    return (na < nb);
}
