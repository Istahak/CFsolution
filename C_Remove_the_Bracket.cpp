#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
int ax[N], ay[N];
ll dp[N][2];
int v[N];
ll n, s;

ll rec(int i, int f)
{
    if (i == n - 1)
        return min(v[n - 1] * ay[n - 2], v[n - 1] * ax[n - 2]);
    if (dp[i][f] != -1)
        return dp[i][f];
    if (f == 0)
    {
        dp[i][f] = min(rec(i + 1,1))
    }
    else{

    }
}
void solve()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // ll dp[n][2];
    ll ax[n], ay[n];
    for (int i = 1; i < n - 1; i++)
    {
        int x = s;
        int y = v[i] - s;
        if (y < 0)
        {
            ax[i] = v[i];
            ay[i] = 0;
        }
        else
        {
            ax[i] = x;
            ay[i] = y;
        }
    }

    memset(dp, -1, sizeof(dp));
    // dp[1][0] = v[0] * ax[1];
    // dp[1][1] = v[0] * ay[1];
    // for (int i = 1; i < n - 1; i++)
    // {
    //     dp[i][0] = min(dp[i - 1][0] + ax[i] * ay[i - 1], dp[i - 1][1] + ax[i - 1] * ay[i]);
    //     dp[i][1] = min(dp[i - 1][0] + ay[i] * ax[i - 1], dp[i - 1][1] + ax[i] * ay[i - 1]);
    // }

    cout << min(dp[n - 2][0] + ay[n - 2] * v[n - 1], dp[n - 2][1] + ax[n - 2] * v[n - 1]) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}