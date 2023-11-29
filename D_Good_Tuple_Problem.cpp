#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
int vis[N];
int col[N];
bool dfs(int v, int c)
{
    if (vis[v])
    {
        if (c == col[v])
            return true;
        else
            return false;
    }
    vis[v] = true;

    col[v] = c;
    bool ans = true;
    for (auto u : adj[v])
    {
        ans &= dfs(u, c ^ 1);
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < m; i++)
    {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    memset(col, -1, sizeof(col));
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ok &= dfs(i, 0);
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
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