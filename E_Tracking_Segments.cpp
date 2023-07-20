#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> seg(m);
    for (auto &[x, y] : seg)
        cin >> x >> y;
    int q;
    cin >> q;
    vector<int> qq(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qq[i];
    }
    int ans = -1;
    int lo = 0, hi = q - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        FenwickTree bt(n + 1);
        bool ok = false;
        for (int i = 0; i <= mid; i++)
        {
            bt.add(qq[i], 1);
        }
        for (auto [l, r] : seg)
        {
            int len = r - l + 1;
            int one = bt.sum(l, r);
            int zero = len - one;
            if (one > zero)
                ok = true;
        }
        if (ok)
        {
            hi = mid - 1;
            ans = mid + 1;
        }
        else
            lo = mid + 1;
    }

    cout << ans << endl;
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