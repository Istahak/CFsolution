#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    vector<tuple<int, int, int>> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(vector<int> &a, int n)
    {
        Buildseg(0, 0, n - 1, a);
    }
    int Query(int l, int r, int n)
    {

        auto [x, y, ans] = QuerySeg(0, 0, n - 1, l, r);
        return 2 * ans;
    }

private:
    void Buildseg(int ind, int low, int high, vector<int> &a)
    {
        if (low == high)
        {
            auto &[x, y, z] = seg[ind];
            if (a[low] == -1)
                y = 1, x = 0, z = 0;
            else
                x = 1, y = 0, z = 0;
            return;
        }
        int mid = (low + high) >> 1;
        Buildseg(2 * ind + 1, low, mid, a);
        Buildseg(2 * ind + 2, mid + 1, high, a);

        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    tuple<int, int, int> marge(tuple<int, int, int> &a, tuple<int, int, int> &b)
    {
        auto &[lo, lc, lf] = a;
        auto &[ro, rc, rf] = b;
        tuple<int, int, int> ans;
        auto &[anso, ansc, ansf] = ans;
        ansf = min(lo, rc) + lf + rf;
        anso = lo + ro - min(lo, rc);
        ansc = lc + rc - min(lo, rc);
        return ans;
    }
    tuple<int, int, int> QuerySeg(int ind, int low, int high, int l, int r)
    {
        if (low > r or high < l)
        {
            return {0, 0, 0};
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
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            v[i] = 1;
        else
            v[i] = -1;
    }
    int q;
    cin >> q;
    SegTree ST(n);
    ST.BuildTree(v, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << ST.Query(l, r, n) << endl;
    }

    return 0;
}