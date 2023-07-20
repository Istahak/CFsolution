#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
vector<int> adj[N + 1], cost(N + 1), vis(N + 1);
int cur_cost = INT_MAX;
int n, m;
void dfs(int vertex)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    cur_cost = min(cur_cost, cost[vertex]);
    for (auto child : adj[vertex])
    {
        dfs(child);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans += cur_cost;
            cur_cost = INT_MAX;
        }
    }
    cout << ans << endl;

    return 0;
}