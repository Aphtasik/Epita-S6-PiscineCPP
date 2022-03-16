#pragma once

#include <iostream>

class StackCreationFailed : public std::exception
{
public:
    StackCreationFailed(std::string& msg);
    virtual const char* what() const noexcept;

private:
    std::string msg_;
};
