#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    struct Node
    {
        int val;
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
            Node tem;
            tem.val = 0; // need change
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
    void Updateseg(int ind, int low, int high, int l, int r, ll val)
    {

        if (low > r or high < l)
        {
            return;
        }
        if (low >= l and r >= high)
        {
            seg[ind].val ^= val;
            return;
        }
        int mid = (low + high) >> 1;

        Updateseg(2 * ind + 1, low, mid, l, r, val);

        Updateseg(2 * ind + 2, mid + 1, high, l, r, val);

        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    Node marge(Node &a, Node &b)
    {
        Node c;
        c.val = a.val ^ b.val;
        return c;
    }
};
void solve()
{
    int n;
    cin >> n;

    vector<ll> v(n);
    vector<ll> vz(n);
    for (auto &x : v)
        cin >> x;
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero ^= v[i];
            vz[i] = v[i];
        }
        else
        {
            one ^= v[i];
            vz[i] = 0;
        }
    }
    SegTree stz(n), stt(n);
    stz.BuildTree(0, 0, n - 1, vz);
    stt.BuildTree(0, 0, n - 1, v);

    int q;
    cin >> q;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 2)
        {
            int g;
            cin >> g;
            if (g == 1)
            {
                // int ans = stt.seg[0].val ^ stz.seg[0].val;
                cout << one << ' ';
            }
            else
            {
                cout << zero << ' ';
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            // int lrzreo = bt0.sum(l, r);
            // auto lrzero = stz.QuerySeg(0, 0, n - 1, l, r);
            auto lrtotal = stt.QuerySeg(0, 0, n - 1, l, r);

            // int lrtotal = btt.sum(l, r);
            // cout << lrzreo << ' ' << lrtotal << endl;
            zero ^= (lrtotal.val);
            one ^= (lrtotal.val);
            // cout << pp << endl;
            // stz.Updateseg(0, 0, n - 1, l, r, pp);
            // bt0.add(l, r, pp);
            // cout << bt0.sum(n) << endl;
        }
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