#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<pair<int, int>> adj[N];
int n;
vector<bool> ok(N);
int ans;

void reset()
{
    for (int i = 0; i < n + 6; i++)
    {
        adj[i].clear();
        ok[i] = false;
    }
}
void solve()
{
    cin >> n;
    reset();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    ans = 1;
    queue<pair<int, int>> q;
    vector<int> vis(n + 1, false);
    for (auto [u, i] : adj[1])
        q.emplace(u, i), vis[u] = true;
    while (!q.empty())
    {
        bool ok = false;
        auto [v, pre] = q.front();
        q.pop();
        for (auto [u, i] : adj[v])
        {
            if (vis[u] == false)
            {
                if (pre > i)
                    ok = true;
                q.emplace(u, i);
                vis[u] = true;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
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