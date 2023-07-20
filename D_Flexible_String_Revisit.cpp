#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;
ll inver[N + 1];
long long power(long long a, long long b)
{
    long long x = 1;
    while (b)
    {
        if (b & 1)
            x = x * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return x;
}
void init()
{
    inver[1] = 1;
    for (int i = 2; i < N; i++)
    {
        inver[i] = power(i, mod - 2);
        inver[i] %= mod;
    }
}
ll dp[N];
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            cnt++;
    dp[0] = 0;
    dp[1] = power(2, n) + mod - 1;
    dp[1] %= mod;
    for (int i = 2; i <= n; i++)
    {
        ll ans2 = (i - 1) * dp[i - 2];
        ans2 %= mod;
        ll ans1 = n * dp[i - 1];
        ans1 %= mod;
        ll ans = (ans1 - ans2 - n + mod) % mod;
        ans = (ans * inver[n - i + 1]) % mod;
        dp[i] = ans;
    }
    cout << dp[cnt] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    init();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}