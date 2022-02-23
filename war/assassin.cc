#include "assassin.hh"

Assassin::Assassin()
    : Soldier()
{
    this->dmg_ = 9;
    this->health_ = 10;
    this->scream_ = "Out of the shadows!";
}

void Assassin::attack(Soldier& s)
{
    Soldier::attack(s);
}

void Assassin::print_state() const
{
    Soldier::print_state();
}

void Assassin::scream() const
{
    Soldier::scream();
}
