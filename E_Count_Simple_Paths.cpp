#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    function<void(int)> dfs = [&](int v)
    {
        ans++;
        if (ans >= 1e6)
            return;
        vis[v] = true;
        for (auto u : adj[v])
        {

            if (vis[u])
                continue;
            dfs(u);
            if (ans >= 1e6)
                return;
        }
        vis[v] = false;
    };
    dfs(0);

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