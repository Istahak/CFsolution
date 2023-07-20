#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m, u, L, k;
    cin >> n >> m >> u >> L >> k;
    k--;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int ans = INT_MIN;
    queue<int> q;
    q.emplace(u);
    vector<int> dis(n + 1, 1e9);
    dis[u] = 0;
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        for (auto [child, w] : adj[v])
        {
            if (dis[child] == 1e9)
            {
                dis[child] = dis[v] + 1;
                q.emplace(child);
            }
            if (dis[child] <= k)
            {
                ans = max(ans, w);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("path.in", "r", stdin);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}