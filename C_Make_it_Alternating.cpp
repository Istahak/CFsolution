#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int M = 998244353, N = 2e5 + 10;
ll fact[N + 10], invfact[N + 10];
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
void solve()
{
    string s;
    cin >> s;
    ll cnt = 0;
    int n = s.size();
    int i = 0;
    ll ans1 = 0, ans2 = 1;
    while (i < n)
    {
        cnt = 1;
        while (i < n - 1 and s[i] == s[i + 1])
            cnt++, i++;
        i++;
        ans1 += (cnt - 1);
        if (cnt != 1)
        {

            ans2 = (ans2 % M) * (ncr(cnt, cnt - 1) % M);
            ans2 %= M;
        }
    }
    ans2 = (ans2 % M) * (fact[ans1] % M);
    ans2 %= M;
    cout << ans1 << ' ' << ans2 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    factorialcul();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}