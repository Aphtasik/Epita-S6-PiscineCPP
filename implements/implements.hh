#pragma once


// Requires clause used in a concept
template <typename T>
concept impl_basic_op = requires
{ // Requirement sequence
    T::operator+;
    T::operator-;
    T::operator*;
    T::operator/;
};
