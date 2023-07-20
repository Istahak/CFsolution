#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll M = 998244353;
ll dp[103];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans += dp[i], ans %= M;
    for (int i = 0; i < n; ++i)
    {
        if (i == n - 1)
        {
            if (s[i] >= '7')
                ans += 2;
            else if (s[i] >= '4')
                ans++;
            ans %= M;
            break;
        }
        if (s[i] < '4')
            break;
        if (s[i] > '7')
        {
            ans = (ans + dp[(n - i)]) % M;
            break;
        }
        if (s[i] == '7')
        {
            ans = (ans + dp[(n - i - 1)]) % M;
        }
        else if (s[i] > '4')
        {
            ans = (ans + dp[(n - i - 1)]) % M;
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[0] = 1;
    for (int i = 1; i < 102; i++)
        dp[i] = (dp[i - 1] << 1) % M;
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}