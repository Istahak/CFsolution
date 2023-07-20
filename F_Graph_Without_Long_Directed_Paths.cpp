#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N + 1];
bool vis[N];
int ans[N];
bool ok = true;
int n, m;

void dfs(int vertex, int state)
{

    ans[vertex] = state;
    vis[vertex] = 1;
    for (auto child : adj[vertex])
    {
        if (ans[vertex] == ans[child])
            ok = false;
        if (vis[child])
            continue;
        dfs(child, state ^ 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(ans, -1, sizeof(ans));
    vector<pair<int, int>> vi;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        vi.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(vi[0].first, 1);
    if (ok)
    {
        cout << "YES" << endl;
        for (auto [x, y] : vi)
            cout << (ans[x] ? 1 : 0);

        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}