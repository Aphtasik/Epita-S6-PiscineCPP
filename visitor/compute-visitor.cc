#include "compute-visitor.hh"

namespace visitor
{

    void ComputeVisitor::visit(const tree::Tree& e)
    {
        e.accept(*this);
    }
    void ComputeVisitor::visit(const tree::Node& e)
    {
        auto operation = e.value_get();
        e.lhs_get()->accept(*this);
        e.rhs_get()->accept(*this);

        int x = value_;
        switch (operation.at(0))
        {
        case '+':
            value_ += x;
            break;
        case '-':
            value_ = x - value_;
            break;
        case '*':
            value_ *= x;
            break;
        case '/':
            if (value_ != 0)
            {
                value_ = x / value_;
                break;
            }
            else
            {
                throw std::overflow_error("Divide by zero exception");
                break;
            }
        }
    }
    void ComputeVisitor::visit(const tree::Leaf& e)
    {
        value_ = stoi(e.value_get());
    }

    int ComputeVisitor::value_get()
    {
        return value_;
    }
} // namespace visitor
