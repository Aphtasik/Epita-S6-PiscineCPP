#include "exist.hh"

template <class T>
bool Exist<T>::operator()(T t)
{
    if (std::find(vec.begin(), vec.end(), t) != vec.end())
    {
        vec.push_back(t);
        return true;
    }
    return false;
}