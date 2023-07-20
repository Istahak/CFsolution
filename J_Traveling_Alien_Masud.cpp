#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> g[N], r[N], vec;
void dfs1(int vertex)
{
    vis[vertex] = 1;
    for (auto child : g[vertex])
        if (!vis[child])
            dfs1(child);
    vec.push_back(vertex);
}
void dfs2(int vertex, vector<int> &comp)
{
    comp.push_back(vertex);
    vis[vertex] = 1;
    for (auto child : r[vertex])
        if (!vis[child])
            dfs2(child, comp);
}
void reset(int n)
{
    vec.clear();
    for (int i = 0; i <= n + 1; i++)
    {
        g[i].clear();
        r[i].clear();
        vis[i] = false;
    }
}
void solve()
{
    int n, m;
    cin >> n;
    cin >> m;
    reset(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        r[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    reverse(vec.begin(), vec.end());

    memset(vis, 0, sizeof vis);
    int scc = 0;
    vector<vector<int>> store;
    for (auto u : vec)
    {
        if (!vis[u])
        {
            vector<int> comp;
            dfs2(u, comp);
            scc++;
            store.push_back(comp);
        }
    }
    vector<int> ans;
    for (auto vv : store)
    {
        ans.push_back((int)vv.size());
    }
    sort(ans.rbegin(), ans.rend());
    if (ans.size() == 1)
    {
        cout << ans[0] << endl;
    }
    else
    {
        cout << ans[0] + ans[1] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        memset(vis, 0, sizeof vis);
        solve();
    }

    return 0;
}