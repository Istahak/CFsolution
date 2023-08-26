#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 998244353;
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
long long addmod(long long a, long long b)
{
    long long ans = (a % mod + b % mod) % mod;
    return ans;
}
long long submod(long long a, long long b)
{
    long long ans = (a % mod - b % mod + mod) % mod;
    return ans;
}
long long mulmod(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
void solve()
{
    long long n, a, b;
    cin >> n >> a >> b;
    long long int x = mulmod(a, power(b, mod - 2)), y = mulmod((b - a), power(a, mod - 2));
    vector<long long int> xx(n + 5), yy(n + 5);
    xx[0] = 1;
    for (int i = 1; i <= n + 1; i++)
        xx[i] = mulmod(x, xx[i - 1]);
    yy[0] = 1;
    for (int i = 1; i <= n + 1; i++)
        yy[i] = mulmod(y, yy[i - 1]);
    for (int i = 1; i <= n + 1; i++)
        yy[i] = addmod(yy[i], yy[i - 1]);
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = mulmod(ans, mulmod(xx[i], yy[i]));
    }
    cout << ans << endl;
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