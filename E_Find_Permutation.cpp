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
    vector<int> adj[n];
    vector<int> d(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        d[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    vector<int> order;
    while (!q.empty())
    {
        if (q.size() != 1)
        {
            cout << "No" << '\n';
            return;
        }
        int v = q.front();
        q.pop();
        order.push_back(v);
        for (auto u : adj[v])
        {
            d[u]--;
            if (d[u] == 0)
                q.emplace(u);
        }
    }
    if (order.size() != n)
    {
        cout << "No" << '\n';
        return;
    }
    vector<int> ans(n);
    int val = 1;
    for (auto x : order)
    {
        ans[x] = val++;
    }
    cout << "Yes" << '\n';
    for (auto x : ans)
        cout << x << ' ';
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