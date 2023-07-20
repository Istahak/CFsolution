#include <bits/stdc++.h>
#define ll long long int
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    map<int, ll> cnt;
    for (auto x : v)
        cnt[x]++;
    ll ans = 0;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    n = v.size();
    ll curans = 1LL;
    int i = 0, j = 0;
    int taken = 0;
    while (i < n and j < n)
    {
        while (j < n and v[j] - v[i] + 1 <= m and taken <= m)
        {
            curans = mulmod(curans, cnt[v[j]]);
            j++;
            taken++;
        }
        if (taken == m)
        {
            ans = addmod(ans, curans);
        }
        if (i <= j)
        {
            curans = mulmod(curans, power(cnt[v[i]], mod - 2));
            taken--;
            i++;
        }
        else
        {
            curans = 1;
            taken = 0;
            i++;
        }
    }
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