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
    void BuildTree(string &s, int n)
    {

        Buildseg(0, 0, n - 1, s);
    }
    void Update(int index, char c, int n)
    {
        Updateseg(0, 0, n - 1, index, c);
    }
    int query()
    {
        auto [ans, _, a_] = seg[0];
        return ans;
    }

private:
    void Buildseg(int ind, int low, int high, string &s)
    {
        if (low == high)
        {
            auto &[val, fdot, sdot] = seg[ind];
            if (s[low] == '.')
            {
                val = 0;
                fdot = 1;
                sdot = 1;
            }
            else
            {
                val = 0;
                fdot = 0;
                sdot = 0;
            }
            return;
        }
        int mid = (low + high) >> 1;
        Buildseg(2 * ind + 1, low, mid, s);
        Buildseg(2 * ind + 2, mid + 1, high, s);
        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2], mid, low, high);
    }

    void Updateseg(int ind, int low, int high, int x, char c)
    {

        if (low == high)
        {
            auto &[val, fdot, sdot] = seg[ind];
            if (c == '.')
            {
                val = 0;
                fdot = 1;
                sdot = 1;
            }
            else
            {
                val = 0;
                fdot = 0;
                sdot = 0;
            }

            return;
        }
        int mid = (low + high) >> 1;
        if (x <= mid)
            Updateseg(2 * ind + 1, low, mid, x, c);
        else
            Updateseg(2 * ind + 2, mid + 1, high, x, c);

        seg[ind] = marge(seg[2 * ind + 1], seg[2 * ind + 2], mid, low, high);
    }
    tuple<int, int, int> marge(tuple<int, int, int> &a, tuple<int, int, int> &b, int mid, int low, int high)
    {
        tuple<int, int, int> ans;
        auto &[ansval, ansdot, ansf] = ans;
        auto &[aval, adot, af] = a;
        auto &[bval, bdot, bf] = b;
        ansval = aval + bval - max(af - 1, 0) - max(bdot - 1, 0) + max(af + bdot - 1, 0);
        if (adot == mid - low + 1)
            ansdot = adot + bdot;
        else
            ansdot = adot;

        if (bf == (high - (mid + 1) + 1))
            ansf = af + bf;
        else
            ansf = bf;
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegTree ST(n);
    ST.BuildTree(s, n);
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        ST.Update(x, c, n);
        cout << ST.query() << endl;
    }

    return 0;
}