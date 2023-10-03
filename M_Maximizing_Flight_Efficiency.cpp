#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int cost[n][n], dp[n][n], dp2[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            dp[i][j] = cost[i][j];
            dp2[i][j] = cost[i][j];
            if (i == j){
                dp[i][j] = 0;
                dp2[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (dp[i][j] < cost[i][j])
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==j || k==i || k==j) continue;
                if (dp[i][j] == dp[i][k] + dp[k][j])
                {
                    ans++;
                    dp[i][j] = 1e9;
                }
            }
        }
    }
    cout << (ans>>1) << endl;
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