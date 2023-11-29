#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    ll n;
    cin >> n;
    ll sq = sqrtl(n);
    ll ans = LLONG_MAX;
    vector<ll> v;
    for (ll i = 0; i <= sq; i++)
    {
        v.push_back(i * i);
    }
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        ll x = v[i];
        auto it = upper_bound(v.begin(), v.end(), n - x);
        if (it != v.end())
        {
            ll y = (*it);
            ans = min(ans, abs(x + y - n));
        }
        if (it != v.begin())
        {
            it--;
            ll y = (*it);
            ans = min(ans, abs(x + y - n));
        }
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
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}