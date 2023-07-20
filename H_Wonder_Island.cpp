#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
const int M = 1e9 + 7;

int dp[1001][N + 1];
void solve()
{
    for (int i = 1; i <= 1000; i++)
    {
        dp[i][1] = i;
        dp[i][2] = i;
        dp[i][3] = i;
        for (int j = 4; j < N; j++)
        {
            dp[i][j] = dp[i][j - 1] % M + dp[i][j - 3] % M;
            dp[i][j] %= M;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ": ";
        int k, n;
        cin >> k >> n;
        cout << (dp[k][n] << 1) % M << endl;
    }

    return 0;
}