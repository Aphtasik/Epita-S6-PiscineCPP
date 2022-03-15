#pragma once

#include <string>

#include "leaf.hh"
#include "node.hh"
#include "tree.hh"
#include "visitor.hh"

namespace visitor
{
    class ComputeVisitor : public Visitor
    {
    public:
        void visit(const tree::Tree& e) override;
        void visit(const tree::Node& e) override;
        void visit(const tree::Leaf& e) override;

        int value_get();

    private:
        int value_ = 0;
    };
} // namespace visitor