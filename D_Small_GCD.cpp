#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(), v.end());
    int mx = v.back();
    vector<int> fr[mx + 1];
    for (int i = 0; i < n; i++)
    {
        fr[v[i]].push_back(i);
    }
    vector<ll> dp(mx + 1);
    for (int i = mx; i > 0; i--)
    {
        ll now = 0;
        vector<pair<int, int>> cur;
        for (int j = i; j <= mx; j += i)
        {
            for (auto x : fr[j])
                cur.push_back({x, j});
        }
        for (int j = i; j <= mx; j += i)
        {
            dp[i] -= dp[j];
        }
        int sz = cur.size();
        for (int k = 0; k < sz; k++)
        {
            ll gg = (k * 1LL * (n - cur[k].first - 1));
            dp[i] += gg;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= mx; i++)
    {
        ans += dp[i] * 1LL * i;
    }
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