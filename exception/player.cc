#include "player.hh"

#include <exception>
#include <iostream>
#include <string>

Player::Player(const std::string& name, unsigned int age)
{
    if (name.empty())
    {
        throw InvalidArgumentException("Name can't be empty.");
    }
    else if (age > 150)
    {
        throw InvalidArgumentException("Sorry gramp, too old to play.");
    }
    name_ = name;
    age_ = age;
}
