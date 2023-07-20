#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    auto lcm = [](ll x, ll y)
    {
        ll p = x * y * 1LL;
        ll gc = __gcd(x, y);
        return p / gc;
    };
    int ans = 1;
    ll g = a[0], l = b[0], tr = b[0];
    for (int i = 1; i < n; i++)
    {
        l = lcm(l, b[i]);
        ll p = l / b[i], q = l / tr;
        if (a[i] % p != 0 || g % q != 0)
        {
            g = a[i], l = b[i], tr = b[i];
            ans++;
        }
        else
        {
            a[i] /= p;
            g /= q;
            g = __gcd(g, a[i]);
            tr = l;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}
