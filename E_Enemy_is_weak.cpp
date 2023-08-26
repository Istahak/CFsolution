#include <bits/stdc++.h>
#define int long long int
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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vp[i] = {x, i};
    }
    sort(vp.begin(), vp.end());
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = vp[i];
        v[y] = i;
    }
    FenwickTree bt(n + 1), bt1(n + 1);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += bt1.sum(v[i]);
        bt1.add(v[i], bt.sum(v[i]));
        bt.add(v[i], 1);
    }
    cout << ans << endl;
}
int32_t main()
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