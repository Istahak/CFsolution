#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    set<ll> v;
    for (ll i = 0, x; i < n; i++)
        cin >> x, v.insert(int(__gcd(x, m)));

    set<ll> divisor;
    for (auto mm : v)
    {
        for (ll i = 1ll; i * i * 1ll <= mm; i++)
        {
            if (mm % i == 0)
            {
                divisor.insert(i);
                divisor.insert(mm / i);
            }
        }
    }
    int ans = 0;
    for (ll i = 1ll; i * i * 1ll <= m; i++)
    {
        if (m % i == 0)
        {
            if (divisor.count(i) == 0)
                ans++;
            if (i == m / i)
                continue;
            if (divisor.count(m / i) == 0)
                ans++;
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
        solve();
    }

    return 0;
}