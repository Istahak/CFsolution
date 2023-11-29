#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
const double pi = acos(-1);
void solve()
{
    ll a, b, m, n, th;
    cin >> a >> b >> m >> n >> th;
    long double A = a, B = b, M = m, N = n, Th = th;
    long double rad = (pi * Th) / 180.0;
    long double h = A * cos(rad) + B * sin(rad);
    long double w = A * sin(rad) + B * cos(rad);
    ll H = ceil(h);
    ll W = ceil(w);
    ll l = 1, r = 1e10;
    ll ansx = 1, ansy = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll curm = m * mid, curn = n * mid;
        if (curm >= H and curn >= W)
        {
            ansx = curm, ansy = curn;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ansx << ' ' << ansy << '\n';
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