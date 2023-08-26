#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, m;
vector<int> adj[55];
bool vis[55];
void dfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis[u])
            dfs(u);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i);
        int cc = 0;
        for (int i = 1; i <= n; i++)
        {
            cc += vis[i];
        }
        if (cc == n)
        {
            st.insert(i);
        }
    }
    if (st.size() == 1)
    {
        cout << *st.begin() << endl;
    }
    else
        cout << -1 << endl;
}
int main()
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