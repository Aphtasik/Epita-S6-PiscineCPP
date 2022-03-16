#pragma once

#include <iostream>

class StackEmpty : public std::exception
{
public:
    StackEmpty(std::string& msg);
    virtual const char* what() const noexcept;

private:
    std::string msg_;
};
