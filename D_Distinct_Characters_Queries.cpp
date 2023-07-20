#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    vector<vector<bool>> seg;
    SegTree(int n)
    {
        seg.assign(4 * n + 1, vector<bool>(26, false));
    }
    void BuildTree(int ind, int low, int high, string &s)
    {
        if (low == high)
        {
            auto &v = seg[ind];
            v[s[low] - 'a'] = true;
            return;
        }
        int mid = (low + high) >> 1;
        BuildTree(2 * ind + 1, low, mid, s);
        BuildTree(2 * ind + 2, mid + 1, high, s);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    vector<bool> QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            vector<bool> tem(26, false);
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
            v.assign(26, false);
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

    vector<bool> marge(vector<bool> &a, vector<bool> &b)
    {
        auto ans = a;
        for (int i = 0; i < 26; i++)
            ans[i] = ans[i] | b[i];
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    SegTree ST(n);
    ST.BuildTree(0, 0, n - 1, s);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index;
            char c;
            cin >> index >> c;
            index--;
            ST.Updateseg(0, 0, n - 1, index, c - 'a');
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto ansa = ST.QuerySeg(0, 0, n - 1, l, r);
            int ans = 0;
            for (auto x : ansa)
                ans += x;
            cout << ans << endl;
        }
    }

    return 0;
}