#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
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
    cin >> n >> m;
    DSU st(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        st.merge(u, v);
    }
    int k;
    cin >> k;
    set<int> con[n];
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        con[st.root(u)].insert(st.root(v));
        con[st.root(v)].insert(st.root(u));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v)
            swap(u, v);
        if (con[st.root(u)].count(st.root(v)))
            cout << "No" << '\n';

        else
            cout << "Yes" << '\n';
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
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}