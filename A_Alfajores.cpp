#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    struct Node
    {
        // need change
        int x;
    };

    vector<Node> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(int ind, int low, int high, vector<ll> &v)
    {
        if (low == high)
        {
            auto &c = seg[ind];
            // need change
            c.x = v[low];
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
            Node tem; // need change
            tem.x = INT_MAX;
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
    void Updateseg(int ind, int low, int high, int x, ll val)
    {

        if (low == high)
        {
            auto &c = seg[ind];
            // need change
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
        ans.x = min(a.x, b.x);

        return ans;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    SegTree st(m);
    st.BuildTree(0, 0, m - 1, a);
    // cout << st.QuerySeg(0, 0, m - 1, 0, 2).x << '\n';
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cur < m - 1)
        {
            if (v[i] == 0)
                break;
            int l = cur;
            int r = m - 1;
            int ans = -1;
            while (l <= r)
            {
                int mid = (l + r);
                int mx = st.QuerySeg(0, 0, m - 1, l, mid).x;
                if (mx <= v[i])
                {
                    r = mid - 1;
                    ans = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (ans == -1)
                break;
            v[i] %= a[ans];
            cur = ans;
            if (cur == m - 1)
            {
                v[i] %= a[m - 1];
                break;
            }
        }
        cout << v[i] << ' ';
        cur = 0;
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