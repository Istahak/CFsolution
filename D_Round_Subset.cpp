#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, k;
vector<pair<int, int>> v;
const int N = 202 * 64;
int dp[202][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    v.resize(n + 1);
    auto pp = [&](ll vv, int d)
    {
        int cnt = 0;
        while (vv % d == 0)
            cnt++, vv /= d;
        return cnt;
    };
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v[i] = {pp(x, 5), pp(x, 2)};
    }
    for (int i = 0; i < 202; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        auto [y, x] = v[i];
        for (int j = k; j >= 1; j--)
        {
            for (int l = x; l < N; l++)
            {
                dp[j][l] = max(dp[j][l], dp[j - 1][l - x] + y);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans = max(ans, min(i, dp[k][i]));
    }
    cout << ans << endl;
    return 0;
}