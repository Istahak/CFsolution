#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    struct Node
    {
        // need change
        int one;
        int zero;
    };

    vector<Node> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(int ind, int low, int high, string s)
    {
        if (low == high)
        {
            auto &c = seg[ind];
            if (s[low] == '1')
            {
                c.one = 1;
                c.zero = 0;
            }
            else
            {
                c.zero = 1;
                c.one = 0;
            }
            // need change
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid, s);
        BuildTree(2 * ind + 2, mid + 1, high, s);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    Node QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            Node tem; // need change
            tem.one = INT_MIN;
            tem.zero = INT_MIN;
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
        if (a.zero == 0 and b.zero == 0)
        {
            ans.one = max({a.one + b.one, a.one, b.one});
            ans.zero = max(a.zero, b.zero);
        }
        else if (a.one == 0 and b.one == 0)
        {
            ans.zero = max({a.zero + b.zero, a.zero, b.zero});
            ans.one = max(a.one, b.one);
        }
        else
        {
            ans.one = max(a.one, b.one);
            ans.zero = max(a.zero, b.zero);
        }
        return ans;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegTree st(n);
    st.BuildTree(0, 0, n - 1, s);
    cout << st.QuerySeg(0, 0, n - 1, 2, 5).one << '\n';
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