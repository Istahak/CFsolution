#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
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
const int N = 2e5 + 10;
ll pr[3];
ll dp[N];
ll f(int cur)
{
    if (cur <= 0)
        return 0;
    ll &ret = dp[cur];
    if (~ret)
        return ret;
    ret = 1 + mulmod(pr[2], f(cur - 2)) + mulmod(pr[1], f(cur - 1));
    ret %= mod;
    return ret;
}
void solve()
{
    int n, p;
    cin >> n >> p;
    pr[2] = mulmod(p, power(100, mod - 2));
    pr[1] = mulmod(100 - p, power(100, mod - 2));
    memset(dp, -1, sizeof(dp));
    cout << f(n) % mod << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}