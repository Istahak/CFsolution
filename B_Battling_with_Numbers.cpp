#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e6 + 10;
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
    int n;
    cin >> n;
    vector<int> v(N, 0);
    vector<int> bx(n);
    vector<int> px(n);
    for (auto &x : bx)
        cin >> x;
    for (auto &x : px)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        v[bx[i]] = px[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    vector<int> p(m);
    for (auto &x : b)
        cin >> x;
    for (auto &x : p)
        cin >> x;
    for (int i = 0; i < m; i++)
    {
        v[b[i]] -= p[i];
    }
    ll ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (v[i] < 0)
        {
            cout << 0 << endl;
            return;
        }
        else if (v[i] > 0)
        {
            ans = mulmod(ans, 2);
        }
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