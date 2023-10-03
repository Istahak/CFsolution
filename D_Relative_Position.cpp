#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e5 + 10;
vector<tuple<int, int, int>> adj[N];
int vis[N];
int n, m;
vector<pair<int, int>> ans(N);
void dfs(int v, int curx, int cury)
{
    vis[v] = 1;
    ans[v] = {curx, cury};
    for (auto [u, x, y] : adj[v])
    {
        if (vis[u])
            continue;
        dfs(u, curx + x, cury + y);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].emplace_back(v, x, y);
        adj[v].emplace_back(u, -x, -y);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
        else
        {
            cout << "undecidable" << endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}