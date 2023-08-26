#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    struct Node
    {
        // need change
        ll val;
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
            Node tem; // need change
            tem.val = INT_MAX;
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
        ans.val = max(a.val, b.val);

        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> x;
    SegTree st(n);
    st.BuildTree(0, 0, n - 1, v);
    cout << st.seg[0].val << endl;
    set<int> track;
    for (int i = 0; i < n; i++)
        track.insert(i);
    int q;
    cin >> q;
    while (q--)
    {
        int pos;
        cin >> pos;
        pos--;
        track.erase(pos);
        auto it = track.upper_bound(pos);
        if (it == track.end())
        {
            v[n - 1] += v[pos];
            st.Updateseg(0, 0, n - 1, n - 1, v[n - 1]);
            v[pos] = 0;
            st.Updateseg(0, 0, n - 1, pos, v[pos]);
        }
        else
        {
            int cur = (*it);
            v[cur] += v[pos];
            st.Updateseg(0, 0, n - 1, cur, v[cur]);
            v[pos] = 0;
            st.Updateseg(0, 0, n - 1, pos, v[pos]);
        }
        cout << st.seg[0].val << endl;
    }
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