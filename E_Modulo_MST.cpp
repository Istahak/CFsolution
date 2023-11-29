#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct DSU
{
    int n, sz;
    vector<int> p; // root: -1 * component size, otherwise: parent
    DSU(int n) : n(n), sz(n), p(n, -1) {}
    bool same(int a, int b) { return root(a) == root(b); }
    int root(int a) { return p[a] < 0 ? a : (p[a] = root(p[a])); }
    int size(int a) { return -p[root(a)]; }
    int size() { return sz; }
    bool merge(int a, int b, bool rank = true)
    {
        int x = root(a), y = root(b);
        if (x == y)
            return false;
        sz--;
        if (rank and -p[x] < -p[y])
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
    vector<vector<int>> groups()
    {
        vector<int> _root(n), sz(n);
        for (int i = 0; i < n; i++)
            _root[i] = root(i), sz[_root[i]]++;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
            g[i].reserve(sz[i]);
        for (int i = 0; i < n; i++)
            g[_root[i]].push_back(i);
        auto empty = [&](const vector<int> &v)
        { return v.empty(); };
        g.erase(remove_if(g.begin(), g.end(), empty), g.end());
        return g;
    }
};
void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<tuple<int, int, ll>> edg(m);
    for (auto &[u, v, w] : edg)
        cin >> u >> v >> w;
    vector<int> v(m, 0);
    for (int i = 0; i < n - 1; i++)
    {
        v[i] = 1;
    }
    sort(v.begin(), v.end());
    ll ans = LLONG_MAX;
    do
    {
        ll cur = 0;
        DSU st(n);
        for (int i = 0; i < m; i++)
        {
            if (v[i])
            {
                auto [u, v, w] = edg[i];

                st.merge(u - 1, v - 1);
                cur += w;
            }
        }

        if (st.size() == 1)
        {

            ans = min(ans, cur % k);
        }

    } while (next_permutation(v.begin(), v.end()));
    cout << ans << '\n';
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