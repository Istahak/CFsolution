#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<pair<int, int>> adj[N];
int n;
int sz[N];
vector<int> ans;
vector<int> ra[N];
int cce = 0;
void dfs(int v, int p = -1)
{
    sz[v] = 1;
    for (auto [u, _] : adj[v])
    {
        if (u == p)
            continue;
        // cout << u << endl;
        dfs(u, v);
        sz[v] += sz[u];
    }
}
void dfs1(int v, int p = -1)
{
    for (auto [u, i] : adj[v])
    {
        if (u == p)
            continue;
        // cout << u << ' ' << sz[u] << endl;
        if (sz[u] % 3 == 0)
        {
            ans.push_back(i);
            // cout << 1 << endl;
        }
        dfs1(u, v);
    }
}
vector<bool> vis(N);
void dfs3(int v)
{
    vis[v] = true;
    cce++;
    for (auto u : ra[v])
    {
        if (vis[u])
            continue;
        dfs3(u);
    }
}
void reset()
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        sz[i] = 0;
        vis[i] = false;
        ra[i].clear();
    }
    ans.clear();
}
void solve()
{

    cin >> n;
    reset();
    vector<pair<int, int>> vv(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        vv[i] = {u, v};
    }
    if (n == 2 and n % 3 != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 3)
    {
        cout << 0 << endl;
        cout << "" << endl;
        return;
    }
    dfs(1);
    dfs1(1);
    if (ans.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    vector<bool> bb(n, true);
    for (auto &i : ans)
    {
        bb[i] = false;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (bb[i])
        {
            auto &[u, v] = vv[i];
            ra[u].push_back(v);
            ra[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cce = 0;
            dfs3(i);
            if (cce != 3)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
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