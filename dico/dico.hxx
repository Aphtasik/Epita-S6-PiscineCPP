#include "dico.hh"

template <typename Iterator>
Dico::Dico(Iterator begin, Iterator end)
{
    std::set<std::string> dick;
    dick.insert(begin, end);
    dico_ = dick;
}
