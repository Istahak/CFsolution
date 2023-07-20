#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[20][2][5];
ll f(string s, int pos, int taken, int cnt)
{
    if (cnt > 3)
        return 0;
    if (s[pos] == '\0')
        return cnt <= 3;
    ll &ret = dp[pos][taken][cnt];
    if (ret != -1)
        return ret;
    int h = 9;
    if (!taken)
        h = s[pos] - '0';
    ret = 0;
    for (int i = 0; i <= h; i++)
    {
        ret += f(s, pos + 1, (i < h or taken), (cnt + (i != 0)));
    }
    return ret;
}
ll ff(ll n)
{
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return f(s, 0, 0, 0);
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << ff(r) - ff(l - 1) << endl;
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