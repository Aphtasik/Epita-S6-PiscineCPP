#include "stack-empty.hh"
#include "stack-max-size.hh"
#include "stack-creation-failed.hh"
#include "stack.hh"

#include <iostream>
#include <ostream>

template <class T>
Stack<T>::Stack(size_t max_size)
{
    max_size_=max_size;
}


template <class T>
Stack<T>& Stack<T>::push(const T& item)
{
    try
    {
        items_.push_back(item);
        return *this;
    }
    catch (std::exception e)
    {
        std::string msg = "Unable to push, stack max size reached.";
        throw StackMaxSize(msg);
    }
}

template <class T>
Stack<T>& Stack<T>::operator+=(const T& item)
{
    try
    {
        items_.push_back(item);
        return *this;
    }
    catch (std::exception e)
    {
        std::string msg = "Unable to push, stack max size reached.";
        throw StackMaxSize(msg);
    }
}

template <class T>
Stack<T>& Stack<T>::operator<< (const T& item)
{
    try
    {
        items_.push_back(item);
        return *this;
    }
    catch (std::exception e)
    {
        std::string msg = "Unable to push, stack max size reached.";
        throw StackMaxSize(msg);
    }
}

template <class T>
T Stack<T>::pop()
{
    try
    {
        T item = items_.pop_back();
        return item;
    }
    catch (std::exception e)
    {
        std::string msg = "Unable to pop, stack is empty.";
        throw StackEmpty(msg);
    }
}

template <class T>
T Stack<T>::operator--()
{
    try
    {
        T item = items_.pop_back();
        return item;
    }
    catch (std::exception e)
    {
        std::string msg = "Unable to pop, stack is empty.";
        throw StackEmpty(msg);
    }
}

template <class T>
T Stack<T>::operator[](size_t i)
{
    try
    {
        return items_.at(i);
    }
    catch (std::exception e)
    {
        std::string msg = "Out of range.";
        throw std::out_of_range(msg);
    }
}

template <class T>
bool Stack<T>::operator==(Stack s1)
{
    try
    {
        return max_size_ == s1.max_size_ && items_ == s1.items_;
    }
    catch (std::exception e)
    {
        throw std::exception(e);
    }
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& s) const
{
    if (items_.size() == 0)
        return s;

    for (int i = items_.size() - 1; i > 0; i--)
    {
        s << items_.at(i) << " ";
    }
    s << items_.at(0);
}

template <class T>
const_iterator Stack<T>::begin() const
{
    
}

template <class T>
iterator Stack<T>::begin()
{

}

template <class T>
const_iterator Stack<T>::end() const
{

}

template <class T>
iterator Stack<T>::end()
{

}

template <class T>
void Stack<T>::resize(size_t t)
{
    if (t == max_size_)
        return;
    else if (t < max_size_)
    {
        while (max_size_ > t)
            items_.pop_back();
    }
    else
    {
        max_size_= t;
    }
}

template <class T>
size_t Stack<T>::max_size() const
{
    return max_size_;
}

template <class T>
std::ostream& Stack<T>::operator<<(std::ostream& ostr, const Stack<T>& p)
{
    
}
