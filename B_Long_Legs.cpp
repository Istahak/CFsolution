#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll sz = sqrtl(x + y) + 1;
    ll ans = LLONG_MAX;
    for (ll k = 1; k <= sz; k++)
    {
        ll curans = k - 1;
        curans += (x + k - 1) / k;
        curans += (y + k - 1) / k;
        ans = min(ans, curans);
    }
    cout << ans << endl;
}
int main()
{

    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }

    return 0;
}