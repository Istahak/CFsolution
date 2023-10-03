#include <bits/stdc++.h>
#define int long long int
using namespace std;
void solve()
{
    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    auto ispos = [&](int m)
    {
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += max(0LL, m - v[i]);
        }

        return total <= u;
    };
    int l = 0, r = 4*1e9;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ispos(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans << '\n';
}
int32_t main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        solve();
    }

    return 0;
}