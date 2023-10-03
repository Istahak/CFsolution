#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
vector<pair<int, int>> adj[N];
vector<int> Z;
int vis[N];
ll tot = 0;
ll ans = 0;
void dfs(int v)
{

    for (auto [u, w] : adj[v])
    {

        
        tot += (w ^ 1);
        dfs(u);
    }
}
ll cur = 0;
void dfs1(int v)
{

    for (auto [u, w] : adj[v])
    {

        if (w)
        {
            ans += (tot - cur);
            ans %= mod;
        }
        else
        {
            cur++;
        }
        dfs1(u);
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int v, wt;
            cin >> v >> wt;
            adj[i + 1].push_back({v, wt});
        }
    }
    dfs(1);
    // cout << tot << endl;
    dfs1(1);
    // for (auto x : Z)
    //     cout << x << ' ';
    // cout << endl;
    // int sz = Z.size();
    // vector<ll> v(sz, 0);
    // v[sz - 1] = !(Z.back());
    // ll ans = 0;
    // for (int i = sz - 2; i >= 0; i--)
    // {
    //     v[i] += v[i + 1] + !(Z[i]);
    // }
    // for (int i = 0; i < sz; i++)
    // {

    //     if (Z[i])
    //     {
    //         ans += v[i];
    //         ans %= mod;
    //     }
    // }
    cout << ans << endl;
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