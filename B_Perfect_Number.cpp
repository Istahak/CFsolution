#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[20][2][50];
int cs = 0;
ll f(string s, int pos, int taken, int sum, int sz)
{
    if (sum >= 11)
        return 0;
    if (pos == sz)
        return sum == 10;
    ll &ret = dp[pos][taken][sum];
    if (ret != -1)
        return ret;
    int l = 9;
    if (taken == 0)
        l = s[pos] - '0';
    ret = 0;
    for (int i = 0; i <= l; i++)
    {
        ret += f(s, pos + 1, (i < l or taken), sum + i, sz);
    }
    return ret;
}
void solve()
{

    int k;
    cin >> k;
    ll ans = -1;
    ll l = 1, r = 1e9;
    auto ispossible = [&](ll mid)
    {
        memset(dp, -1, sizeof(dp));
        string s = to_string(mid);
        int n = s.size();
        ll pos = f(s, 0, 0, 0, n);

        return pos >= k;
    };
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (ispossible(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
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