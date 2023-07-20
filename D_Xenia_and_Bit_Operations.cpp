#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class SegTree
{
public:
    vector<int> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void BuildTree(vector<int> &a, int n)
    {
        int ele = a.size();
        if (n & 1)
            Buildseg(0, 0, ele - 1, a, true);
        else
            Buildseg(0, 0, ele - 1, a, false);
    }
    void Update(vector<int> &a, int index, int val, int n)
    {
        int ele = a.size();
        if (n & 1)
            Updateseg(0, 0, ele - 1, index, val, a, true);
        else
            Updateseg(0, 0, ele - 1, index, val, a, false);
    }

private:
    void Buildseg(int ind, int low, int high, vector<int> &a, bool isor)
    {
        if (low == high)
        {
            seg[ind] = a[low];
            return;
        }
        int mid = (low + high) >> 1;
        Buildseg(2 * ind + 1, low, mid, a, isor ^ 1);
        Buildseg(2 * ind + 2, mid + 1, high, a, isor ^ 1);
        if (isor)
            seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else
            seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }

    void Updateseg(int ind, int low, int high, int x, int val, vector<int> &a, bool isor)
    {

        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (x <= mid)
            Updateseg(2 * ind + 1, low, mid, x, val, a, isor ^ 1);
        else
            Updateseg(2 * ind + 2, mid + 1, high, x, val, a, isor ^ 1);

        if (isor)
            seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else
            seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> v(1 << n);
    for (auto &i : v)
        cin >> i;
    SegTree ST(1 << n);
    ST.BuildTree(v, n);
    while (q--)
    {
        int x, val;
        cin >> x >> val;
        x--;
        ST.Update(v, x, val, n);
        cout << ST.seg[0] << endl;
    }

    return 0;
}