#pragma once

// Requires clause used in a concept
template <typename A, typename B = A>
concept impl_basic_op = requires(A a, B b)
{ // Requirement sequence
    {
        +a
        } -> std::convertible_to<A>;
    {
        -a
        } -> std::convertible_to<A>;
    {
        a + b
        } -> std::convertible_to<A>;
    {
        a - b
        } -> std::convertible_to<A>;
    {
        a* b
        } -> std::convertible_to<A>;
    {
        a / b
        } -> std::convertible_to<A>;
};

template <typename A, typename B = A>
concept impl_modulo = requires(A a, B b)
{
    { a % b };
};

template <typename A, typename B = A>
concept impl_bitwise_op = requires(A a, B b)
{
    {
        a& b
        } -> std::convertible_to<A>;
    {
        a | b
        } -> std::convertible_to<A>;
    {
        a ^ b
        } -> std::convertible_to<A>;
    {
        ~a
        } -> std::convertible_to<A>;
    {
        a << b
        } -> std::convertible_to<A>;
    {
        a >> b
        } -> std::convertible_to<A>;
};

template <typename A, typename B = A>
concept impl_arith_op =
    impl_basic_op<A, B> && impl_modulo<A, B> && impl_bitwise_op<A, B>;
