#include "soldier.hh"

class Assassin : public Soldier
{
public:
    Assassin();
    void attack(Soldier& s) override;
    void print_state() const override;
    void scream() const override;
};
