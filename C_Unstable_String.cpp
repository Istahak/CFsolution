#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll dp[n + 2][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i - 1;
        if (s[x] == '1')
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = 0;
        }
        else if (s[x] == '0')
        {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = 0;
        }
        else
        {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1] + 1;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += max(dp[i][0], dp[i][1]);
    }
    cout << ans << endl;
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