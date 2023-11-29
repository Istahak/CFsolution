#include <bits/stdc++.h>
#define int long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, m;
    cin >> n >> m;
    int p;
    cin >> p;
    vector<pair<int, int>> point(p);
    for (auto &[x, y] : point)
        cin >> x >> y;
    int xx;
    cin >> xx;
    set<int> sx;
    for (int i = 0; i < xx; i++)
    {
        int x;
        cin >> x;
        sx.insert(x);
    }
    sx.insert(n);
    int yy;
    cin >> yy;
    set<int> sy;
    sy.insert(m);
    for (int i = 0; i < yy; i++)
    {
        int y;
        cin >> y;
        sy.insert(y);
    }
    map<pair<int, int>, int> fr;
    for (auto &[x, y] : point)
    {
        int xp = *sx.lower_bound(x);
        int yp = *sy.lower_bound(y);
        fr[{xp, yp}]++;
    }
    int mi = LLONG_MAX, mx = LLONG_MIN;
    for (auto [x, y] : fr)
        mx = max(y, mx), mi = min(y, mi);
    if ((xx + 1) * 1LL * (yy + 1) != fr.size())
        mi = 0;
    cout << mi << ' ' << mx << '\n';
}
int32_t main()
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