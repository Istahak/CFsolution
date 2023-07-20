#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    ll g = __gcd(a, b);
    a /= g, b /= g;
    ll l = 1, r = max(n, m);
    ll ans = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        bool ok = (a * mid <= n) and (b * mid <= m);
        if (ok)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    ll la = a * ans;
    ll lb = b * ans;
    ll x1 = 2 * x - la;
    ll x2 = 2 * x + la;
    ll y1 = 2 * y - lb;
    ll y2 = 2 * y + lb;
    if (x1 < 0)
    {
        ll rightshift = abs(x1);
        x1 += rightshift;
        x2 += rightshift;
    }
    if (x2 > 2 * n)
    {
        ll lefshift = x2 - 2 * n;
        x1 -= lefshift;
        x2 -= lefshift;
    }
    if (y1 < 0)
    {
        ll upshift = abs(y1);
        y1 += upshift;
        y2 += upshift;
    }
    if (y2 > 2 * m)
    {
        ll downshift = y2 - 2 * m;
        y1 -= downshift;
        y2 -= downshift;
    }
    cout << x1 / 2 << ' ' << y1 / 2 << ' ' << x2 / 2 << ' ' << y2 / 2 << endl;
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