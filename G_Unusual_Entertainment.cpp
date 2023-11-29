#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
class SegTree
{
public:
    struct Node
    {
        // need change
        int val;
    };

    vector<Node> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(int ind, int low, int high, vector<int> &v)
    {
        if (low == high)
        {
            auto &c = seg[ind];
            // need change
            c.val = v[low];
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid, v);
        BuildTree(2 * ind + 2, mid + 1, high, v);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    Node QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            Node tem;
            tem.val = 1e9; // need change
            return tem;
        }
        if (low >= l and r >= high)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        auto left = QuerySeg(2 * ind + 1, low, mid, l, r);
        auto right = QuerySeg(2 * ind + 2, mid + 1, high, l, r);
        return marge(left, right);
    }
    void Updateseg(int ind, int low, int high, int x, int val)
    {

        if (low == high)
        {
            auto &c = seg[ind];
            // need change
            c.val = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (x <= mid)
            Updateseg(2 * ind + 1, low, mid, x, val);
        else
            Updateseg(2 * ind + 2, mid + 1, high, x, val);

        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    Node marge(Node &a, Node &b)
    {
        auto ans = a;
        // need change
        ans.val = min(a.val, b.val);

        return ans;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = -1;
    vector<int> in(n), out(n), order;
    function<void(int, int)> dfs = [&](int v, int p)
    {
        in[v] = ++timer;
        order.push_back(v);
        for (auto u : adj[v])
        {
            if (u == p)
                continue;
            dfs(u, v);
        }
        out[v] = timer;
    };
    dfs(0, -1);

    vector<int> p(n);
    for (auto &x : p)
        cin >> x, x--;
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        pos[p[i]] = i;
        p[i] = in[p[i]];
    }
    SegTree st(n);
    st.BuildTree(0, 0, n - 1, p);
    vector<vector<tuple<int, int, int>>> query(n);
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        query[x].emplace_back(l, r, i);
    }
    vector<string> ans(q, "NO");

    for (int i = 0; i < n; i++)
    {
        int cur = order[i];
        for (auto [l, r, id] : query[cur])
        {
            int mi = st.QuerySeg(0, 0, n - 1, l, r).val;
            if (mi <= out[cur])
                ans[id] = "YES";
        }
        st.Updateseg(0, 0, n - 1, pos[cur], 1e9);
    }

    for (auto x : ans)
        cout << x << '\n';
    cout << '\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}