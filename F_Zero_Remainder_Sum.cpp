#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
const int N = 71;
int grid[N][N];
int dp[N][N][N][N];
int n, m, k;
int f(int row, int col, int ccnt, int d)
{
    if (row >= n)
    {
        if (d == 0)
            return d;
        else
            return -1e9;
    }
    int &ret = dp[row][col][ccnt][d];
    if (~ret)
        return ret;
    if (ccnt >= m / 2 or col >= m)
    {
        ret = f(row + 1, 0, 0, d);
    }
    else
    {
        ret = max(f(row, col + 1, ccnt, d), f(row, col + 1, ccnt + 1, (d + grid[row][col]) % k) + grid[row][col]);
    }
    return ret;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, 0, 0) << '\n';
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