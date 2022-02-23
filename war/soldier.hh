#pragma once

#include <iostream>
#include <string>

class Soldier
{
public:
    Soldier();
    virtual void attack(Soldier& s);
    virtual void print_state() const;
    virtual void scream() const;

protected:
    int health_;
    int dmg_;
    std::string scream_;
};
