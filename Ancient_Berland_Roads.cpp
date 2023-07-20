#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5e5 + 10;
int n, m, q;
stack<int> wt[N];
vector<pair<int, int>> edg(N);
vector<bool> deleted(N);
vector<tuple<char, int, int>> query(N);
multiset<ll> values;
int par[N];
int sz[N];
int64_t comwt[N];
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}
void marge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    values.erase(values.find(comwt[v]));
    values.erase(values.find(comwt[u]));

    comwt[u] += comwt[v];
    comwt[v] = 0;
    values.emplace(comwt[u]);
}
void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        wt[i].emplace(x);
    }
    for (int i = 1; i <= m; i++)
    {
        auto &[u, v] = edg[i];
        cin >> u >> v;
    }
    for (int i = 1; i <= q; i++)
    {
        auto &[type, index, value] = query[i];
        cin >> type >> index;
        if (type == 'D')
        {
            deleted[index] = true;
        }
        if (type == 'P')
        {
            cin >> value;
            wt[index].emplace(value);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        values.emplace(wt[i].top());
        comwt[i] = wt[i].top();
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (deleted[i])
            continue;
        auto [u, v] = edg[i];
        marge(u, v);
    }
    stack<int64_t> ans;
    for (int i = q; i >= 1; i--)
    {
        auto anss = *values.rbegin();
        ans.emplace(anss);
        auto &[type, index, value] = query[i];
        if (type == 'D')
        {
            auto [u, v] = edg[index];
            marge(u, v);
        }
        if (type == 'P')
        {
            int root = find(index);
            int old = wt[index].top();
            values.erase(values.find(comwt[root]));
            comwt[root] -= old;
            wt[index].pop();
            int cur = wt[index].top();
            comwt[root] += cur;
            values.emplace(comwt[root]);
        }
    }
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
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