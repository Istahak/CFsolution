//https://atcoder.jp/contests/abc328/tasks/abc328_f
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    vector<ll> val;
    vector<vector<int>> nodes;
    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        nodes.resize(n + 1);
        val.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i, size[i] = 1, nodes[i] = {i};
    }
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    bool same_com(int u, int v)
    {
        return find_set(u) == find_set(v);
    }
    void merge(int a, int b, ll w)
    {
        int ra = find_set(a);
        int rb = find_set(b);
        if (ra != rb)
        {

            if (size[ra] < size[rb])
            {
                swap(a, b);
                swap(ra, rb);
                w = -w;
            }
            parent[rb] = ra;
            size[ra] += size[rb];
            ll dd = w - (val[b] - val[a]);
            for (auto cc : nodes[rb])
            {
                val[cc] += dd;
                nodes[ra].push_back(cc);
            }
            nodes[rb].clear();
        }
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    DSU st(n);
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        if (st.same_com(u, v))
        {
            if (st.val[v] - st.val[u] == w)
            {
                cout << i << ' ';
            }
        }
        else
        {
            st.merge(u, v, w);
            cout << i << ' ';
        }
    }
    cout << '\n';
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