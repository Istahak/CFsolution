#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = s[i] - '0';
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][v[0]]++;
    for (int i = 1; i < n; i++)
    {
        dp[i][v[i]]++;
        for (int j = 0; j < 2; j++)
        {
            dp[i][(j & v[i]) ^ 1] += dp[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
        ans += dp[i][1];
    cout << ans << '\n';
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