#include "int-container.hh"

MyIntContainer::MyIntContainer(size_t size)
{
    this->elems_ = std::make_unique<int[]>(size);
    this->current_size_ = 0;
    this->max_size_ = size;
}

void MyIntContainer::print() const
{
    for (int i = 0; i < current_size_ - 1; i++)
    {
        std::cout << elems_[i] << " | ";
    }

    std::cout << elems_[current_size_ - 1] << "\n";
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ == max_size_)
        return false;

    current_size_++;
    elems_[current_size_] = elem;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    
}
