#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int M = 1e9 + 7, N = 200000 + 5;
ll fact[N], invfact[N];
ll bigmod(ll a, ll b)
{
    a %= M;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
void factorialcul()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = ((fact[i - 1] % M) * (i % M)) % M;
    }
    invfact[N - 1] = bigmod(fact[N - 1], M - 2);
    for (int i = N - 2; i >= 0; --i)
    {
        invfact[i] = ((invfact[i + 1] % M) * (i + 1)) % M;
    }
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0ll;
    ll res = fact[n] % M;
    res = res * (invfact[n - r] % M);
    res %= M;
    res = res * (invfact[r] % M);
    res %= M;
    return res;
}
const int mod = 1e9 + 7;

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
ll f(ll h, ll w)
{
    ll ans = fact[h + w];
    ans = mulmod(ans, invfact[h]);
    ans = mulmod(ans, invfact[w]);
    return ans;
}
void solve()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for (int i = h - a, j = b + 1; i > 0 and j <= w; i--, j++)
    {
        ans += (f(i - 1, j - 1) * f(h - i, w - j)) % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    factorialcul();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}