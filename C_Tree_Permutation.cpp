#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
long long int sz[N];
long double sum = 0;
void dfs(int v, int p = -1)
{
    sz[v] = 1;
    for (auto u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }
}
void dfs1(int v, int p = -1)
{
    for (auto u : adj[v])
    {
        if (u != p)
        {
            long long int child = sz[u];
            sz[v] -= child;
            sum += sz[v] * sz[u] * 2;
            sz[u] += sz[v];
            dfs1(u, v);
            sz[v] += child;
        }
    }
}
void solve()
{
    double n;
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        adj[i].clear();
        sz[i] = 0;
        sum = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    dfs1(1);
    double ans = sum / n;
    cout << fixed << setprecision(7) << ans << endl;
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