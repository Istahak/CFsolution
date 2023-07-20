#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
vector<int> cnt(N), d(N);
void dfs(int v, int p = -1)
{
    if (cnt[v] == 1 and v!=1)
        d[v] = 1;
    else
        d[v] = 0;
    for (auto u : adj[v])
    {
        if (p == u)
            continue;
        dfs(u, v);
        d[v] += d[u];
    }
}
void reset(int n)
{
    for (int i = 0; i <= n + 1; i++)
    {
        adj[i].clear();
        cnt[i] = 0;
        d[i] = 0;
    }
}
void solve()
{
    int n;
    cin >> n;
    reset(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cnt[x]++, cnt[y]++;
    }
    dfs(1);
    // for (int i = 1; i <= n; i++)
    //     cout << d[i] << " ";
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        ll a = d[x], b = d[y];
        cout << a * b * 1LL << endl;
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