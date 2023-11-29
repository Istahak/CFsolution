#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9 + 7;
long long power(long long a, long long b)
{
    a %= mod;
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
long long mulmod(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
void solve()
{
    ll L, R;
    cin >> L >> R;
    vector<ll> div;
    for (ll i = 1; i * i <= R; i++)
    {
        if (R % i == 0)
        {
            div.push_back(i);
            if (i != (R / i))
                div.push_back(R / i);
        }
    }
    sort(div.begin(), div.end());
    int sz = div.size();
    vector<ll> dp(sz, 0);
    ll ans = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        ll cur = (R / div[i]) - ((L - 1) / div[i]);
        for (int j = i + 1; j < sz; j++)
            if (div[j] % div[i] == 0)
                cur -= dp[j];
        dp[i] = cur;
        ll now = mulmod(cur, R);
        now = mulmod(now, power(div[i], mod - 2));
        ans = addmod(ans, now);
    }
    cout << ans << '\n';
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