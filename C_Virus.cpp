#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, d;
    cin >> n >> d;
    d = d * d;
    vector<pair<int, int>> point(n);
    for (auto &[x, y] : point)
        cin >> x >> y;
    auto ifacted = [&](int x1, int y1, int x2, int y2)
    {
        int xx = x1 - x2;
        int yy = y1 - y2;
        return xx * xx + yy * yy <= d;
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto [x1, y1] = point[i];
            auto [x2, y2] = point[j];
            if (ifacted(x1, y1, x2, y2))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<string> ans(n, "No");
    function<void(int)> dfs = [&](int v)
    {
        ans[v] = "Yes";
        for (auto u : adj[v])
        {
            if (ans[u] == "No")
            {
                dfs(u);
            }
        }
    };
    dfs(0);
    for (auto x : ans)
        cout << x << '\n';
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