#include "exist.hh"

template <typename T>
bool Exist<T>::operator()(T t)
{
    if (std::find(vec.begin(), vec.end(), t) == vec.end())
    {
        vec.push_back(t);
        return false;
    }
    return true;
}
