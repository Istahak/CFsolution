#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<int, int>> q;
    vector<int> d(n, -1);
    for (int i = 0; i < k; i++)
    {
        int u, val;
        cin >> u >> val;
        u--;
        d[u] = val;
        q.emplace(val, u);
    }
    vector<int> vis(n, false);
    vector<int> ans;
    while (!q.empty())
    {
        auto [val, v] = q.top();
        q.pop();
        if (d[v] != val)
            continue;
        for (auto u : adj[v])
        {
            if (d[u] < val - 1)
            {
                d[u] = val - 1;
                q.emplace(val - 1, u);
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (d[i] >= 0)
            ans.push_back(i);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
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