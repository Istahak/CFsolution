#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
const int N = 510;
ll fact[15];
void solve()
{
    int n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    ll ans = 0;
    for (auto &p : mp)
    {
        ll x = p.first;
        ll y = p.second;
        for (int i = 0; i < 31; ++i)
        {
            ans += (bool)(y & 1);
            x <<= 1LL;
            y >>= 1LL;
            if (mp.find(x) != mp.end())
            {
                mp[x] += y;
                break;
            }
            // y += mp[x];
            // mp[x] = 0;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    fact[0] = 1LL;
    for (ll i = 1; i <= 10; ++i)
        fact[i] = fact[i - 1] * i;
    // cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        // cout << "Case " << tt << ": ";
        solve();
    }
    return 0;
}