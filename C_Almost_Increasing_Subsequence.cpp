#include <bits/stdc++.h>
#define ll long long int
using namespace std;
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
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    FenwickTree bt(n);
    for (int i = 2; i < n; i++)
    {
        if (v[i - 2] >= v[i - 1] && v[i - 1] >= v[i])
            bt.add(i, 1);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        l--, r--;
        if (ans <= 2)
            cout << ans << endl;
        else
        {
            ans -= bt.sum(l, r);

            if (l >= 2)
            {
                if (v[l - 2] >= v[l - 1] && v[l - 1] >= v[l])
                    ans += 1;
            }
            if (l != 0 && l + 1 != n)
            {
                if (v[l - 1] >= v[l] && v[l] >= v[l + 1])
                    ans += 1;
            }
            cout << ans << endl;
        }
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