#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    ll b;
    cin >> n >> b;
    b *= 10000;
    ll f = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll h, r;
        cin >> h >> r;
        ll x = 31416 * h * r * r;
        if (x >= b)
        {
            ll y = x - b;
            if (y < f)
            {
                f = y;
                ans = i + 1;
            }
        }
    }
    if (ans == 0)
    {
        cout << "impossible" << endl;
    }
    else
        cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}