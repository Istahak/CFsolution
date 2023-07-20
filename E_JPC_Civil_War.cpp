#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i, size[i] = 1;
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void marge(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> g(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g[i] = {t, u, v};
    }
    vector<pair<int, int>> b(k);
    for (auto &[u, v] : b)
        cin >> u >> v;
    sort(g.rbegin(), g.rend());
    int ans = -1;
    int l = 0, r = m;
    while (l <= r)
    {
        int mi = (l + r) / 2;
        DSU st(n + 1);
        for (int i = 0; i < mi; i++)
        {
            auto [t, u, v] = g[i];
            st.marge(u, v);
        }
        bool ok = true;
        for (auto [u, v] : b)
        {
            if (st.find_set(u) == st.find_set(v))
                ok = false;
        }
        if (ok)
        {
            ans = mi ;
            l = mi + 1;
        }
        else
            r = mi - 1;
    }
    if (ans == -1)
    {
        auto [__, u, v] = g.back();
        cout << __ << endl;
    }
    else
    {
        auto [__, u, v] = g[ans];
        cout << __ << endl;
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