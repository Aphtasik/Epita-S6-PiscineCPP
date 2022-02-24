#include <iostream>

template <typename It, typename F>
void my_foreach(It i1, It i2, F f)
{
    while (i1 != i2)
    {
        f(*i1);
        ++i1;
    }
}
