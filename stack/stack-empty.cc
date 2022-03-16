#include "stack-empty.hh"

StackEmpty::StackEmpty(std::string& msg)
{
    msg_ = msg;
}

const char* StackEmpty::what() const noexcept
{
    return msg_.c_str();
}
