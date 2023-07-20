#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
int w[N], mx[N], mn[N], mxsum[N], mnsum[N];
void dfs(int v, int p = -1)
{
    if (p == -1)
    {
        mx[1] = 1, mn[1] = 0, mxsum[1] = 1, mnsum[1] = 0;
    }
    else
    {
        mxsum[v] = max(mxsum[p] + w[v], w[v]);
        mx[v] = max(mxsum[v], mx[p]);
        mnsum[v] = min(mnsum[p] + w[v], w[v]);
        mn[v] = min(mnsum[v], mn[p]);
    }
    for (auto u : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n + 5; i++)
        adj[i].clear(), w[i] = 0, mx[i] = 0, mxsum[i] = 0, mn[i] = 0, mnsum[i] = 0;
    w[1] = 1;
    int cur = 2;
    vector<tuple<int, int, int>> q;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int u = cur, v, wt;
            cin >> v >> wt;
            adj[u].push_back(v);
            adj[v].push_back(u);
            w[u] = wt;
            cur++;
        }
        else
        {
            int u, v, k;
            cin >> u >> v >> k;
            q.emplace_back(u, v, k);
        }
    }
    dfs(1);
    for (auto [u, v, k] : q)
    {
        cout << ((mn[v] <= k and k <= mx[v]) ? "YES" : "NO") << endl;
    }
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