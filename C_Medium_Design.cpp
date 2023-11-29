#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp1;
    map<ll, ll> mp2;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > 1)
        {
            mp1[l]++, mp1[r + 1]--;
        }
        if (r < m)
        {
            mp2[l]++, mp2[r + 1]--;
        }
    }
    auto f = [&](map<ll, ll> mp)
    {
        vector<pair<ll, ll>> diff;
        for (auto [x, y] : mp)
        {
            diff.push_back({x, y});
        }
        int sz = diff.size();
        for (int i = 1; i < sz; i++)
            diff[i].second += diff[i - 1].second;
        ll ans = 0;
        for (auto [x, y] : diff)
            ans = max(ans, y);
        return ans;
    };
    cout << max(f(mp1), f(mp2)) << '\n';
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