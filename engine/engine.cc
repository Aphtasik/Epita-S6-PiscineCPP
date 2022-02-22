#include "engine.hh"

Engine::Engine(int fuel)
{
    this->fuel_ = fuel;
}

bool Engine::start()
{
    if (fuel_ < 1)
        return false;

    fuel_--;
    std::cout << "Engine starts with " << fuel_ << " units of fuel\n";
    return true;
}

void Engine::use(int consumed)
{
    int used;
    if (consumed > fuel_)
    {
        used = fuel_;
        fuel_ = 0;
    }
    else
    {
        used = consumed;
        fuel_ -= consumed;
    }
    std::cout << "Engine uses " << used << " fuel units\n";
}

void Engine::stop() const
{
    std::cout << "Stop Engine\n";
}

void Engine::fill(int fuel)
{
    fuel_ += fuel;
    std::cout << "Engine now has " << fuel_ << " fuel units\n";
}
