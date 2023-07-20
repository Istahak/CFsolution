const int mod = 1e9 + 7;
long long power(long long a, long long b)
{
    long long x = 1;
    while (b)
    {
        if (b & 1)
            x = x * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return x;
}
long long addmod(long long a, long long b)
{
    long long ans = (a % mod + b % mod) % mod;
    return ans;
}
long long submod(long long a, long long b)
{
    long long ans = (a % mod - b % mod + mod) % mod;
    return ans;
}
long long mulmod(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}