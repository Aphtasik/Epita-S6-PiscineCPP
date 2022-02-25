#include "stack-max-size.hh"

StackMaxSize::StackMaxSize(std::string& msg)
{
    msg_=msg;
}

const char* StackMaxSize::what() const noexcept
{
    return msg_.c_str();
}
