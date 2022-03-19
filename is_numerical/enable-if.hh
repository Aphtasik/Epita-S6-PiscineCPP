#pragma once

// Implementation c++11 of enable_if cppreference
template <bool B, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<true, T>
{
    typedef T type;
};
