#include <bits/stdc++.h>
#define ll __int128_t
using namespace std;
const int mod = 1e9 + 7;
ll power(ll a, ll b)
{
    ll x = 1;
    while (b)
    {
        if (b & 1)
            x = x * a;
        a = a * a;
        b >>= 1;
    }
    return x;
}

void solve()
{
    long long int n;
    cin >> n;
    for (ll i = 1; i <= 16; i++)
    {
        if (power(i, i) == n)
        {
            int ans = i;
            cout << ans << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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