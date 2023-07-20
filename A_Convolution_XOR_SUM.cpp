#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int M = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(29, 0), b(29, 0);
    ll ans1 = 1;
    for (ll i = 2; i < n; ++i)
    {
        ans1 *= i;
        ans1 %= M;
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (int i = 0; i < 29; i++)
        {
            a[i] += (x & 1);
            x >>= 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (int i = 0; i < 29; i++)
        {
            b[i] += (x & 1);
            x >>= 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 29; i++)
    {
        ll xx = (1 << i) % M;
        ans += (xx * a[i] * (n - b[i])) % M;
        ans %= M;
        ans += (xx * b[i] * (n - a[i])) % M;
        ans %= M;
    }
    cout << (ans * ans1) % M << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}