#include "knight.hh"

Knight::Knight()
    : Soldier()
{
    this->dmg_ = 5;
    this->health_ = 20;
    this->scream_ = "Be quick or be dead!";
}

void Knight::attack(Soldier& s)
{
    Soldier::attack(s);
}

void Knight::print_state() const
{
    Soldier::print_state();
}

void Knight::scream() const
{
    Soldier::scream();
}
