#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    ll k, c;
    cin >> n >> k >> c;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int source)
    {
        vector<ll> dis(n + 1, -1);
        queue<int> q;
        q.push(source);
        dis[source] = 0;
        while (!q.empty())
        {
            auto v = q.front();
            q.pop();
            for (auto child : adj[v])
            {
                if (dis[child] == -1)
                {
                    dis[child] = dis[v] + 1;
                    q.push(child);
                }
            }
        }
        return dis;
    };
    auto dist = bfs(1);
    auto fn = max_element(dist.begin(), dist.end()) - dist.begin();
    auto dist1 = bfs(fn);
    auto ffn = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    auto dist2 = bfs(ffn);
    ll best = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ll profit = max(dist1[i], dist2[i]) * k;
        ll cost = dist[i] * c;
        best = max(best, profit - cost);
    }
    cout << best << endl;
    
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