#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> m(n);
    ll ttf = 0, ttm = 0;
    for (auto &x : m)
        cin >> x, ttm += x;
    vector<ll> f(n);
    for (auto &x : f)
        cin >> x;
    vector<tuple<ll, ll, ll>> ord;
    for (int i = 0; i < n; i++)
    {
        ord.emplace_back(f[i] + m[i], f[i], m[i]);
    }
    sort(ord.rbegin(), ord.rend());
    int ans = 0;
    for (auto [_, ff, mm] : ord)
    {
        ttf += ff, ttm -= mm;
        ans++;
        if (ttf >= (ttm + w))
        {
            cout << ans << '\n';
            return;
        }
    }

    ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}