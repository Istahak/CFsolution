#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6;
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    ll ans = 0;
    vector<ll> sz(n + 1, 1);
    function<void(int)> dfs = [&](int v) -> void
    {
        for (auto u : adj[v])
        {
            dfs(u);
            sz[v] += sz[u];
        }
    };
    dfs(1);
    function<ll(vector<ll>, int)> f = [&](vector<ll> cur, int sum) -> ll
    {
        ll mx = 0;
        bitset<N> bs = 1;
        for (auto x : cur)
        {
            bs |= (bs << x);
        }
        for (ll i = 0; i < sum; i++)
        {
            if (bs[i])
            {
                mx = max(mx, i * (sum - i));
            }
        }

        return mx;
    };
    function<void(int)> dfs1 = [&](int v) -> void
    {
        vector<ll> cur;
        for (auto u : adj[v])
        {
            cur.emplace_back(sz[u]);
        }

        ans += f(cur, sz[v] - 1);
        for (auto u : adj[v])
        {
            dfs1(u);
        }
    };
    dfs1(1);
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