#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<pair<int, int>> adj[N];
int vis[N];
int pos[N];
bool ok;
void dfs(int v)
{
    vis[v] = true;
    for (auto [u, w] : adj[v])
    {
        if (vis[u])
        {
            if (pos[u] != w + pos[v])
                ok = false;
        }
        else
        {
            pos[u] = w + pos[v];
            dfs(u);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 10; i++)
    {
        adj[i].clear();
        vis[i] = 0, pos[i] = 0;
        ok = true;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << (ok ? "YES" : "NO") << endl;
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