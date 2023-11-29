#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 3e5 + 10;
vector<int> st[N];
class SegTree
{
public:
    struct Node
    {
        // need change
        vector<int> val;
    };

    vector<Node> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(int ind, int low, int high)
    {
        if (low == high)
        {
            auto &c = seg[ind];

            c.val = st[low];
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid);
        BuildTree(2 * ind + 2, mid + 1, high);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    int QuerySeg(int ind, int low, int high, int l, int r, int val)
    {
        if (low > r or high < l or low > high)
        {
            Node tem; // need change
            return 0;
        }
        if (low >= l and r >= high)
        {
            auto &v = seg[ind].val;
            int lo = lower_bound(v.begin(), v.end(), val) - v.begin();
            lo = v.size() - lo;
            return lo;
        }
        int mid = (low + high) >> 1;
        auto left = QuerySeg(2 * ind + 1, low, mid, l, r, val);
        auto right = QuerySeg(2 * ind + 2, mid + 1, high, l, r, val);
        return left + right;
    }
    Node marge(Node &a, Node &b)
    {
        Node ans;
        ans.val.resize(a.val.size() + b.val.size());
        merge(a.val.begin(), a.val.end(), b.val.begin(), b.val.end(), ans.val.begin());
        return ans;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        st[s].push_back(e);
    }
    for (int i = 0; i < N; i++)
    {
        if (st[i].empty())
            continue;
        sort(st[i].begin(), st[i].end());
    }
    SegTree stt(N);
    stt.BuildTree(0, 0, N - 1);
    while (q--)
    {
        int k;
        cin >> k;
        int l = 1, ans = 0;
        for (int i = 0; i < k; i++)
        {
            int r;
            cin >> r;
            ans += stt.QuerySeg(0, 0, N - 1, l, r, r);
            l = r + 1;
        }

        cout << ans << '\n';
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
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}