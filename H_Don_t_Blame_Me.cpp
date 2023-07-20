#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2*1e5 + 10, mod = 1e9 + 7;
int dp[N][64];
int arr[N];
int n, k;
int rec(int i, int val)
{
    if (i == n + 1)
    {
        if (__builtin_popcount(val) == k)
            return 1;
        else
            return 0;
    }

    if (dp[i][val] != -1)
        return dp[i][val];

    return dp[i][val] = (rec(i + 1, val & arr[i]) % mod + rec(i + 1, val) % mod) % mod;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            dp[i][j] = -1;
        }
    }
    ll ans = rec(1, 63);
    if (k == 6)
        ans--;
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