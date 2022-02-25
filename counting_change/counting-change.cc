constexpr long long count(long long S[], int m, int n)
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;

    if (m <= 0 && n >= 1)
        return 0;

    return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
}

constexpr long long count_change(const long long amount)
{
    long long values[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
    long long total = count(values, 7, amount);
    return total;
}
