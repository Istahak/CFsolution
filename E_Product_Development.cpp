#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[102][7][7][7][7][7];
int n, m, p;
int val[102][7];
ll f(int id, int i1, int i2, int i3, int i4, int i5)
{
    if (id >= n)
    {
        if (m == 1)
        {

            return i1 >= p ? 0LL : 1e14;
        }
        else if (m == 2)
        {
            int mi = min(i1, i2);
            return mi >= p ? 0LL : 1e14;
        }
        else if (m == 3)
        {

            int mi = min({i1, i2, i3});
            // cout << mi << '\n';
            return mi >= p ? 0LL : 1e14;
        }
        else if (m == 4)
        {

            int mi = min({i1, i2, i3, i4});
            return mi >= p ? 0LL : 1e14;
        }
        else
        {

            int mi = min({i1, i2, i3, i4, i5});
            return mi >= p ? 0LL : 1e14;
        }
    }
    ll &ret = dp[id][i1][i2][i3][i4][i5];
    if (~ret)
        return ret;

    ret = f(id + 1, i1, i2, i3, i4, i5);
    ret = min(ret, f(id + 1, min(i1 + val[id][1], 5), min(i2 + val[id][2], 5), min(i3 + val[id][3], 5), min(i4 + val[id][4], 5), min(i5 + val[id][5], 5)) + val[id][0]);
    return ret;
}
void solve()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> val[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << val[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    memset(dp, -1, sizeof(dp));
    ll ans = f(0, 0, 0, 0, 0, 0);
    cout << (ans == 1e14 ? -1 : ans) << '\n';
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