#include <iostream>
#include <string>

class Encrypt
{
    public:
        Encrypt(const std::string& input);
        virtual void process() = 0;
};
