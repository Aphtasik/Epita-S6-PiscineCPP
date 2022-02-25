#include "invalid-argument.hh"

InvalidArgumentException::InvalidArgumentException(const std::string& msg)
{
    msg_=msg;
}
