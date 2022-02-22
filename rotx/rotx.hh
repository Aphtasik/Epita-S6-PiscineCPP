#include "encrypt.hh"

class RotX : public Encrypt 
{
private:
    std::string text_;
    int rot_;
public:
    RotX(std::string text, int rot);
    void process();
    ~RotX();
};