#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N], vis(N);
vector<int> G[N];
int n;
vector<int> ans;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (vis[v])
            continue;
        dfs(v);
    }
    ans.push_back(u);
}
void solve()
{
    cin >> n;
    vector<int> inDegree(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            G[x].push_back(i);
            inDegree[i]++;
        }
    }
    dfs(1);
   
    for (int i = 0; i < ans.size()-1; i++)
        cout << ans[i] << ' ';
    cout << endl;
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