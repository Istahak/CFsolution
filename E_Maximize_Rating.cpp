#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    double n;
    cin >> n;
    vector<double> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0.0;
    for (int i = 1; i <= n; i++)
    {

        dp[i][1] = v[i] - 1200;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            double pre = dp[i - 1][j - 1];
            double cur = pre + (1200) / sqrt(j - 1);
            double dd = 10.0 * (1 - pow(0.9, j - 1));
            double d = 10.0 * (1 - pow(0.9, j));
            dd += pow(0.9, j - 1) * v[i];
            dd /= d;
            dd = dd - 1200 / sqrt(j);
            dp[i][j] = dd;
            
        }
    }
    double ans = dp[n][1];
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    cout << fixed << setprecision(12) << ans << '\n';
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