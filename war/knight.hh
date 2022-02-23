#include "soldier.hh"

class Knight : public Soldier
{
public:
    Knight();
    void attack(Soldier& s) override;
    void print_state() const override;
    void scream() const override;
};
