#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, k;
int dp[N];
int f(int cur)
{
    if (cur < 0)
        return 0;
    if (cur == 0)
        return 1;
    if (dp[cur] != -1)
        return dp[cur];
    int ans = 0;
    ans = f(cur - 1) + f(cur - k);
    ans %= mod;
    return dp[cur] = ans;
}
void solve()
{
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    f(N - 1);
    dp[0] = 0;
    for (int i = 1; i < N; i++)
        dp[i] += dp[i - 1], dp[i] %= mod;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        cout << (dp[r] - dp[l - 1] + mod) % mod << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //  cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}