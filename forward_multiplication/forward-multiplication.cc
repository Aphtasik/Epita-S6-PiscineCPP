#include "forward-multiplication.hh"

lambda_type create_lambda()
{
    return [](int a) 
    { 
        return [a](int b)
        { 
            return a * b; 
        }; 
    };
}
