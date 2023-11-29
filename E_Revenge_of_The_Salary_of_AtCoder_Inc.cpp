#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
ll inv[N];
ll dp[N], arr[N], suff[N];
int n;
ll f(int cur)
{
    if (cur > n)
        return 0LL;
    ll &ret = dp[cur];
    if (~ret)
        return ret;
    ret = 0;
    ll nextt = f(cur + 1) % mod;
    ll extra = (((n % mod) * nextt) % mod - suff[cur + 2] + mod) % mod;
    ret = (suff[cur + 1] % mod + nextt % mod + extra % mod) * inv[n];
    ret %= mod;
    return ret;
}
void solve()
{
    inv[1] = 1;
    for (int a = 2; a < N; ++a)
        inv[a] = mod - (long long)(mod / a) * inv[mod % a] % mod;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    suff[n] = arr[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suff[i] = suff[i + 1] + arr[i];
        suff[i] %= mod;
    }
    cout << f(0) % mod << '\n';
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