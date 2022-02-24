#pragma once

#include <cmath>
#include <iostream>

template <class Iterator>
void my_foreach(Iterator i1, Iterator i2, std::is_function<Iterator> f)
{
    while (i1 != i2)
    {
        *i1 = f(*i1);
        i1++;
    }
}
