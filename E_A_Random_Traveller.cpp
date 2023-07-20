#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int64_t x;
        cin >> x;
        sum += x;
        v[i] = power(i, mod - 2);
    }
    sum *= v[n];
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (n * v[n - i + 1]) % mod + dp[i - 1] ;
        dp[i] %= mod;
    }
    sum %= mod;
    long long ans = dp[n] * sum;
    ans %= mod;
    cout << ans << endl;
    return 0;
}