#include "soldier.hh"

Soldier::Soldier()
{
    this->health_ = 15;
    this->dmg_ = 3;
    this->scream_ = "No pity for losers!";
}

void Soldier::attack(Soldier& s)
{
    s.health_ = s.health_ - dmg_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << health_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << scream_ << "\n";
}

