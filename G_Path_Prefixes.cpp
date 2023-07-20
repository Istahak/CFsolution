#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<tuple<int, int, int>> adj[N];
int n;
int ans[N];
ll cur = 0;
vector<ll> add;
void dfs(int v, int p, int curb, int curr)
{
    cur += curb;
    if (add.size() == 0)
        add.push_back(curr);
    else
        add.push_back(add.back() + curr);
    auto lw = [&]()
    {
        int ans = -1;
        int l = 0, r = add.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (add[m] <= cur)
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return ans;
    };
    ans[v] = (lw() == -1 ? 0 : lw() + 1);
    for (auto [u, bb, rr] : adj[v])
    {
        if (u == p)
            continue;
        dfs(u, v, bb, rr);
    }
    cur -= curb;
    add.pop_back();
}
void reset(int n)
{
    for (int i = 0; i <= n; i++)
        adj[i].clear(), ans[i] = 0;
    add.clear();
    cur = 0;
}
void solve()
{
    cin >> n;
    reset(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int u, v = i, b, r;
        cin >> u >> b >> r;
        adj[v].emplace_back(u, b, r);
        adj[u].emplace_back(v, b, r);
    }
    for (auto [u, _, __] : adj[1])
    {
        dfs(u, 1, _, __);
    }
    for (int i = 2; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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