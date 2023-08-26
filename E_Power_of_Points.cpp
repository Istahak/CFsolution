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

    FenwickTree(vector<int> const &a) : FenwickTree(a.size())
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
    vector<ll> v(n), vv(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vv = v;
    sort(v.begin(), v.end());
    FenwickTree bt(n + 1);
    for (int i = 0; i < n; i++)
    {
        bt.add(i, v[i]);
    }
    ll total = accumulate(v.begin(), v.end(), 0LL);
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(v.begin(), v.end(), vv[i]) - v.begin();
        it--;
        ll sum1 = bt.sum(it);
        ll cnt1 = it + 1;
        ll sum2 = total - sum1;
        ll cnt2 = n - cnt1;
        ll ans = cnt1 * vv[i] - sum1 + cnt1;
        ans += (sum2 - cnt2 * vv[i] + cnt2);
        cout << ans << ' ';
    }
    cout << endl;
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