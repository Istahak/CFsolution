#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 5002;
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
int dp[N];
int n, m;
FenwickTree bt(N + 1);
int f(int id)
{
    if (id == n)
        return 0;
    int &ret = dp[id];
    if (~ret)
        return ret;
    ret = -1e9;
    for (int k = id; k < n; k++)
    {
        int sum = bt.sum(id, k);
        int len = k - id + 1;
        len /= 2;
        if (sum > len)
        {
            ret = max(ret, f(k + 1) + 1);
        }
       
    }
    return ret;
}
void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= m)
            bt.add(i, 1);
    }
    memset(dp, -1, sizeof(dp));
    cout << max(f(0),0) << endl;
    
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