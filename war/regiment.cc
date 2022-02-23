#include "regiment.hh"

void Regiment::join_by(Regiment& r)
{
    for (auto elt : r.army_)
    {
        army_.push_back(elt);
    }
    r.army_.erase(r.army_.begin(), r.army_.end());
}

size_t Regiment::count() const
{
    return army_.size();
}

void Regiment::add_soldier(Soldier* s)
{
    army_.push_back(s);
}

void Regiment::print_state() const
{
    for (auto elt : army_)
    {
        elt->print_state();
    }
}

void Regiment::scream() const
{
    for (auto elt : army_)
    {
        elt->scream();
    }
}
