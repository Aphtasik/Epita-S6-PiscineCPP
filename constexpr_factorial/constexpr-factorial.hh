constexpr unsigned long long factorial(unsigned int n)
{
    unsigned long res = 0;
    for (unsigned int i = 1; i <= n; i++)
        res *= i;
    return res;
}