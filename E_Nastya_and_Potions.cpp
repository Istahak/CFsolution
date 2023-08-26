#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
vector<ll> adj[N], vis(N), v(N), ans(N);
set<ll> st;
ll dfs(int ver)
{
    // if (st.count(ver))
    //     return ans[ver] = 0;
    vis[ver] = 1;
    if (st.count(ver))
        return ans[ver] = 0;
    if (adj[ver].size() == 0)
    {

        return ans[ver] = min(ans[ver], v[ver]);
    }
    ll sum = 0;
    // cout << ver << ' ' << endl;
    for (auto u : adj[ver])
    {
        if (vis[u])
        {
            sum += ans[u];
            continue;
        }
        sum += dfs(u);
    }
    return ans[ver] = min({v[ver], sum, ans[ver]});
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i <= n + 7; i++)
    {
        adj[i].clear();
        vis[i] = 0;
        ans[i] = LLONG_MAX;
    }
    st.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }

    for (int i = 1; i <= n; i++)
    {
        int sz;
        cin >> sz;
        if (sz == 0)
        {
            if (st.count(i))
                ans[i] = 0;
            else
                ans[i] = v[i];
        }
        else
        {
            for (int j = 1; j <= sz; j++)
            {
                int u;
                cin >> u;
                // if (st.count(u))
                //     continue;
                // if (st.count(j))
                //     continue;
                adj[i].push_back(u);
                // adj[u].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        // if (st.count(i))
        //     cout << 0 << ' ';
        // else
        cout << ans[i] << ' ';
    }
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