#include <bits/stdc++.h>
#define ll long long int
using namespace std;
template <class T>
class BIT
{
public:
    int n;
    vector<T> f;
    BIT(int n) : n(n)
    {
        f.resize(n + 1, (T)0);
    }
    BIT(const vector<T> &a)
    { // O(n)
        n = a.size();
        f.assign(n + 1, (T)0);
        for (int i = 1; i <= n; i++)
        {
            f[i] += a[i - 1];
            if (i + (i & -i) <= n)
            {
                f[i + (i & -i)] += f[i];
            }
        }
    }
    void update(int p, T v)
    {
        while (p <= n)
            f[p] += v, p += p & -p;
    }
    T pref(int p)
    {
        T ret = 0;
        while (p)
            ret += f[p], p -= p & -p;
        return ret;
    }
    T range(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};
int atMostSum(vector<int> arr, int n, int k)
{
    int sum = 0;
    int cnt = 0, maxcnt = 0;

    for (int i = 0; i < n; i++)
    {

        // If adding current element doesn't
        // cross limit add it to current window
        if ((sum + arr[i]) <= k)
        {
            sum += arr[i];
            cnt++;
        }

        // Else, remove first element of current
        // window and add the current element
        else if (sum != 0)
        {
            sum = sum - arr[i - cnt] + arr[i];
        }

        // keep track of max length.
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    // BIT<ll> bt(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
    }
    BIT<ll> bb(n + 1);
    vector<int> di(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> di[i];
    bb.update(1, 1);
    for (int i = 2; i <= n; i++)
    {
        if (di[i - 1] % di[i] != 0)
        {
            bb.update(i, 1);
        }
    }
    int mx = bb.pref(n);
    vector<int> seg[mx + 1];
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ' << bb.pref(i) << endl;
        seg[bb.pref(i)].push_back(v[i]);
    }
    int ans = 0;
    for (int i = 0; i <= mx; i++)
    {
        auto cur = seg[i];
        if (cur.empty())
            continue;
        int curans = atMostSum(cur, cur.size(), k);
        ans = max(ans, curans);
    }
    cout << ans << '\n';
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