#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> v[n + 1];
    map<int, ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        mp[a] = max(mp[a], b);
    }
    ll mx = 0;
    for (int i = 0; i <= n; i++)
    {
        auto vv = v[i];
        sort(vv.rbegin(), vv.rend());
        if (vv.size() >= 2)
        {
            mx = max(vv[0] / 2 + vv[1], mx);
            mx = max(vv[0] + vv[1] / 2, mx);
        }
    }
    vector<ll> f;
    for (auto [x, y] : mp)
    {
        f.push_back(y);
    }
    sort(f.rbegin(), f.rend());
    if (f.size() >= 2)
    {
        ll one = f[0];
        ll tt = f[1];
        mx = max(mx, one + tt);
        // mx = max(mx, one + tt / 2);
    }
    cout << mx << endl;
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