#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N], vis(N);
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k == 1)
    {
        cout << n << endl;
        return;
    }
    if (k >= 3)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> side(n + 1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st)
    {
        if (side[st] == -1)
        {
            q.push(st);
            side[st] = 0;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int u : adj[v])
                {
                    if (side[u] == -1)
                    {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    }
                    else
                    {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }
    if (!is_bipartite)
    {
        cout << 1 << endl;
        return;
    }
    int fc = 0, cs = 0;
    for (int i = 1; i <= n; i++)
    {
        if (side[i] == 1)
            fc++;
        if (side[i] == 0)
            cs++;
    }
    cout << max(fc, cs) << endl;
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