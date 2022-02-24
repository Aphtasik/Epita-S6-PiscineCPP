#include "list.hh"

#include <iostream>

List::List()
{
    nb_elts_ = 0;
    first_ = nullptr;
    last_ = nullptr;
}

void List::push_front(int i)
{
    auto node = std::make_shared<Node>(Node(i));
    node->next_set(first_);
    nb_elts_++;

    first_ = node;
    if (nb_elts_ == 1)
        last_ = node;
}

void List::push_back(int i)
{
    auto node = std::make_shared<Node>(Node(i));
    node->prev_set(last_);
    nb_elts_++;

    last_ = node;
    if (nb_elts_ == 1)
        first_ = node;
}

std::optional<int> List::pop_front()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        std::optional<int> node = first_->val_get();
        last_ = nullptr;
        first_ = nullptr;
        nb_elts_--;
        return node;
    }

    std::optional<int> node = first_->val_get();
    first_ = first_->next_get();
    nb_elts_--;

    if (nb_elts_ == 1)
        last_ = first_;
    return node;
}

std::optional<int> List::pop_back()
{
    if (nb_elts_ == 0)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        std::optional<int> node = last_->val_get();
        last_ = nullptr;
        first_ = nullptr;
        nb_elts_--;
        return node;
    }

    std::optional<int> node = last_->val_get();
    last_ = last_->prev_get();
    nb_elts_--;

    if (nb_elts_ == 1)
        first_ = last_;
    return node;
}
void List::print(std::ostream& os) const
{
    if (nb_elts_ == 0)
        return;

    std::shared_ptr<Node> node = first_;
    for (int i = 0; i < nb_elts_ - 1; i++)
    {
        os << node->val_get() << " ";
        node = node->next_get();
    }
    os << last_->val_get();
}
int List::length() const
{
    return nb_elts_;
}
