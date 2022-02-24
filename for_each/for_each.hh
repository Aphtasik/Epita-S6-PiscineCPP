#pragma once

#include <iostream>

template <typename Iterator, typename Function>
void my_foreach(Iterator i1, Iterator i2, Function f)
{
    while (i1 != i2)
    {
        f(*i1);
        i1++;
    }
}
