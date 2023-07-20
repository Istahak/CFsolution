#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    vector<vector<int>> seg;
    SegTree(int n)
    {
        seg.assign(4 * n + 1, vector<int>(26, 0));
    }
    void BuildTree(int ind, int low, int high, string &s)
    {
        if (low == high)
        {
            auto &v = seg[ind];
            v[s[low] - 'A'] = 1;
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid, s);
        BuildTree(2 * ind + 2, mid + 1, high, s);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    vector<int> QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            vector<int> tem(26, 0);
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
            auto &v = seg[ind];
            v.assign(26,0);
            v[val] = 1;
            return;
        }
        int mid = (low + high) >> 1;
        if (x <= mid)
            Updateseg(2 * ind + 1, low, mid, x, val);
        else
            Updateseg(2 * ind + 2, mid + 1, high, x, val);

        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    vector<int> marge(vector<int> &a, vector<int> &b)
    {
        auto ans = a;
        for (int i = 0; i < 26; i++)
            ans[i] += b[i];
        return ans;
    }
};
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    SegTree ST(n);
    ST.BuildTree(0, 0, n - 1, s);
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'g')
        {
            auto ans = ST.QuerySeg(0, 0, n - 1, l, r);
            for (auto x : ans)
                cout << x << ' ';
            cout << endl;
        }
        if (c == 's')
        {

            auto ans = ST.QuerySeg(0, 0, n - 1, l, r);
            int j = 0;
            for (int i = l; i <= r && j < 26;)
            {
                while (ans[j]-- && i <= r)
                {
                    ST.Updateseg(0, 0, n - 1, i, j);
                    i++;
                }
                j++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt, cs = 1;
    tt = 1;
    cin >> tt;
    while (tt--)
    {
        cout << "Case #" << cs++ << ":" << endl;
        solve();
    }
    return 0;
}