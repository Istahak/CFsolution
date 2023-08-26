#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10, mod = 1e9 + 7;
ll val[3];
ll dp[N][3];
ll n, l, r;
ll f(int i, int m)
{
    if (i == n + 1)
        return m == 0;
    ll &ret = dp[i][m];
    if (~ret)
        return ret;
    ret = 0;
    for (int k = 0; k < 3; k++)
    {
        ret += val[k] * f(i + 1, (m + k) % 3);
        ret %= mod;
    }
    return ret;
}
void solve()
{
    cin >> n >> l >> r;
    val[0] = r / 3 - (l - 1) / 3;
    val[1] = val[0] + (r % 3 > 0) - ((l - 1) % 3 > 0);
    val[2] = val[0] + (r % 3 > 1) - ((l - 1) % 3 > 1);
    memset(dp, -1, sizeof(dp));
    cout << f(1, 0) % mod << endl;
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