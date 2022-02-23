#pragma once

#include <iostream>
#include <vector>
#include <string>

template <class T>
bool palindrome(std::vector<T> v)
{
    auto left = v.begin();
    auto right = v.rbegin();

    for (; left != v.end() || right != v.rend(); ++left, ++right)
    {
        if (*left != *right)
            return false;
    } 
    return true;
}
