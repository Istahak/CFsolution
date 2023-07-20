#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    vector<pair<int, int>> seg;
    SegTree(int n)
    {
        seg.assign(4 * n + 1, {0, 1e9});
    }
    void BuildTree(int ind, int low, int high, vector<int> &v)
    {
        if (low == high)
        {
            auto &c = seg[ind];
            c.first = v[low];
            c.second = v[low];
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid, v);
        BuildTree(2 * ind + 2, mid + 1, high, v);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    pair<int, int> QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            pair<int, int> tem = {0, 1e9};
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

    pair<int, int> marge(pair<int, int> &a, pair<int, int> &b)
    {
        auto ans = a;
        int mx = max(a.first, b.first);
        int mn = min(a.second, b.second);
        ans = {mx, mn};
        return ans;
    }
};
void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    SegTree st(n + 1);
    st.BuildTree(0, 0, n, v);
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            auto [mx, mn] = st.QuerySeg(0, 0, n, i, m);
            if (mx - mn <= 1)
                l = m + 1;
            else
                r = m - 1;
        }
        ans = max(ans, l - i);
    }
    cout << ans << endl;
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