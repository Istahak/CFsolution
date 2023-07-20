#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct FenwickTree
{
    vector<ll> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r)
    {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void add(int l, int r, ll val)
    {
        add(l, val);
        add(r + 1, -val);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    vector<tuple<int, int, ll>> rr(m);
    for (auto &x : a)
        cin >> x;
    for (auto &[l, r, d] : rr)
        cin >> l >> r >> d;
    FenwickTree bt(m + 2);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        bt.add(x, y, 1);
    }
    FenwickTree ans(n + 2);
    for (int i = 0; i < m; i++)
    {
        auto [l, r, d] = rr[i];
        ans.add(l, r, d * bt.sum(i + 1));
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] + ans.sum(i + 1) << ' ';
    }
    cout << endl;
    return 0;
}