#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<bool> vis(N);
vector<int> adj[N];
void dfs(int v)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
}
void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        // sz[i] = 0;
        vis[i] = false;
    }
    // ans.clear();
}
void solve()
{
    int n;
    cin >> n;
    reset(n);
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    map<pair<int, int>, bool> mp;
    for (int i = 0; i < n; i++)
    {
        // adj[i + 1].clear();

        if (!mp[{i + 1, v[i]}] and !mp[{v[i], i + 1}])
        {
            adj[i + 1].push_back(v[i]);
            adj[v[i]].push_back(i + 1);
            mp[{i + 1, v[i]}] = true;
            mp[{v[i], i + 1}] = true;
        }
    }
    int mn = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            mx++;
            mn++;
            dfs(i);
        }
    }
    int cc = -2;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() == 1)
        {
            cc++;
        }
    }
    cc = max(0, cc);
    mn -= (cc / 2);
    cout << mn << ' ' << mx << endl;
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