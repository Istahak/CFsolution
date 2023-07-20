#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 200000 + 10;
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }
};
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    FenwickTree bt(N + 1), btt(N + 1);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        bt.add(l, r, 1);
    }
    for (int i = 0; i < N; i++)
    {
        int kk = bt.sum(i);
        if (kk >= k)
            btt.add(i, 1);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << btt.sum(l, r) << endl;
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