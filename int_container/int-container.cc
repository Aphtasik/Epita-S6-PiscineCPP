#include "int-container.hh"

MyIntContainer::MyIntContainer(size_t size)
{
    this->elems_ = std::make_unique<int[]>(size);
    this->current_size_ = 0;
    this->max_size_ = size;
}

void MyIntContainer::print() const
{
    for (long unsigned int i = 0; i < current_size_ - 1; i++)
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

    elems_[current_size_] = elem;
    current_size_++;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return std::nullopt;

    current_size_--;
    return std::optional<int>(elems_[current_size_]);
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position > current_size_ - 1)
        return std::nullopt;

    return std::optional<int>(elems_[position]);
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elems_[i] == elem)
            return std::optional<size_t>(i);
    }
    return std::nullopt;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(std::unique_ptr<int[]>& arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void MyIntContainer::sort()
{
    bubbleSort(elems_, current_size_);
}

bool MyIntContainer::is_sorted() const
{
    if (current_size_ == 1)
        return true;

    int prec = elems_[0];
    for (long unsigned int i = 1; i < current_size_; i++)
    {
        if (elems_[i] < prec)
            return false;
        prec = elems_[i];
    }
    return true;
}
