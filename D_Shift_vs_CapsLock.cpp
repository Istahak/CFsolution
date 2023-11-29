#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 3e5 + 10;
ll x, y, z, dp[N][2];
string s;
ll f(int i, int st)
{
    if (i >= s.size())
        return 0;
    ll &ret = dp[i][st];
    if (~ret)
        return ret;
    ret = LLONG_MAX;
    if (s[i] == 'a')
    {
        if (st == 0)
        {
            ret = min(ret, f(i + 1, st) + x);
            ret = min(ret, f(i + 1, st ^ 1) + z + y);
        }
        else
        {
            ret = min(ret, f(i + 1, st) + y);
            ret = min(ret, f(i + 1, st ^ 1) + z + x);
        }
    }
    else
    {
        if (st == 1)
        {
            ret = min(ret, f(i + 1, st) + x);
            ret = min(ret, f(i + 1, st ^ 1) + z + y);
        }
        else
        {
            ret = min(ret, f(i + 1, st) + y);
            ret = min(ret, f(i + 1, st ^ 1) + x + z);
        }
    }
    return ret;
}
void solve()
{
    cin >> x >> y >> z;
    cin >> s;
    memset(dp, -1, sizeof(dp));

    cout << f(0, 0) << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}