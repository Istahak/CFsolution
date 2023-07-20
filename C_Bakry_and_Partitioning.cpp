#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N], flag(N), v(N);
int x, cnt;
void dfs(int vertex, int parent)
{
    flag[vertex] = v[vertex];
    for (auto child : adj[vertex])
    {
        if (child == parent)
            continue;

        dfs(child, vertex);

        flag[vertex] ^= flag[child];
    }
    if (flag[vertex] == x)
        cnt++, flag[vertex] = 0;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    x = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i], x ^= v[i], adj[i].clear(), flag[i] = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (x == 0)
    {
        cout << "YES\n";
        return;
    }
    if (k == 2)
    {
        cout << "NO\n";
        return;
    }
    dfs(1, -1);
    // cout<<cnt<<endl;
    cout << (cnt < 2 ? "NO" : "YES") << endl;
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