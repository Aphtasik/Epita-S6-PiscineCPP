#include "exist.hh"

template <class T>
bool Exist<T>::operator()(T t)
{
    if (std::find(vec.begin(), vec.end(), t) != vec.end())
        return true;
    return false;
}