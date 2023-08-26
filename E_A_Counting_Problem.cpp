#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int mod = 998244353;
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
void solve()
{
    long long int a, n;
    cin >> n >> a;
    mod = 3;
    long long int ans = power(5LL, a);
    ans = mulmod(ans, power(10LL, n - a));
    long long r = 3 - ans % 3;
    mod = 998244353;
    ans = power(5LL, a);
    ans = mulmod(ans, power(10LL, n - a));
    ans = addmod(ans, r);
    ans = mulmod(ans, power(3, mod - 2));
    cout << ans % mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}