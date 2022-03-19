#pragma once

#include "enable-if.hh"
#include "is-numerical.hh"

// enable_if c++11 cppreference Helper types
template <bool B, class T = void>
using enable_if_t = typename enable_if<B, T>::type;

// enable_if c++11 cppreference usage exemples
template <typename T, enable_if_t<is_numerical<T>::value, bool> = true>
void algorithm(T)
{}