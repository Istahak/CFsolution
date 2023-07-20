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
vector<tuple<int, int, int>> edg;
int n, m;
ll MST()
{
    DSU g(n);
    sort(edg.begin(), edg.end());
    ll totcost = 0;
    for (auto [w, u, v] : edg)
    {
        if (g.find_set(u) == g.find_set(v))
            continue;
        totcost += w;
        g.marge(u, v);
    }

    return totcost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.emplace_back(w, u, v);
    }
    ll ans = MST();
    cout<<ans<<endl;

    return 0;
}