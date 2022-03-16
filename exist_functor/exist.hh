#pragma once

#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

template <class T>
class Exist
{
public:
    bool operator()(T);

private:
    std::vector<T> vec;
};

#include "exist.hxx"
